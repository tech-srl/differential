#include "TagConsumer.h"
#include <clang/Lex/Lexer.h>
#include <clang/Basic/Linkage.h>

namespace differential {

    void TagInstructions::VisitDeclRefExpr(DeclRefExpr* node) {
        VarDecl * decl_ptr = dyn_cast<VarDecl>(node->getDecl());
        if (!decl_ptr) // ignore other types of declarations for now
            return;
        if (!decl_ptr->isExternC()) {// ignore externs 
            rewriter_.InsertText(node->getLocStart(), Defines::kTagPrefix); // tag it
            if (add_asserts_ && is_l_value_ && 
                !decl_ptr->getType()->isArrayType() && // ignore arrays 
                !decl_ptr->getType()->isPointerType() && // ignore pointers
                decl_ptr->getNameAsString().find(Defines::kGuardPrefix) > 0) { // ignore guards  
                is_l_value_ = false; 
                string name = node->getDecl()->getNameAsString() ;
                // add an assertion for checking equality right after the last statement
                stringstream assertion_ss;
                assertion_ss << "\n" << Defines::kAssertPrefix << "(" << name << " == " << Defines::kTagPrefix << name << " && " << ++asserts_ctr_ << ");";
                rewriter_.InsertText(Utils::getNextEligibleCodeLoc(node, rewriter_), assertion_ss.str());
            }
        }
    }

    void TagInstructions::VisitFunctionDecl(FunctionDecl *node) {
        if ( !node->isMain() && ( source_manager_.isFromMainFile(node->getLocation()) ||
                                  !source_manager_.isInExternCSystemHeader(node->getLocation()) || // ignore printf, etc.
                                  !source_manager_.isInSystemHeader(node->getLocation()) ) ) {
        }

        if ( node->isThisDeclarationADefinition() ) {
            stringstream ParamsOS;
            ParamsOS << "\n";
            // For now add the tagged parameters as local variables
            for ( unsigned i = 0 ; i < node->getNumParams() ; i++ ) {
                ParmVarDecl * p = node->getParamDecl(i);
                string decl = Utils::PrintDecl(p,contex_);
                string name = p->getNameAsString();
                unsigned l = decl.find_last_of(name) - name.size() + 1;
                string tag_decl = decl;
                tag_decl.insert(l,Defines::kTagPrefix);
                // Add the tagged parameter
                ParamsOS << Defines::kTagParamDef << tag_decl << ((tag_equality_) ? (string(" = ") + name + ";\n") : ";\n");
            }
            rewriter_.InsertText(node->getBody()->getLocStart().getLocWithOffset(1), ParamsOS.str());
            asserts_ctr_ = 0;
            Visit(node->getBody());
        }
    }

    void TagInstructions::VisitDeclStmt(DeclStmt *node) {
        for (DeclStmt::decl_iterator
             iter = node->decl_begin(), 
             end = node->decl_end(); 
             iter != end; ++iter) {
            if (isa<VarDecl>(*iter))
                Visit(*iter);

        }
    }

    void TagInstructions::VisitGotoStmt(GotoStmt * node) {
        rewriter_.InsertText(node->getLabelLoc(), Defines::kTagPrefix); 
    }

    void TagInstructions::VisitVarDecl(VarDecl *node) {
        if ( node->hasBody() )
            return Visit(node->getBody());
        if ( node->hasInit() )
            Visit(node->getInit());
        if ( node->isExternC() )
            return;
        // make RetVal' = RetVal
        /*
        if (node->getNameAsString() == Defines::kRetVal) {
            stringstream ss;
            ss << " = " << Defines::kRetVal;
            rewriter_.InsertText(Utils::getIdentifierEndLoc(node,rewriter_),ss.str());
        }
        */
        rewriter_.InsertText(Utils::getIdentifierNameLoc(node,rewriter_), Defines::kTagPrefix);
    }


    void TagInstructions::VisitStmt(Stmt *node) {
        VisitChildren(node);
    }

    void TagInstructions::VisitLabelStmt(LabelStmt * node) {
        rewriter_.InsertText(node->getLocStart(), Defines::kTagPrefix); 
        Visit(node->getSubStmt());
    }

    void TagInstructions::VisitBinaryOperator(BinaryOperator *node) {
        if ( node->getOpcode() >= BO_Assign ) // remember it's being assigned to
            is_l_value_ = true;
        Visit(node->getLHS());
        is_l_value_ = false; 
        Visit(node->getRHS());
    }

    void TagInstructions::VisitUnaryOperator(UnaryOperator *node) {
        if ( node->getOpcode() >= UO_PostInc && node->getOpcode() <= UO_PreDec )
            is_l_value_ = true;
        Visit(node->getSubExpr());
        is_l_value_ = false; 
    }

    void TagInstructions::VisitChildren(Stmt *node) {
        for ( Stmt::child_iterator I = node->child_begin(), E = node->child_end();I != E;++I )
            if ( *I )
                Visit(*I);
    }



}
