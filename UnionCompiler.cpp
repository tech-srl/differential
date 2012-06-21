#include "UnionCompiler.h"
#include "Transform/GuardConsumer.h"
#include "Transform/TagConsumer.h"
#include "Transform/InlineConsumer.h"
#include "Transform/UnionConsumer.h"
using namespace differential;

#include "DTL/dtl.hpp"
#include "DTL/variables.hpp"
using namespace dtl;

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define DEBUGOutputUnion 0

extern llvm::cl::opt<std::string>  InputFilename;
extern llvm::cl::list<std::string> PatchedFilename;
extern llvm::cl::list<std::string> GuardFilename;
extern llvm::cl::list<std::string> GuardTaggedFilename;
extern llvm::cl::list<std::string> TagFilename;
extern llvm::cl::list<std::string> InlineFilename;
extern llvm::cl::list<std::string> RetGuard;
extern llvm::cl::list<std::string> X0;
extern llvm::cl::list<std::string> Clear;
extern llvm::cl::list<std::string> DiffPoints;
extern llvm::cl::list<std::string> TagEquality;
extern llvm::cl::list<std::string> AddAsserts;

namespace differential {

    int UnionCompiler::Main(int argc, char* argv[]) {
        CodeHandler::Init(argc,argv);

        if ( GuardFilename.size() > 0 ) {
            InputFilename = GuardFilename[0];
			UnionCompiler().AddDefinitions();
            UnionCompiler().GuardedInstructionsTransform(); 
        } else if ( GuardTaggedFilename.size() > 0 ) {
            InputFilename = GuardTaggedFilename[0];
			UnionCompiler().AddDefinitions();
            UnionCompiler().GuardedInstructionsTransform(); 
        } else if ( TagFilename.size() > 0 ) {
            InputFilename = TagFilename[0];
            UnionCompiler().TagInstructionsTransform();
        } else if ( InlineFilename.size() > 0 ) {
            InputFilename = InlineFilename[0];
            UnionCompiler().InlineTransform();
        } else if ( PatchedFilename.size() > 0 ) {
            // This handles 2 files
            UnionCompiler().UnionTransform();
        }

        return 0;
    }

    UnionCompiler::UnionCompiler() : CodeHandler(), rewriter_(source_manager_,language_options_) {
        // This is stupid, but it's the only way to really attach the Rewriter to the file
        string str;
        llvm::raw_string_ostream os(str);
        rewriter_.getEditBuffer(source_manager_.getMainFileID()).write(os);
    } 
	
	void UnionCompiler::AddDefinitions() {
		rewriter_.InsertText(source_manager_.getLocForStartOfFile(source_manager_.getMainFileID()), Defines::kGeneralTypedefs);
		InputFilename = Defines::kGuardedFilenamePrefix + InputFilename;
		Utils::WriteFiles(rewriter_,InputFilename);
	}

    void UnionCompiler::GuardedInstructionsTransform() {
        GuardedInstructionsASTConsumer consumer(rewriter_, (RetGuard.size() > 0 && RetGuard[0] == "true"), (X0.size() > 0 && X0[0] == "true"));
		
        Transform(consumer); 
    }

