#ifndef ANALYZER_H
#define ANALYZER_H
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
#include <clang/Analysis/Analyses/LiveVariables.h>
#include <clang/Analysis/Analyses/ReachableCode.h>
#include <clang/Analysis/AnalysisContext.h>
#include <clang/Analysis/CFG.h>
#include <clang/Analysis/FlowSensitive/DataflowSolver.h>
using namespace clang;
#include "CodeHandler.h"
#include "Analysis/AnalysisConsumer.h"
namespace differential
{
class IterativeAnalyzer
{
private:
	AnalyzerOptions analyzer_options_;

public:
	IterativeAnalyzer();
	~IterativeAnalyzer() { }
	void RunAnalysis(ostream& report_file = cout);
	static int Main(int argc, char *argv[]);
};
}
#endif
