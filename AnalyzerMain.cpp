#include "Analyzer.h"

#include <string>
using std::string;

#include <llvm/Support/CommandLine.h>

llvm::cl::list<string> IgnoredParams(llvm::cl::Sink);
llvm::cl::list<string> DefinedMacros("D", llvm::cl::value_desc("macro"), llvm::cl::Prefix, llvm::cl::desc("Predefine the specified macro"));
llvm::cl::list<string> IncludeDirs("I", llvm::cl::value_desc("directory"), llvm::cl::Prefix, llvm::cl::desc("Add directory to include search path"));
llvm::cl::opt<string>  InputFilename(llvm::cl::Positional, llvm::cl::desc("filename"), llvm::cl::Optional);

// Analysis Flags:
llvm::cl::list<string> ManagerType("m",llvm::cl::value_desc(differential::Analyzer::Flags::kManagerTypes),llvm::cl::desc("Type of constraint manager for apron"));
llvm::cl::list<string> CanonizationPoint("c_p",llvm::cl::value_desc(differential::Analyzer::Flags::kFlagCanonizationPoints),llvm::cl::desc("Canonization Point"));
llvm::cl::list<string> CanonizationStrategy("c_s",llvm::cl::value_desc(differential::Analyzer::Flags::kFlagCanonizationStrategies),llvm::cl::desc("Canonization Strategy"));
llvm::cl::list<string> CanonizationThreshold("c_t",llvm::cl::value_desc("<positive integer>"),llvm::cl::desc("Canonization Threshold"));
llvm::cl::list<string> WideningPoint("w_p",llvm::cl::value_desc(differential::Analyzer::Flags::kFlagWideningPoints),llvm::cl::desc("Widening Point"));
llvm::cl::list<string> WideningStrategy("w_s",llvm::cl::value_desc(differential::Analyzer::Flags::kFlagWideningStrategies),llvm::cl::desc("Widening Strategies"));
llvm::cl::list<string> WideningThreshold("w_t",llvm::cl::value_desc("<positive integer>"),llvm::cl::desc("Widening Threshold"));

int main(int argc, char* argv[])
{
    return differential::Analyzer::Main(argc,argv);
}


