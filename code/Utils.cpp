#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceManager.h>
#include <llvm/Support/raw_ostream.h>
#include "Utils.h"
#include "Defines.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace differential {


/**
 * extract all function declarations from the translation units and populate them into a 'function_name' -> 'function_decl_ptr' map given as argument
 */
void Utils::CreateFunctionsMap(TranslationUnitDecl * tran_unit_ptr,map<string,const FunctionDecl *> &functions) {
	for (DeclContext::decl_iterator iter = tran_unit_ptr->decls_begin(), end = tran_unit_ptr->decls_end(); iter != end; ++iter) {
		// Only handle declarations with bodies
		if (const FunctionDecl *fd = dyn_cast<FunctionDecl>(*iter)) {
			if (!fd->isThisDeclarationADefinition())
				continue;
			functions[fd->getNameAsString()] = fd;
		}
	}
}

size_t Utils::GetStmtLength(Stmt * node) {
	return node->getSourceRange().getEnd().getRawEncoding() - node->getSourceRange().getBegin().getRawEncoding() + 2; // +2 correcting for clang
}

size_t Utils::GetDeclLength(Decl * node) {
	return node->getSourceRange().getEnd().getRawEncoding() - node->getSourceRange().getBegin().getRawEncoding() + 2; // +2 correcting for clang
}

/**
 *
 *
 * @author nimrod (3/4/2012)
 *
 * @param name - (input) variable name, (output) untagged name
 * @param tagged_name - (output) tagged name
 */
void Utils::Names(string &name, string &tagged_name){
	tagged_name = name;
	if (name.find(Defines::kTagPrefix) == 0) {
		name = name.substr(Defines::kTagPrefix.size());
	} else {
		tagged_name = Defines::kTagPrefix + name;
	}
}

string Utils::PrintStmt(Stmt * node, ASTContext &contex) {
	string str;
	raw_string_ostream os(str);
	if (node) {
		node->printPretty(os, contex, 0, PrintingPolicy(contex.getLangOptions()));
	}
	return os.str();
}

string Utils::PrintDecl(Decl * node, ASTContext &contex) {
	string str;
	raw_string_ostream os(str);
	if (node) {
		node->print(os, PrintingPolicy(contex.getLangOptions()));
	}
	return os.str();
}


string Utils::ReplaceAll(const StringRef& source, const StringRef& token, const StringRef& replacement) {
	//string Utils::ReplaceAll(const string& source, const string& tokens, const string& replacement) {
	stringstream ss;
	size_t start = 0, end;
	while ((end = source.find(token,start)) != source.npos) {
		ss << source.slice(start,end).str() << replacement.str();
		start = end + token.size();
	}
	// Append the remainder
	ss << source.slice(start,source.size()).str();
	return ss.str();

	//boost::regex expr( tokens ) ;
	//return boost::regex_replace(source, expr, replacement, boost::match_default | boost::format_sed ) ;
}

vector<string> Utils::Split(const string& source, const string& tokens){
	vector<string> result;
	//boost::split(result, source, boost::is_any_of(tokens));
	return result;
}

string Utils::RemoveGuards(string source) {
	stringstream ss;
	size_t start = 0, end;
	while (true) {
		start = source.find(Defines::kGuardPrefix,start);
		ss << source.substr(0,start);
		if (start == source.npos)
			break;
		end = min(source.find(")",start),source.find(" ",start));
		source = source.substr(end);
	}
	return ss.str();
}

string Utils::ConditionToGuard(const string condition){
	unsigned char result[16];
	stringstream ss;
	/*
	   MD5((const unsigned char *)(condition.c_str()), condition.size(), result);
	   for (int i = 0 ; i < 16 ; i++)
		   ss << '_' << (int)result[i];
	   return ss.str();
	 */
	unsigned long long hash = 0;
	for (size_t i = 0 ; i < condition.size() ; i++) {
		hash += i * condition[i];
		/*
           if (isalnum(condition[i])) {
               ss << condition[i];
               continue;
           }
           switch (condition[i]) {
               case '<': ss << "Lower"; break;
               case '>': ss << "Greater"; break;
               case '=': ss << "Eq"; break;
               case '&': ss << "And"; break;
               case '|': ss << "Or"; break;
               case '*': ss << "Star"; break;
               case '%': ss << "Mpd"; break;
               case '+': ss << "Plus"; break;
               case '-': ss << "Min"; break;
               case '/': ss << "Div"; break;
               case '(': ss << "RParen"; break;
               case ')': ss << "LParen"; break;
               case '!': ss << "Not"; break;
               case '\'': ss << "Tag"; break;
               case '[': ss << "LSqBracket"; break;
               case ']': ss << "RSqBracket"; break;
               case '"': ss << "Quote"; break;
               case '{': ss << "LCurBracket"; break;
               case '}': ss << "RCurBracket"; break;
               case '\\': ss << "BSlash"; break;
               default: ss << "_"; break;
           } 
		 */
	}
	ss << hash;
	return ss.str();
}


