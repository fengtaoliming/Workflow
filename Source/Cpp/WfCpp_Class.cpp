#include "WfCpp.h"

namespace vl
{
	namespace workflow
	{
		namespace cppcodegen
		{
			using namespace collections;
			using namespace reflection;
			using namespace reflection::description;
			using namespace analyzer;

/***********************************************************************
WfGenerateClassMemberDeclVisitor
***********************************************************************/

			class WfGenerateClassMemberDeclVisitor : public Object, public WfDeclaration::IVisitor
			{
			public:
				WfCppConfig*				config;
				stream::StreamWriter&		writer;
				Ptr<WfClassDeclaration>		classDecl;
				Ptr<WfClassMember>			classMember;
				WString						prefix;

				WfGenerateClassMemberDeclVisitor(WfCppConfig* _config, stream::StreamWriter& _writer, Ptr<WfClassDeclaration> _classDecl, Ptr<WfClassMember> _classMember, const WString& _prefix)
					:config(_config)
					, writer(_writer)
					, classDecl(_classDecl)
					, classMember(_classMember)
					, prefix(_prefix)
				{
				}

				void Visit(WfNamespaceDeclaration* node)override
				{
				}

				void Visit(WfFunctionDeclaration* node)override
				{
					auto methodInfo = dynamic_cast<IMethodInfo*>(config->manager->declarationMemberInfos[node].Obj());
					writer.WriteString(prefix);
					config->WriteFunctionHeader(writer, methodInfo, config->ConvertName(node->name.value), true);
					writer.WriteLine(L";");
				}

				void Visit(WfVariableDeclaration* node)override
				{
					auto scope = config->manager->nodeScopes[node].Obj();
					auto symbol = scope->symbols[node->name.value][0];
					auto typeInfo = symbol->typeInfo;
					writer.WriteString(prefix + config->ConvertType(typeInfo.Obj()) + L" " + config->ConvertName(node->name.value));
					auto defaultValue = config->DefaultValue(typeInfo.Obj());
					if (defaultValue != L"")
					{
						writer.WriteString(L" = " + defaultValue);
					}
					writer.WriteLine(L";");
				}

				void Visit(WfEventDeclaration* node)override
				{
					auto eventInfo = dynamic_cast<IEventInfo*>(config->manager->declarationMemberInfos[node].Obj());
					auto typeInfo = eventInfo->GetHandlerType();
					writer.WriteString(prefix);

					writer.WriteString(L"::vl::Event<void(");
					vint count = typeInfo->GetGenericArgumentCount();
					for (vint i = 1; i < count; i++)
					{
						if (i > 1) writer.WriteString(L", ");
						writer.WriteString(config->ConvertType(typeInfo->GetGenericArgument(i)));
					}
					writer.WriteLine(L")> " + config->ConvertName(node->name.value) + L";");
				}

				void Visit(WfPropertyDeclaration* node)override
				{
				}

				void Visit(WfConstructorDeclaration* node)override
				{
					auto methodInfo = dynamic_cast<IMethodInfo*>(config->manager->declarationMemberInfos[node].Obj());
					writer.WriteString(prefix);
					config->WriteFunctionHeader(writer, methodInfo, config->ConvertName(classDecl->name.value), false);
					writer.WriteLine(L";");
				}

				void Visit(WfDestructorDeclaration* node)override
				{
					writer.WriteLine(prefix + L"~" + config->ConvertName(classDecl->name.value) + L"();");
				}

				void Visit(WfClassDeclaration* node)override
				{
				}

				void Visit(WfEnumDeclaration* node)override
				{
				}

				void Visit(WfStructDeclaration* node)override
				{
				}
			};

			void GenerateClassMemberDecl(WfCppConfig* config, stream::StreamWriter& writer, Ptr<WfClassDeclaration> classDecl, Ptr<WfClassMember> member, const WString& prefix)
			{
				WfGenerateClassMemberDeclVisitor visitor(config, writer, classDecl, member, prefix);
				member->declaration->Accept(&visitor);
			}

/***********************************************************************
WfGenerateClassMemberImplVisitor
***********************************************************************/

			class WfGenerateClassMemberImplVisitor : public Object, public WfDeclaration::IVisitor
			{
			public:
				WfCppConfig*				config;
				stream::StreamWriter&		writer;
				Ptr<WfClassDeclaration>		classDecl;
				Ptr<WfClassMember>			classMember;
				WString						prefix;
				bool						printableMember = false;

				WfGenerateClassMemberImplVisitor(WfCppConfig* _config, stream::StreamWriter& _writer, Ptr<WfClassDeclaration> _classDecl, Ptr<WfClassMember> _classMember, const WString& _prefix)
					:config(_config)
					, writer(_writer)
					, classDecl(_classDecl)
					, classMember(_classMember)
					, prefix(_prefix)
				{
				}

				void Visit(WfNamespaceDeclaration* node)override
				{
				}

				void Visit(WfFunctionDeclaration* node)override
				{
					printableMember = true;
					auto methodInfo = dynamic_cast<IMethodInfo*>(config->manager->declarationMemberInfos[node].Obj());
					writer.WriteString(prefix);
					config->WriteFunctionHeader(writer, methodInfo, config->GetClassBaseName(classDecl) + L"::" + config->ConvertName(node->name.value), true);
					writer.WriteLine(L"");

					writer.WriteLine(prefix + L"{");
					writer.WriteLine(prefix + L"\tthrow 0;");
					writer.WriteLine(prefix + L"}");
				}

				void Visit(WfVariableDeclaration* node)override
				{
				}

				void Visit(WfEventDeclaration* node)override
				{
				}

				void Visit(WfPropertyDeclaration* node)override
				{
				}

				void Visit(WfConstructorDeclaration* node)override
				{
					printableMember = true;
					auto methodInfo = dynamic_cast<IMethodInfo*>(config->manager->declarationMemberInfos[node].Obj());
					writer.WriteString(prefix);
					config->WriteFunctionHeader(writer, methodInfo, config->GetClassBaseName(classDecl) + L"::" + config->ConvertName(classDecl->name.value), false);
					writer.WriteLine(L"");

					writer.WriteLine(prefix + L"{");
					writer.WriteLine(prefix + L"\tthrow 0;");
					writer.WriteLine(prefix + L"}");
				}

				void Visit(WfDestructorDeclaration* node)override
				{
					printableMember = true;
					writer.WriteLine(prefix + config->GetClassBaseName(classDecl) + L"::~" + config->ConvertName(classDecl->name.value) + L"()");

					writer.WriteLine(prefix + L"{");
					writer.WriteLine(prefix + L"\tthrow 0;");
					writer.WriteLine(prefix + L"}");
				}

				void Visit(WfClassDeclaration* node)override
				{
				}

				void Visit(WfEnumDeclaration* node)override
				{
				}

				void Visit(WfStructDeclaration* node)override
				{
				}
			};

			bool GenerateClassMemberImpl(WfCppConfig* config, stream::StreamWriter& writer, Ptr<WfClassDeclaration> classDecl, Ptr<WfClassMember> member, const WString& prefix)
			{
				WfGenerateClassMemberImplVisitor visitor(config, writer, classDecl, member, prefix);
				member->declaration->Accept(&visitor);
				return visitor.printableMember;
			}
		}
	}
}