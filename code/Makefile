# !!! Don't ever use ~ in the path here
LLVM = ../../llvm
CLANG = $(LLVM)/tools/clang
APRON = ../apron
CXX = g++
CXXFLAGS = -g -c -fPIC -Wno-long-long -fno-rtti #-ansi -Wall -pedantic
DEFS =  -D__STDC_LIMIT_MACROS=0 -D__STDC_CONSTANT_MACROS=0
INCLUDES = -I$(LLVM)/include -I$(CLANG)/include  -I/usr/include -I/usr/local/include -I$(APRON)/include
VPATH = Config/ Analysis/ Transform/

COMMON_SOURCES = Defines.cpp \
	ConfigFile.cpp \
	Utils.cpp
COMMON_HEADERS = $(COMMON_SOURCES:.cpp=.h)
COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
COMMON_SHARED = -lDefines \
	-lConfigFile \
	-lUtils

ANALYZER_SOURCES = $(COMMON_SOURCES) \
	Abstract1.cpp \
	Abstract2.cpp \
	AnalysisUtils.cpp \
	APAbstractDomain.cpp \
	AnalysisFlags.cpp \
	TransferFuncs.cpp \
	AnalysisConsumer.cpp \
	CodeHandler.cpp \
	Analyzer.cpp \
	AnalyzerMain.cpp
ANALYZER_HEADERS = $(ANALYZER_SOURCES:.cpp=.h)
ANALYZER_OBJECTS = $(ANALYZER_SOURCES:.cpp=.o)
ANALYZER_EXEC = cdizy
ANALYZER_SHARED = $(COMMON_SHARED) \
	-lAnalysisUtils \
	-lAPAbstractDomain \
	-lAnalysisConsumer \
	-lCodeHandler \
	-lAnalyzer
	
ITERATIVE_ANALYZER_SOURCES = $(COMMON_SOURCES) \
	Abstract1.cpp \
	Abstract2.cpp \
	AnalysisUtils.cpp \
	APAbstractDomain.cpp \
	AnalysisFlags.cpp \
	TransferFuncs.cpp \
	CodeHandler.cpp \
	IterativeTransformer.cpp \
	IterativeSolver.cpp \
	IterativeAnalyzer.cpp \
	IterativeAnalyzerMain.cpp
ITERATIVE_ANALYZER_HEADERS = $(ITERATIVE_ANALYZER_SOURCES:.cpp=.h)
ITERATIVE_ANALYZER_OBJECTS = $(ITERATIVE_ANALYZER_SOURCES:.cpp=.o)
ITERATIVE_ANALYZER_EXEC = idizy
ITERATIVE_ANALYZER_SHARED = $(COMMON_SHARED) \
	-lAnalysisUtils \
	-lAPAbstractDomain \
	-lAnalysisConsumer \
	-lCodeHandler \
	-lIterativeSolver \
	-lIterativeAnalyzer

CCC_SOURCES = $(COMMON_SOURCES) \
	TagConsumer.cpp \
	GuardConsumer.cpp \
	UnionConsumer.cpp \
	InlineConsumer.cpp \
	CodeHandler.cpp \
	UnionCompiler.cpp \
	CCCMain.cpp
CCC_HEADERS = $(CCC_SOURCES:.cpp=.h)
CCC_OBJECTS = $(CCC_SOURCES:.cpp=.o)
CCC_EXEC = ccc

CCCDIZY_SOURCES = $(COMMON_SOURCES) \
	Abstract1.cpp \
	Abstract2.cpp \
	AnalysisUtils.cpp \
	APAbstractDomain.cpp \
	AnalysisFlags.cpp \
	TransferFuncs.cpp \
	AnalysisConsumer.cpp \
	TagConsumer.cpp \
	GuardConsumer.cpp \
	UnionConsumer.cpp \
	InlineConsumer.cpp \
	CodeHandler.cpp \
	Analyzer.cpp \
	UnionCompiler.cpp \
	Main.cpp
CCCDIZY_HEADERS = $(CCCDIZY_SOURCES:.cpp=.h)
CCCDIZY_OBJECTS = $(CCCDIZY_SOURCES:.cpp=.o)
CCCDIZY_EXEC = cccdizy


LIB_DIR = -L$(LLVM)/Release/lib -L$(LLVM)/Release+Asserts/lib -L$(LLVM)/Debug+Asserts/lib -L$(APRON)/lib
# !!! The ORDER of these LIBS is VERY IMPORTANT !!!
LIBS =  -lclangFrontendTool \
	-lclangFrontend \
	-lclangDriver \
	-lclangSerialization \
	-lclangCodeGen \
	-lclangParse \
	-lclangSema \
	-lclangStaticAnalyzerCheckers \
	-lclangAnalysis \
	-lclangIndex \
	-lclangRewrite \
	-lclangAST \
	-lclangLex \
	-lclangBasic \
	-lLLVMCore \
	-lLLVMSupport \
	-lLLVMMC \
	-ldl \
	-lpthread \
	-lssl

	
#LIBS = -lclang -lLLVM-3.0 

APRON_LIBS = -lapron -lapronxx \
	-lgmp -lgmpxx \
	-lboxMPQ -loctMPQ -lpolkaMPQ \
	-lap_ppl -lap_pkgrid

all: $(CCC_EXEC) $(ANALYZER_EXEC) $(ITERATIVE_ANALYZER_EXEC) $(CCCDIZY_EXEC)

$(CCCDIZY_EXEC): $(CCCDIZY_OBJECTS)
	$(CXX) $(CCCDIZY_OBJECTS) $(LIB_DIR) $(LIBS) $(APRON_LIBS) -o $@

$(ANALYZER_EXEC): $(ANALYZER_OBJECTS)
	$(CXX) $(ANALYZER_OBJECTS) $(LIB_DIR) $(LIBS) $(APRON_LIBS) -o $@ 

$(ITERATIVE_ANALYZER_EXEC): $(ITERATIVE_ANALYZER_OBJECTS)
	$(CXX) $(ITERATIVE_ANALYZER_OBJECTS) $(LIB_DIR) $(LIBS) $(APRON_LIBS) -o $@

$(CCC_EXEC): $(CCC_OBJECTS) 
	$(CXX) $(CCC_OBJECTS) $(LIB_DIR) $(LIBS) -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCLUDES) $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCLUDES) $< -o $@
	
#%.so: %.o
#	$(CXX) -shared -Wl -o lib$@ $<

clean:
	-rm -f $(ANALYZER_EXEC) $(ITERATIVE_ANALYZER_EXEC) $(CCC_EXEC) $(CCCDIZY_EXEC) *.o */*.o

	
