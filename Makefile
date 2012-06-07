# !!! Don't ever use ~ in the path here
LLVM = ../llvm
CLANG = $(LLVM)/tools/clang
APRON = ../apron
CXX = g++
CXXFLAGS = -g -c -fPIC  -Wno-long-long -fno-rtti #-ansi -Wall -pedantic
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
	AnalysisUtils.cpp \
	APAbstractDomain.cpp \
	AnalysisConsumer.cpp \
	CodeHandler.cpp \
	Analyzer.cpp \
	AnalyzerMain.cpp
ANALYZER_HEADERS = $(ANALYZER_SOURCES:.cpp=.h)
ANALYZER_OBJECTS = $(ANALYZER_SOURCES:.cpp=.o)
ANALYZER_EXEC = dizy
ANALYZER_SHARED = $(COMMON_SHARED) \
	-lAnalysisUtils \
	-lAPAbstractDomain \
	-lAnalysisConsumer \
	-lCodeHandler \
	-lAnalyzer

UCC_SOURCES = $(COMMON_SOURCES) \
	TagConsumer.cpp \
	GuardConsumer.cpp \
	UnionConsumer.cpp \
	InlineConsumer.cpp \
	CodeHandler.cpp \
	UnionCompiler.cpp \
	UCCMain.cpp
UCC_HEADERS = $(UCC_SOURCES:.cpp=.h)
UCC_OBJECTS = $(UCC_SOURCES:.cpp=.o)
UCC_EXEC = ucc

DUAL_SOURCES = $(COMMON_SOURCES) \
	AnalysisUtils.cpp \
	APAbstractDomain.cpp \
	AnalysisConsumer.cpp \
	TagConsumer.cpp \
	GuardConsumer.cpp \
	UnionConsumer.cpp \
	InlineConsumer.cpp \
	CodeHandler.cpp \
	Analyzer.cpp \
	UnionCompiler.cpp \
	Main.cpp
DUAL_HEADERS = $(DUAL_SOURCES:.cpp=.h)
DUAL_OBJECTS = $(DUAL_SOURCES:.cpp=.o)
DUAL_EXEC = dual


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
	-lpthread

	
#LIBS = -lclang -lLLVM-3.0 

APRON_LIBS = -lapron -lapronxx \
	-lgmp -lgmpxx \
	-lboxMPQ -loctMPQ -lpolkaMPQ \
	-lap_ppl -lap_pkgrid

all: $(UCC_EXEC) $(ANALYZER_EXEC) $(DUAL_EXEC)

$(DUAL_EXEC): $(DUAL_OBJECTS)
	$(CXX) $(DUAL_OBJECTS) $(LIB_DIR) $(LIBS) $(APRON_LIBS) -o $@

$(ANALYZER_EXEC): $(ANALYZER_OBJECTS)
	$(CXX) $(ANALYZER_OBJECTS) $(LIB_DIR) $(LIBS) $(APRON_LIBS) -o $@ 

#$(ANALYZER_EXEC): $(ANALYZER_OBJECTS)
#	$(CXX) AnalyzerMain.cpp -g -fno-rtti -Wno-long-long $(DEFS) $(INCLUDES) $(LIB_DIR) -L. $(ANALYZER_SHARED) $(LIBS) $(APRON_LIBS) -o $@ 



$(UCC_EXEC): $(UCC_OBJECTS) 
	$(CXX) $(UCC_OBJECTS) $(LIB_DIR) $(LIBS) -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCLUDES) $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCLUDES) $< -o $@
	
#%.so: %.o
#	$(CXX) -shared -Wl -o lib$@ $<

clean:
	-rm -f $(ANALYZER_EXEC) $(UCC_EXEC) $(DUAL_EXEC) *.o */*.o

install:
	-cp $(ANALYZER_EXEC) /usr/local/bin
	-cp $(UCC_EXEC) /usr/local/bin
	-cp $(DUAL_EXEC) /usr/local/bin
	-cp Script/*.sh /usr/local/bin
	
