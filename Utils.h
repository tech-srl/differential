#ifndef UTILS_H
#define UTILS_H

#include <llvm/ADT/StringRef.h>
#include <clang/AST/Decl.h>
#include <clang/AST/Stmt.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Rewrite/Rewriter.h>
#include "Config/ConfigFile.h"

using namespace std;
using namespace llvm;
using namespace clang;

namespace differential {

	class Utils {

		static ConfigFile CF;

		public:

        static size_t GetStmtLength(Stmt *node);
        static size_t GetDeclLength(Decl *node);
        static string PrintStmt(Stmt *node, ASTContext &contex);
        static string PrintDecl(Decl *node, ASTContext &contex);
        static void Names(string &name, string &tagged_name);
		static void Rename(const StringRef& Src, string& Result);
        static string ReplaceAll(const StringRef& source, const StringRef& tokens, const StringRef& replacement) ;
		static vector<string> Split(const string& source, const string& token);
        static string RemoveGuards(const string source);
        static string ConditionToGuard(const string condition);
		static void WriteFiles(Rewriter& rw, string filename = "");
		static unsigned int Rand();
		static bool isWhitespace(char c);
		static void Init(ConfigFile& file);
		static SourceLocation getIdentifierStartLoc(VarDecl * node, Rewriter& rw);
        static SourceLocation getIdentifierNameLoc(VarDecl * node, Rewriter& rw);
		static SourceLocation getIdentifierEndLoc(VarDecl * node, Rewriter& rw);
        static SourceLocation getNextEligibleCodeLoc(Stmt * node, Rewriter& rw);

		// String trimming functions
		// trim from both ends
		static inline string Trim(string s) { return LTrim(RTrim(s)); }
		// trim from start
		static inline string LTrim(string s) {
		        s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
		        return s;
		}
		// trim from end
		static inline string RTrim(string s) {
		        s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
		        return s;
		}
	};
}
#endif