void Utils::WriteFiles(Rewriter& rw, string filename)
{
	for (Rewriter::buffer_iterator I = rw.buffer_begin(), E = rw.buffer_end();I != E;++I) {
		if (I->first.isInvalid()) continue;
		const FileEntry *Entry = rw.getSourceMgr().getFileEntryForID(I->first);
		if (filename == "")
			filename = Entry->getName();
		string error;
		raw_fd_ostream OS(filename.c_str(), error, raw_fd_ostream::F_Binary);
		if (!error.empty()) {
			cerr << "Unable to open " << filename << error;
			continue;
		}
		RewriteBuffer & RewriteBuf = I->second;
		RewriteBuf.write(OS);
		OS.close();
	}
}

void Utils::Init(ConfigFile& CF)
{
	int seed;
	CF.readInto( seed, "seed" );
	srand(seed);
}

unsigned int Utils::Rand()
{
	return rand();
}

bool Utils::isWhitespace(char Candidate)
{
	return(Candidate == ' ' || Candidate == '\t' || Candidate == '\n' || Candidate == '\r');
}

/**
 * Get the true start location of a identifier, including 
 * Storage Class, Qualifiers, etc. 
 */
SourceLocation Utils::getIdentifierStartLoc(VarDecl *node, Rewriter& rw)
{
	SourceLocation loc = node->getTypeSpecStartLoc();
	if (loc.getRawEncoding() < 3) { // We are at the start of the file
		return loc;
	}
	loc = loc.getLocWithOffset(-1);
	bool invalid;
	StringRef code = FullSourceLoc(loc, rw.getSourceMgr()).getBufferData(&invalid);
	unsigned raw_loc = loc.getRawEncoding() - 1, raw_end;
	if (raw_loc > code.size())
		return loc.getLocWithOffset(1);
	bool end;
	do {
		end = true;
		raw_end = raw_loc--;
		// ignore white-spaces
		while (Utils::isWhitespace(code[raw_loc]))
			raw_loc--;

		// Now go back a sufficient amount of lines and check for qualifiers
		{
			// enum
			raw_loc -= 3;
			StringRef s(code.data() + raw_loc);
			if (s.startswith("enum")) {
				end = false;
				continue;
			}
		}
		{
			// const
			raw_loc -= 1;
			StringRef s(code.data() + raw_loc);
			if (s.startswith("const")) {
				end = false;
				continue;
			}
		}
		{
			// static or struct or extern
			raw_loc -= 1;
			StringRef s(code.data() + raw_loc);
			if (s.startswith("static") || s.startswith("struct") || s.startswith("extern")) {
				end = false;
				continue;
			}
		}
		{
			// volatile
			raw_loc -= 2;
			StringRef s(code.data() + raw_loc);
			if (s.startswith("volatile")) {
				end = false;
				continue;
			}
		}
	} while (!end);
	raw_end++;
	return SourceLocation::getFromRawEncoding(raw_end);
}


/**
 * Get the true end location of an identifier, including array brackets.
 */
SourceLocation Utils::getIdentifierEndLoc(VarDecl * node, Rewriter &rewriter)
{
	SourceLocation loc = node->getLocEnd();
	bool invalid;
	StringRef code = FullSourceLoc(loc, rewriter.getSourceMgr()).getBufferData(&invalid);
	if (invalid)
		return loc;
	unsigned raw_loc = loc.getRawEncoding();
	if (raw_loc > code.size())
		return loc;
	while (code[raw_loc - 2] != ';' && code[raw_loc - 2] != ',') // correcting +2 for clang
		raw_loc++;
	return SourceLocation::getFromRawEncoding(raw_loc);
}

/**
 * Get the start location of an identifier's name.
 */
SourceLocation Utils::getIdentifierNameLoc(VarDecl * node, Rewriter& rw)
{
	SourceLocation loc = node->getLocStart();
	string name = node->getNameAsString(), type = node->getType().getAsString();
	FullSourceLoc fl(loc, rw.getSourceMgr());
	bool invalid;
	string code = fl.getBufferData(&invalid).str();
	code = code.substr(loc.getRawEncoding());
	size_t offset = code.rfind(name,min(code.find(";"),code.find("="))); // look for the name backwards from ; or =
	return loc.getLocWithOffset(offset + 2); // +2 correcting for clang
}

/**
 * Get the first semicolon preceeding the given statement. This 
 * is the first locaion where you can add new code. 
 */
SourceLocation Utils::getNextEligibleCodeLoc(Stmt *node, Rewriter &rw)
{
	SourceLocation loc = node->getLocStart();
	bool invalid;
	StringRef code = FullSourceLoc(loc, rw.getSourceMgr()).getBufferData(&invalid);
	if (invalid)
		return loc;
	unsigned raw_loc = loc.getRawEncoding() - 2;
	while (raw_loc < code.size() && code[raw_loc] != ';' && code[raw_loc] != '}' && code[raw_loc] != '{')
		raw_loc++;
	return SourceLocation::getFromRawEncoding(raw_loc + 1 + 2); // +1 get place right after, +2 correcting for clang
}

/**
 * Check is the block has a back-edge, if so return the edge ID, else return -1;
 */
int Utils::hasBackEdge(const CFGBlock* block) {
	// a block has a back edge if its predecessor id is greater than its own
	for ( CFGBlock::const_pred_iterator iter = block->pred_begin(), end = block->pred_end(); iter != end; ++iter ) {
		CFGBlock *prev_block = *iter;
		if ( prev_block && prev_block->getBlockID() < block->getBlockID() ) {
			return prev_block->getBlockID();
		}
	}
	return -1;
}
} // end namespace differential



