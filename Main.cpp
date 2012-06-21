#include "Analyzer.h"
#include "UnionCompiler.h"
using namespace differential;


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//#define DEBUG


#include <string>

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
llvm::cl::list<string> PatchedFilename("u", llvm::cl::value_desc("patched-guarded-tagged filename"), llvm::cl::desc("Union the program with this patched version of it"));
llvm::cl::list<string> Clear("clear", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("Clear function body in case no diff is found between it and the patched version"));
llvm::cl::list<string> X0("x0", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("preserve initial values (i.e. x=x0,x'=x0' etc)"));
llvm::cl::list<string> TagEquality("tag_equality", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("make the tag variables equal to the untagged ones in the union program"));
llvm::cl::list<string> DiffPoints("diff_points", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("create diff points in the union program."));
llvm::cl::list<string> AddAsserts("asserts", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("add an assertion for tagged-untagged variable equality after each diff-point."));
llvm::cl::list<string> RetGuard("ret_guard", llvm::cl::value_desc("flag"), llvm::cl::Prefix,llvm::cl::desc("substitute return calls (i.e. return x; --> { Ret = true; RetVal = x; }"));

// Analysis Flags:
llvm::cl::list<string> ManagerType("m",llvm::cl::value_desc(differential::Analyzer::Flags::kManagerTypes),llvm::cl::desc("Type of constraint manager for apron"));
llvm::cl::list<string> CanonizationPoint("c_p",llvm::cl::value_desc(differential::Analyzer::Flags::kFlagCanonizationPoints),llvm::cl::desc("Canonization Point"));
llvm::cl::list<string> CanonizationStrategy("c_s",llvm::cl::value_desc(differential::Analyzer::Flags::kFlagCanonizationStrategies),llvm::cl::desc("Canonization Strategy"));
llvm::cl::list<string> CanonizationThreshold("c_t",llvm::cl::value_desc("<positive integer>"),llvm::cl::desc("Canonization Threshold"));
llvm::cl::list<string> WideningPoint("w_p",llvm::cl::value_desc(differential::Analyzer::Flags::kFlagWideningPoints),llvm::cl::desc("Widening Point"));
llvm::cl::list<string> WideningStrategy("w_s",llvm::cl::value_desc(differential::Analyzer::Flags::kFlagWideningStrategies),llvm::cl::desc("Widening Strategies"));
llvm::cl::list<string> WideningThreshold("w_t",llvm::cl::value_desc("<positive integer>"),llvm::cl::desc("Widening Threshold"));

// Complete Flags:
llvm::cl::list<string> ReportFilename("r",llvm::cl::value_desc("report filename"),llvm::cl::desc("Filename for outputing the statistics when running with -c"));


int main(int argc, char* argv[]) {
    CodeHandler::Init(argc,argv);

    // First check if the report file exists and if not create the table header
    fstream report_file;
    const char * report_file_name = (ReportFilename.size()) ? ReportFilename[0].c_str() : "report.out";
    report_file.open(report_file_name,ios::in);
    bool file_exists = report_file.is_open();
    report_file.close();

    report_file.open(report_file_name,ofstream::out | ofstream::app);
    if ( !file_exists )
        report_file << "| " << setw(15) << "Filename" << " | " <<
        setw(10) << "Domain" << " | " <<
        setw(12) << "CanonPoint" << " | " <<
        setw(15) << "CanonStrategy" << " | " <<
        setw(6) << "#Added" << " | " <<
        setw(8) << "#Deleted" << " | " <<
        setw(12) << "#DiffPoints" << " | " <<
        setw(6) << "#Diffs" << " | " <<
        setw(15) << "Optimal #Diffs" << "|\n";

    report_file << "| "<< setw(15) << InputFilename << 
    " | " << setw(10) << string(ManagerType[0]) << 
    " | " << setw(12) << string((CanonizationPoint.size() > 0) ? CanonizationPoint[0] : "none") << 
    " | " << setw(15) << string((CanonizationStrategy.size() > 0) ? CanonizationStrategy[0] : "equiv") <<
    " | ";

    string filename = InputFilename, patched_filname = PatchedFilename[0];
    // Start by guarding both files

    GuardFilename.addValue(filename);
    cout << "GuardFilename = " << GuardFilename[0] << endl;
    InputFilename = GuardFilename[0];
    UnionCompiler().GuardedInstructionsTransform();
    // Ignore this option from now own (the condition is size() == 1)
    GuardFilename.addValue("");

    GuardTaggedFilename.addValue(patched_filname);
    cout << "GuardTaggedFilename = " << GuardTaggedFilename[0] << endl;
    InputFilename = GuardTaggedFilename[0];
    UnionCompiler().GuardedInstructionsTransform();
    // Ignore this option from now own (the condition is size() == 1)
    GuardTaggedFilename.addValue("");

    // Now tag the patched file
    TagFilename.addValue(Defines::kGuardedFilenamePrefix + patched_filname);
    cout << "TagFilename = " << TagFilename[0] << endl;
    InputFilename = TagFilename[0];
    UnionCompiler().TagInstructionsTransform();
    // Ignore this option from now own (the condition is size() == 1)
    TagFilename.addValue("");

    // Now union the files
    InputFilename.setValue(Defines::kGuardedFilenamePrefix + filename);
    PatchedFilename[0] = Defines::kTaggedFilenamePrefix + Defines::kGuardedFilenamePrefix + patched_filname;
    cout << "InputFilename = " << InputFilename << ",PatchedFilename = " << PatchedFilename[0] << endl;
    UnionCompiler().UnionTransform(report_file);
    // Ignore this option from now own (the condition is size() == 1)
    PatchedFilename.addValue("");

    // Now analyze it
    InputFilename.setValue(Defines::kUnionedFilenamePrefix + filename);
    cout << "InputFilename = " << InputFilename << endl;
    Analyzer().RunAnalysis(report_file);

    report_file << setw(15) <<" |\n";
    report_file.close();

    return 0;

}

