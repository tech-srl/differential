#include "CodeHandler.h"

extern llvm::cl::list<std::string> IgnoredParams;
extern llvm::cl::list<std::string> DefinedMacros;
extern llvm::cl::list<std::string> IncludeDirs;
extern llvm::cl::opt<std::string>  InputFilename;

namespace differential {

// Append a #define line to Buf for Macro.  Macro should be of the form XXX,
// in which case we emit "#define XXX 1" or "XXX=Y z W" in which case we emit
// "#define XXX Y z W".  To get a #define with no value, use "XXX=".
    void CodeHandler::DefineBuiltinMacro(vector<char> &Buf, const char *Macro, const char *Command) {
        Buf.insert(Buf.end(), Command, Command+strlen(Command));
        if ( const char *Equal = strchr(Macro, '=') ) {
            // Turn the = into ' '.
            Buf.insert(Buf.end(), Macro, Equal);
            Buf.push_back(' ');
            Buf.insert(Buf.end(), Equal+1, Equal+strlen(Equal));
        } else {
            // Push "macroname 1".
            Buf.insert(Buf.end(), Macro, Macro+strlen(Macro));
            Buf.push_back(' ');
            Buf.push_back('1');
        }
        Buf.push_back('\n');
    }

    CodeHandler::CodeHandler()  :
    file_manager_(FileSystemOptions()),
    header_search_(file_manager_),
    source_manager_(diagnostics_engine_,file_manager_),
    text_diag_printer_(new TextDiagnosticPrinter(llvm::errs(), diagnostic_options_)),
    diagnostics_engine_(llvm::IntrusiveRefCntPtr<DiagnosticIDs>(new DiagnosticIDs())) {
        const FileEntry *file_entry_ptr = file_manager_.getFile(InputFilename);
        if ( !file_entry_ptr ) {
            cerr << "Failed to open \'" << InputFilename << "\'" << endl;
            exit(1);
        }

        diagnostics_engine_.setClient(text_diag_printer_);
        diagnostics_engine_.setSourceManager(&source_manager_);

        // Allow C99 and GNU extenstions
        language_options_.C99 = 1;
        language_options_.GNUKeywords = 1;
        language_options_.Borland = 1;
        language_options_.CPlusPlus = 1;

        // Setting the target machine properties
        Triple triple;
        triple.setArch(Triple::x86);
        triple.setVendor(Triple::PC);
        triple.setOS(Triple::Linux);
        target_options_.Triple = triple.str();
        target_options_.ABI = "";
        target_options_.CPU = "";
        target_options_.Features.clear();

        // Create a target information object
        target_info_ = TargetInfo::CreateTargetInfo(diagnostics_engine_, target_options_);
		
        header_search_options_.UseStandardSystemIncludes = true;
        header_search_options_.UseBuiltinIncludes = true;
        header_search_options_.UseStandardCXXIncludes = true;
        
		header_search_options_.AddPath("/usr/lib/clang/1.1/include/",frontend::Angled, true, false, true);
        header_search_options_.AddPath("/usr/include/",frontend::Angled, true, false, true);
        header_search_options_.AddPath("/usr/include/linux/",frontend::Angled, true, false, true);
        header_search_options_.AddPath("/usr/lib/gcc/i486-linux-gnu/4.4/include/",frontend::Angled, true, false, true);
		
        // Add user header search directories
        for ( unsigned int i = 0;i < IncludeDirs.size();++i ) {
            cerr << "adding " << IncludeDirs[i] << endl;
            header_search_options_.AddPath(IncludeDirs[i], frontend::Angled, true, false, true);
        }
        ApplyHeaderSearchOptions(header_search_, header_search_options_, language_options_, triple);
        // Add defines passed in through parameters
        vector<char> predefineBuffer;
        for ( unsigned int i = 0;i < DefinedMacros.size();++i ) {
            cerr << "defining " << DefinedMacros[i] << endl;
            DefineBuiltinMacro(predefineBuffer, DefinedMacros[i].c_str());
        }
		DefineBuiltinMacro(predefineBuffer,"_Bool=int");
        predefineBuffer.push_back('\0');
        // Create the preproccessor from all the other inputs
        CompilerInstance compiler_instance;
        preprocessor_ptr_ = new Preprocessor(diagnostics_engine_, language_options_, target_info_, source_manager_, header_search_, compiler_instance);
        preprocessor_ptr_->setPredefines(&predefineBuffer[0]);
		InitializePreprocessor(*preprocessor_ptr_, preprocessor_options_, header_search_options_, frontend_options_);
        text_diag_printer_->BeginSourceFile(language_options_, preprocessor_ptr_);
        source_manager_.createMainFileID(file_entry_ptr);
    }

    CodeHandler::~CodeHandler() {
        delete target_info_;
        delete preprocessor_ptr_;
    }

    void CodeHandler::Init(int argc, char *argv[]) {
        llvm::cl::ParseCommandLineOptions(argc, argv, "");
        if ( !IgnoredParams.empty() ) {
            cerr << "Ignoring the following parameters:";
            copy(IgnoredParams.begin(), IgnoredParams.end(), ostream_iterator<string>(cerr, " "));
        }
    }

}