    void UnionCompiler::UnionTransform(ostream& report_file) {
        // Create TranslationUnit for the input program 
        string filename = InputFilename;
        UnionerASTConsumer consumer(rewriter_);
        Transform(consumer);

        // Create TranslationUnit for the patched program (we need another differential for that)
        InputFilename = PatchedFilename[0];
        UnionCompiler ucc2; // for the patched version
        UnionerASTConsumer consumer2(ucc2.rewriter_);
        ucc2.Transform(consumer2);

        // Traverse the translation units and union matched functions
        unsigned added_ctr = 0, deleted_ctr = 0, diff_point_ctr = 0;
        set<string> added_decls;
        for ( DeclContext::decl_iterator iter = consumer.unit_ptr_->decls_begin(), end = consumer.unit_ptr_->decls_end(); iter != end; ++iter ) {
            for ( DeclContext::decl_iterator iter2 = consumer2.unit_ptr_->decls_begin(), end2 = consumer2.unit_ptr_->decls_end(); iter2 != end2; ++iter2 ) {

                // Handling globals:
                VarDecl * var_decl_ptr = dyn_cast<VarDecl>(*iter), *var_decl_ptr2 = dyn_cast<VarDecl>(*iter2);
                if ( var_decl_ptr && var_decl_ptr2 && 
                     !var_decl_ptr->isExternC() && !var_decl_ptr2->isExternC() && 
                     var_decl_ptr2->getNameAsString().find(Defines::kTagPrefix) == 0 ) {
                    // Insert tagged globals alongside their original counterparts
                    if ( var_decl_ptr->getNameAsString() == Utils::ReplaceAll(var_decl_ptr2->getNameAsString(), Defines::kTagPrefix, "") ) {
                        string declaration2;
                        {// Get the patched global decleration string
                            SourceLocation start_loc2 = Utils::getIdentifierStartLoc(var_decl_ptr2,ucc2.rewriter_);
                            bool invalid;
                            llvm::StringRef code2 = FullSourceLoc(var_decl_ptr2->getLocStart(), ucc2.rewriter_.getSourceMgr()).getBufferData(&invalid);
                            unsigned start_i = start_loc2.getRawEncoding() - 2;
                            unsigned end_i = code2.find(";",start_i) + 1;
                            declaration2 = code2.slice(start_i,end_i);
                        }
                        if ( added_decls.count(declaration2) == 0 ) { // making sure declerations that appear on the same line won't appear twice
                            added_decls.insert(declaration2);
                            SourceLocation end_loc;
                            {// Find the end location of the declaration
                                bool invalid;
                                llvm::StringRef code = FullSourceLoc(var_decl_ptr->getLocStart(), rewriter_.getSourceMgr()).getBufferData(&invalid);
                                unsigned start_i = var_decl_ptr->getLocStart().getRawEncoding();
                                unsigned end_i = code.find(";",start_i) + 1;
                                end_loc = SourceLocation::getFromRawEncoding(end_i + 2);
                            }
                            rewriter_.InsertText(end_loc,declaration2);
                        }
                    }
                }

                // Handle functions:
                FunctionDecl *FD = dyn_cast<FunctionDecl>(*iter), *PFD = dyn_cast<FunctionDecl>(*iter2);
                if ( FD && PFD && FD->isThisDeclarationADefinition() && PFD->isThisDeclarationADefinition() && 
                     FD->getNameAsString() == PFD->getNameAsString() ) {
                    StringRef PatchedStr;
                    unsigned Length;
                    {
                        SourceLocation SLoc = PFD->getBody()->getLocStart(), ELoc = PFD->getBodyRBrace().getLocWithOffset(1);
                        FullSourceLoc FSLoc(SLoc, ucc2.rewriter_.getSourceMgr());
                        bool Invalid;
                        llvm::StringRef CodeString = FSLoc.getBufferData(&Invalid);
                        assert(!Invalid && "Invalid buffer data for patched file");
                        PatchedStr = CodeString.slice(SLoc.getRawEncoding(),ELoc.getRawEncoding());
                    }

                    StringRef FileStr;
                    {
                        SourceLocation SLoc = FD->getBody()->getLocStart(), ELoc = FD->getBodyRBrace().getLocWithOffset(1);
                        FullSourceLoc FSLoc(SLoc, rewriter_.getSourceMgr());
                        bool Invalid;
                        llvm::StringRef CodeString = FSLoc.getBufferData(&Invalid);
                        assert(!Invalid && "Invalid buffer data for input file");
                        FileStr = CodeString.slice(SLoc.getRawEncoding(),ELoc.getRawEncoding());
                        Length = ELoc.getRawEncoding() - SLoc.getRawEncoding();
                    }
                    rewriter_.ReplaceText(FD->getBody()->getLocStart(),Length,OutputUnion(FileStr,PatchedStr,diff_point_ctr, added_ctr, deleted_ctr, (Clear.size() > 0 && Clear[0] == "true")));
                }
            }
        }

        report_file << setw(6) << added_ctr << " | " << setw(8) << deleted_ctr << " | " << setw(12) << diff_point_ctr << " | ";

        // add the assert header since we might have asserts in our union program
        rewriter_.InsertText(source_manager_.getLocForStartOfFile(source_manager_.getMainFileID()),"#include <assert.h>\n");

        // Create an output file for the union program
        int index = filename.find(".",filename.find(".")); // We want the second "." (filename is of form patched.guarded.filename)
        filename = filename.replace(0,index+1,Defines::kUnionedFilenamePrefix);
        // Output the unioned program
        Utils::WriteFiles(rewriter_,filename);

    }

