/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Parser::WfExpression.parser.txt

This file is generated by: Vczh Parser Generator
***********************************************************************/

#ifndef VCZH_WORKFLOW_EXPRESSION_WFEXPRESSIONPARSER_EMPTY
#define VCZH_WORKFLOW_EXPRESSION_WFEXPRESSIONPARSER_EMPTY

#include "../../Import/Vlpp.h"
#include "WfExpression_Ast.h"

namespace vl
{
	namespace workflow
	{
		namespace empty_visitor
		{
			class TypeVisitor : public Object, public WfType::IVisitor
			{
			public:

				// Visitor Members -----------------------------------
				void Visit(WfPredefinedType* node)override;
				void Visit(WfTopQualifiedType* node)override;
				void Visit(WfReferenceType* node)override;
				void Visit(WfRawPointerType* node)override;
				void Visit(WfSharedPointerType* node)override;
				void Visit(WfNullableType* node)override;
				void Visit(WfEnumerableType* node)override;
				void Visit(WfMapType* node)override;
				void Visit(WfFunctionType* node)override;
				void Visit(WfChildType* node)override;
			};

			class ExpressionVisitor : public Object, public WfExpression::IVisitor
			{
			public:

				// Dispatch (virtual) --------------------------------
				virtual void Dispatch(WfVirtualExpression* node) = 0;

				// Visitor Members -----------------------------------
				void Visit(WfThisExpression* node)override;
				void Visit(WfTopQualifiedExpression* node)override;
				void Visit(WfReferenceExpression* node)override;
				void Visit(WfOrderedNameExpression* node)override;
				void Visit(WfOrderedLambdaExpression* node)override;
				void Visit(WfMemberExpression* node)override;
				void Visit(WfChildExpression* node)override;
				void Visit(WfLiteralExpression* node)override;
				void Visit(WfFloatingExpression* node)override;
				void Visit(WfIntegerExpression* node)override;
				void Visit(WfStringExpression* node)override;
				void Visit(WfUnaryExpression* node)override;
				void Visit(WfBinaryExpression* node)override;
				void Visit(WfLetExpression* node)override;
				void Visit(WfIfExpression* node)override;
				void Visit(WfRangeExpression* node)override;
				void Visit(WfSetTestingExpression* node)override;
				void Visit(WfConstructorExpression* node)override;
				void Visit(WfInferExpression* node)override;
				void Visit(WfTypeCastingExpression* node)override;
				void Visit(WfTypeTestingExpression* node)override;
				void Visit(WfTypeOfTypeExpression* node)override;
				void Visit(WfTypeOfExpressionExpression* node)override;
				void Visit(WfAttachEventExpression* node)override;
				void Visit(WfDetachEventExpression* node)override;
				void Visit(WfObserveExpression* node)override;
				void Visit(WfCallExpression* node)override;
				void Visit(WfFunctionExpression* node)override;
				void Visit(WfNewClassExpression* node)override;
				void Visit(WfNewInterfaceExpression* node)override;
				void Visit(WfVirtualExpression* node)override;
			};

			class StatementVisitor : public Object, public WfStatement::IVisitor
			{
			public:

				// Visitor Members -----------------------------------
				void Visit(WfBreakStatement* node)override;
				void Visit(WfContinueStatement* node)override;
				void Visit(WfReturnStatement* node)override;
				void Visit(WfDeleteStatement* node)override;
				void Visit(WfRaiseExceptionStatement* node)override;
				void Visit(WfIfStatement* node)override;
				void Visit(WfSwitchStatement* node)override;
				void Visit(WfWhileStatement* node)override;
				void Visit(WfForEachStatement* node)override;
				void Visit(WfTryStatement* node)override;
				void Visit(WfBlockStatement* node)override;
				void Visit(WfVariableStatement* node)override;
				void Visit(WfExpressionStatement* node)override;
			};

			class DeclarationVisitor : public Object, public WfDeclaration::IVisitor
			{
			public:

				// Visitor Members -----------------------------------
				void Visit(WfNamespaceDeclaration* node)override;
				void Visit(WfFunctionDeclaration* node)override;
				void Visit(WfVariableDeclaration* node)override;
				void Visit(WfEventDeclaration* node)override;
				void Visit(WfPropertyDeclaration* node)override;
				void Visit(WfConstructorDeclaration* node)override;
				void Visit(WfDestructorDeclaration* node)override;
				void Visit(WfClassDeclaration* node)override;
				void Visit(WfEnumDeclaration* node)override;
				void Visit(WfStructDeclaration* node)override;
			};

			class VirtualExpressionVisitor : public Object, public WfVirtualExpression::IVisitor
			{
			public:

				// Visitor Members -----------------------------------
				void Visit(WfBindExpression* node)override;
				void Visit(WfFormatExpression* node)override;
			};

			class ModuleUsingFragmentVisitor : public Object, public WfModuleUsingFragment::IVisitor
			{
			public:

				// Visitor Members -----------------------------------
				void Visit(WfModuleUsingNameFragment* node)override;
				void Visit(WfModuleUsingWildCardFragment* node)override;
			};

		}
	}
}
#endif