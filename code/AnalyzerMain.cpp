#include "Analyzer.h"
#include "Analysis/AnalysisConfiguration.h"

#include <string>
using std::string;

#include <llvm/Support/CommandLine.h>

llvm::cl::list<string> IgnoredParams(llvm::cl::Sink);
llvm::cl::list<string> DefinedMacros("D", llvm::cl::value_desc("macro"), llvm::cl::Prefix, llvm::cl::desc("Predefine the specified macro"));
llvm::cl::list<string> IncludeDirs("I", llvm::cl::value_desc("directory"), llvm::cl::Prefix, llvm::cl::desc("Add directory to include search path"));
llvm::cl::opt<string>  InputFilename(llvm::cl::Positional, llvm::cl::desc("filename"), llvm::cl::Optional);

// Analysis Flags:
llvm::cl::list<string> ManagerType("m",llvm::cl::value_desc(differential::AnalysisConfiguration::kManagerTypes),llvm::cl::desc("Type of constraint manager for apron"));
llvm::cl::list<string> ComputeDiff("diff",llvm::cl::value_desc("flag"),llvm::cl::desc("Compute diff over all states (instead of just showing offendifng states)"));
llvm::cl::list<string> PartitionPoint("p_p",llvm::cl::value_desc(differential::AnalysisConfiguration::kPartitionPoints),llvm::cl::desc("Partition Point"));
llvm::cl::list<string> PartitionStrategy("p_s",llvm::cl::value_desc(differential::AnalysisConfiguration::kPartitionStrategies),llvm::cl::desc("Partition Strategy"));
llvm::cl::list<string> WideningPoint("w_p",llvm::cl::value_desc(differential::AnalysisConfiguration::kWideningPoints),llvm::cl::desc("Widening Point"));
llvm::cl::list<string> WideningStrategy("w_s",llvm::cl::value_desc(differential::AnalysisConfiguration::kWideningStrategies),llvm::cl::desc("Widening Strategies"));
llvm::cl::list<string> WideningThreshold("w_t",llvm::cl::value_desc("positive integer"),llvm::cl::desc("Widening Threshold"));

int main(int argc, char* argv[])
{
	return differential::Analyzer::Main(argc,argv);
}