    string UnionCompiler::OutputUnion(string file, string patched_file, unsigned &diff_point_ctr, unsigned &added_ctr, unsigned &deleted_ctr, bool clear) {
#if (DEBUGOutputUnion)
        string file0 = file, patched_file0 = patched_file;
#endif
        file = file.insert(0,"{\n");
        patched_file = patched_file.insert(0,"{\n");
        stringstream out;

        // Start comparing, remember to ignore the tag prefix and guards
        string line, patched_line;
        vector<string> lines, lines2, patched_lines, patched_lines2;
        bool difference = false;

        for ( size_t loc = 0; loc != file.npos; ) {
            loc = file.find('\n');
            line = file.substr(0, loc + 1);
            file = file.substr(loc + 1);
            if ( Utils::Trim(line) == "" ) // ignore whitespace lines
                continue;
            lines.push_back(line);
            lines2.push_back(line);
        }

        for ( size_t patched_loc = 0 ;patched_loc != patched_file.npos; ) {
            patched_loc = patched_file.find('\n');
            patched_line = patched_file.substr(0, patched_loc + 1);
            patched_file = patched_file.substr(patched_loc + 1);
            if ( Utils::Trim(patched_line) == "" ) // ignore whitespace lines
                continue;
            patched_lines.push_back(patched_line);
            //// Get an untagged version of the patched line for diffing
            patched_lines2.push_back(Utils::ReplaceAll(patched_line, Defines::kTagPrefix, ""));
        }

#if (DEBUGOutputUnion)
		cerr << "Lines size: " << lines.size() << " , " << " Patched lines size: " << patched_lines.size() << endl;
#endif

        Diff< string, vector<string> > diff(lines2, patched_lines2);
        diff.compose();
        vector<pair<string, elemInfo> > seq = diff.getSes().getSequence();
        unsigned line_num = 0, patched_line_num = 0;
		bool added = false, deleted = false;
		bool add_diff_points = DiffPoints.size() > 0 && DiffPoints[0] == "true";
        for ( size_t loc = 0 ; loc < seq.size() ; ++loc ) {
#if (DEBUGOutputUnion)
			cerr << "Line index: " << line_num << " , " << " Patched line index: " << patched_line_num << ", Line: " << seq[loc].second.type << " , " << seq[loc].first << endl;
#endif
            string line, patched_line, current = seq[loc].first;
            switch ( seq[loc].second.type ) {
            case SES_ADD:
				patched_line = patched_lines[patched_line_num];
                if (patched_line.find(Defines::kAssertPrefix) == 0) {
                    // remove the comment before the assert
                    patched_line = patched_line.substr(2);
                    out << patched_line;
                    patched_line_num++;
                    break;
                }
                out << patched_line;
                // Addition of tag variables or '}' or '{' doesn't count as a true diff
                if ( add_diff_points &&
                     current.find(Defines::kTagParamDef) == current.npos &&
                     current.find("{") == current.npos &&
                     current.find("}") == current.npos ) {
#if (DEBUGOutputUnion)
                    cerr << "Add: " << current;
#endif
                    difference = true;
					added = true; // Add a diff point after all additions are complete
                    added_ctr++;
                    
                    //out << "{char *" << Defines::kDiffPointPrefix << "Added" << diff_point_ctr++ << ";}\n";
                }
                patched_line_num++;
                break;
            case SES_DELETE:
				line = lines[line_num];
                out << line;
                if ( add_diff_points &&
                     current.find(Defines::kDiffPointPrefix) == current.npos &&
                     current.find("{") == current.npos &&
                     current.find("}") == current.npos ) {
#if (DEBUGOutputUnion)
                    cerr << "Delete: " << current;
#endif
                    difference = true;
					deleted = true; // Add a diff point after all removals are complete
                    deleted_ctr++;
                    // Add a diff point after each removal
                    //out << "{char *" << Defines::kDiffPointPrefix << "Deleted" << diff_point_ctr++ << ";}\n";
                }
                line_num++;
                break;
            case SES_COMMON:
				line = lines[line_num];
				patched_line = patched_lines[patched_line_num];
				if (added || deleted) { // if lines were added or removed prior to this common line, add a diff point
					out << "{char *" << Defines::kDiffPointPrefix << diff_point_ctr++ << ";}\n";
					added = deleted = false;
				}
                out << line;
                if (patched_line.find(Defines::kTagParamDef) != patched_line.npos &&
                    patched_line.find(Defines::kRetVal) != patched_line.npos) { // make T_RetVal = RetVal
                    stringstream ss;
                    ss << " = " << Defines::kRetVal;
                    out << patched_line.insert(patched_line.size() - 2,ss.str());
                } else if (seq[loc].first.find("enum") != 0) { // print out the patched line only if its not an enum
                    out << patched_line;
                }
                // Add a diff point after 2 identical lines only if it's a "real" line 
                // and only if a syntaxtical diff was previously found
                if ( add_diff_points &&
                     current.find(Defines::kLabelPrefix) > 0 && // ignore Label: ...
                     current.find(Defines::kGuardType) == current.npos &&
                     current.find("{") == current.npos &&
                     current.find("}") == current.npos &&
                     difference ) {
                    out << "{char *" << Defines::kDiffPointPrefix << diff_point_ctr++ << ";}\n";
                }
                line_num++;
                patched_line_num++;
                break;
            }
        }

#if (DEBUGOutputUnion)
        diff.printSES();
#endif

        if ( !difference && clear ) // No difference and the clear flag was not raised - clear function body.
            return "{ }";

        return out.str();
    }

    void UnionCompiler::TagInstructionsTransform() {
        TagInstructionsASTConsumer consumer(rewriter_, (TagEquality.size() > 0 && TagEquality[0] == "true"), (AddAsserts.size() > 0 && AddAsserts[0] == "true"));
        Transform(consumer);
    }

    void UnionCompiler::Transform(ASTConsumer  &consumer) {
        IdentifierTable id_table(language_options_);
        SelectorTable selector_table;
        Builtin::Context builtin_contex;
        contex_ptr_ = new ASTContext(language_options_, source_manager_, target_info_, id_table, selector_table, builtin_contex, 0);
        consumer.Initialize(*contex_ptr_);
        clang::ParseAST(*preprocessor_ptr_, &consumer, *contex_ptr_);
    }

    void UnionCompiler::InlineTransform() {
        InlinerASTConsumer consumer(rewriter_);
        Transform(consumer);
    }

}
