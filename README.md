differential
============

This project hold several experimental tools developed during our ({yahave,nimi}@cs.technion.ac.il) research into differential analysis i.e. finding semantic differences and proving equivalence of programs.

Reaserach paper: http://www.cs.technion.ac.il/~nimi/publications/dizy.pdf

Developed tools:

ccc - Correlating C Compiler
----------------------------
ccc is an experimental tool for transforming C programs to a normal form thats easier for our DIZY analyzers to analyze (take a look at our SAS'13 paper for more details and background). To build it, get the code from the github repository and make ccc (you will need to setup an environment according to the INSTALL file, but can ignore the part about APRON).

ccc features:

- Guarding - transforms code to a guarded command form. Useful for many applications. Fairly tested, may be lacking some language features.
- Tagging - adds a "T_" prefix to all variables in the code. This is an important stage in creating the correlating program.
- Correlating - Creates a correlating program out of a guarded program and a tagged guarded program. Correlation is done at the function level such that functions keep their original prototypes. Caveats exist mainly for looping programs, in case loops do not align.
- Inlining - A disastrous attempt at implement inlining. Does not work :)


cdizy - Analyzer for Semantic Differencing using Correlating Program
--------------------------------------------------------------------

idizy - Analyzer for Iterative Semantic Differencing of Programs
----------------------------------------------------------------



** All tools accept command line arguments for include libraries and defining macros. 
