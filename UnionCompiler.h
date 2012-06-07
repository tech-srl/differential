#ifndef UCC_H
#define UCC_H

#include <clang/AST/ASTContext.h>

#include "CodeHandler.h"

namespace differential {

   class UnionCompiler : public CodeHandler {
      Rewriter      rewriter_;
      ASTContext    *contex_ptr_;

      void Transform(ASTConsumer  &consumer);
      string OutputUnion(string FileStr, string FilePatchedStr, unsigned &diff_point_ctr, unsigned &added_ctr, unsigned &deleted_ctr, bool clear);

   public:

      UnionCompiler();
      virtual ~UnionCompiler() {}

	  void AddDefinitions();
      void GuardedInstructionsTransform();
      void TagInstructionsTransform();
      void InlineTransform();
      void UnionTransform(ostream& report_file = cout);

      static int Main(int argc, char* argv[]);
   };

}

#endif
