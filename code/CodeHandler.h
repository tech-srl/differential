#ifndef CODE_HANDLER_H
#define CODE_HANDLER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/MemoryBuffer.h>
using namespace llvm;

#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/FileManager.h>
#include <clang/Basic/IdentifierTable.h>
#include <clang/Basic/TargetInfo.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/PreprocessorOptions.h>
#include <clang/Frontend/TextDiagnosticPrinter.h>
#include <clang/Frontend/Utils.h>
#include <clang/Lex/HeaderSearch.h>
#include <clang/Lex/LexDiagnostic.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Parse/ParseAST.h>
#include <clang/Parse/Parser.h>
using namespace clang;

#include "Defines.h"
#include "Utils.h"

namespace differential {

class CodeHandler {
protected:
    LangOptions language_options_;
    TargetOptions target_options_;
    PreprocessorOptions preprocessor_options_;
    HeaderSearchOptions header_search_options_;
    FrontendOptions frontend_options_;
    TargetInfo* target_info_;
    FileManager file_manager_;
    HeaderSearch header_search_;
    Preprocessor * preprocessor_ptr_;
    SourceManager source_manager_;
	DiagnosticOptions diagnostic_options_;
    DiagnosticsEngine diagnostics_engine_;
	TextDiagnosticPrinter * text_diag_printer_;
	ASTContext * contex_ptr;

public:
    CodeHandler(string filename);
    virtual ~CodeHandler();
    static void Init(int argc, char *argv[]);
    static void DefineBuiltinMacro(vector<char> &Buf, const char *Macro, const char *Command = "#define ");

    ASTContext * getAST(void);

};

}

#endif
