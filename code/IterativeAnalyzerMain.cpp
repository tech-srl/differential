#include "IterativeAnalyzer.h"
#include "Analysis/AnalysisFlags.h"

#include <string>
using std::string;

#include <llvm/Support/CommandLine.h>

llvm::cl::list<string> IgnoredParams(llvm::cl::Sink);
llvm::cl::list<string> DefinedMacros("D", llvm::cl::value_desc("macro"), llvm::cl::Prefix, llvm::cl::desc("Predefine the specified macro"));
llvm::cl::list<string> IncludeDirs("I", llvm::cl::value_desc("directory"), llvm::cl::Prefix, llvm::cl::desc("Add directory to include search path"));
llvm::cl::opt<string>  InputFilename(llvm::cl::Positional, llvm::cl::desc("filename"), llvm::cl::Optional);
llvm::cl::opt<string>  InputFilename2(llvm::cl::Positional, llvm::cl::desc("2nd filename"), llvm::cl::Optional);

// Analysis Flags:
llvm::cl::list<string> ManagerType("m",llvm::cl::value_desc(differential::AnalysisFlags::kManagerTypes),llvm::cl::desc("Type of constraint manager for apron"));
llvm::cl::list<string> ComputeDiff("diff",llvm::cl::value_desc("flag"),llvm::cl::desc("Compute diff over all states (instead of just showing offendifng states)"));
llvm::cl::list<string> PartitionPoint("p_p",llvm::cl::value_desc(differential::AnalysisFlags::kFlagPartitionPoints),llvm::cl::desc("Partition Point"));
llvm::cl::list<string> PartitionStrategy("p_s",llvm::cl::value_desc(differential::AnalysisFlags::kFlagPartitionStrategies),llvm::cl::desc("Partition Strategy"));
llvm::cl::list<string> PartitonThreshold("p_t",llvm::cl::value_desc("positive integer"),llvm::cl::desc("Partition Threshold"));
llvm::cl::list<string> WideningPoint("w_p",llvm::cl::value_desc(differential::AnalysisFlags::kFlagWideningPoints),llvm::cl::desc("Widening Point"));
llvm::cl::list<string> WideningStrategy("w_s",llvm::cl::value_desc(differential::AnalysisFlags::kFlagWideningStrategies),llvm::cl::desc("Widening Strategies"));
llvm::cl::list<string> WideningThreshold("w_t",llvm::cl::value_desc("positive integer"),llvm::cl::desc("Widening Threshold"));

int main(int argc, char* argv[])
{
    return differential::IterativeAnalyzer::Main(argc,argv);
}


