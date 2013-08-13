#include "IterativeAnalyzer.h"
#include "Analysis/AnalysisConfiguration.h"

#include <string>
using std::string;

#include <llvm/Support/CommandLine.h>

// These must be declared here (in the outermost main file) otherwise we have duplicates:
llvm::cl::list<string> IgnoredParams(llvm::cl::Sink);
llvm::cl::list<string> DefinedMacros("D", llvm::cl::value_desc("macro"), llvm::cl::Prefix, llvm::cl::desc("Predefine the specified macro"));
llvm::cl::list<string> IncludeDirs("I", llvm::cl::value_desc("directory"), llvm::cl::Prefix, llvm::cl::desc("Add directory to include search path"));
llvm::cl::opt<string>  InputFilename(llvm::cl::Positional, llvm::cl::desc("filename"), llvm::cl::Optional);
llvm::cl::opt<string>  InputFilename2(llvm::cl::Positional, llvm::cl::desc("2nd filename"), llvm::cl::Optional);
llvm::cl::list<string> ManagerType("m",llvm::cl::value_desc(differential::AnalysisConfiguration::kManagerTypes),llvm::cl::desc("Type of constraint manager for apron"));
llvm::cl::list<string> PartitionPoint("p_p",llvm::cl::value_desc(differential::AnalysisConfiguration::kPartitionPoints),llvm::cl::desc("Partition Point"));
llvm::cl::list<string> PartitionStrategy("p_s",llvm::cl::value_desc(differential::AnalysisConfiguration::kPartitionStrategies),llvm::cl::desc("Partition Strategy"));
llvm::cl::list<string> WideningPoint("w_p",llvm::cl::value_desc(differential::AnalysisConfiguration::kWideningPoints),llvm::cl::desc("Widening Point"));
llvm::cl::list<string> WideningStrategy("w_s",llvm::cl::value_desc(differential::AnalysisConfiguration::kWideningStrategies),llvm::cl::desc("Widening Strategies"));
llvm::cl::list<string> WideningThreshold("w_t",llvm::cl::value_desc("positive integer"),llvm::cl::desc("Widening Threshold"));
llvm::cl::list<string> Interleaving("interleaving",llvm::cl::value_desc(differential::AnalysisConfiguration::kInterleavigns),llvm::cl::desc("Interleaving"));
llvm::cl::list<string> ProveEquiv("prove_equiv",llvm::cl::value_desc("{true|false}"),llvm::cl::desc("Try and prove equivalence, stop once it is broken and try a different interleaving"));

int main(int argc, char* argv[])
{
    return differential::IterativeAnalyzer::Main(argc,argv);
}


