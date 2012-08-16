#include "UnionCompiler.h"

#include <string>
using std::string;

#include <llvm/Support/CommandLine.h>

llvm::cl::list<string> IgnoredParams(llvm::cl::Sink);
llvm::cl::list<string> DefinedMacros("D", llvm::cl::value_desc("macro"), llvm::cl::Prefix, llvm::cl::desc("Predefine the specified macro"));
llvm::cl::list<string> IncludeDirs("I", llvm::cl::value_desc("directory"), llvm::cl::Prefix, llvm::cl::desc("Add directory to include search path"));
llvm::cl::opt<string>  InputFilename(llvm::cl::Positional, llvm::cl::desc("filename"), llvm::cl::Optional);

// UCC Flags:

llvm::cl::list<string> GuardFilename("g", llvm::cl::value_desc("to-be-guarded filename"), llvm::cl::desc("Transform program to guarded instructions mode"));
llvm::cl::list<string> GuardTaggedFilename("g_t", llvm::cl::value_desc("to-be-guarded-before-tagging file"), llvm::cl::desc("Transform to-be-tagged program to guarded instructions mode"));
llvm::cl::list<string> TagFilename("t", llvm::cl::value_desc("to-be-tagged filename"), llvm::cl::desc("Tag all variables in input code"));
llvm::cl::list<string> InlineFilename("i", llvm::cl::value_desc("input file"), llvm::cl::desc("Inline all functions in input code"));
llvm::cl::list<string> PatchedFilename("u", llvm::cl::value_desc("pathced-guarded-tagged filename"), llvm::cl::desc("Union the program with this patched version of it"));

llvm::cl::list<string> Clear("clear", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("Clear function body in case no diff is found between it and the patched version"));
llvm::cl::list<string> X0("x0", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("preserve initial values (i.e. x=x0,x'=x0' etc)"));
llvm::cl::list<string> TagEquality("tag_equality", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("make the tag variables equal to the untagged ones in the union program"));
llvm::cl::list<string> DiffPoints("diff_points", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("create diff points in the union program."));
llvm::cl::list<string> AddAsserts("asserts", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("add an assertion for tagged-untagged variable equality after each diff-point."));
llvm::cl::list<string> RetGuard("ret_guard", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("substitute return calls (i.e. return x; --> { Ret = true; RetVal = x; }"));


int main(int argc, char* argv[])
{
    return differential::UnionCompiler::Main(argc,argv);
}

