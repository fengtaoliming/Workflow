#include "HelloWorld.h"
#include "OpNot.h"
#include "OpPositive.h"
#include "OpNegative.h"
#include "OpAdd.h"
#include "OpSub.h"
#include "OpMul.h"
#include "OpDiv.h"
#include "OpMod.h"
#include "OpShl.h"
#include "OpShr.h"
#include "OpAnd.h"
#include "OpOr.h"
#include "OpXor.h"
#include "OpCompare.h"
#include "OpCompareReference.h"
#include "ListProcessing.h"
#include "MapProcessing.h"
#include "ElementInSet.h"
#include "GlobalVariable.h"
#include "RecursiveFunction.h"
#include "LetIn.h"
#include "Property.h"
#include "MethodClosure.h"
#include "StaticMethod.h"
#include "Event.h"
#include "ControlFlow.h"
#include "IfNotNull.h"
#include "ForEach.h"
#include "AnonymousLambda.h"
#include "NamedLambda.h"
#include "OrderedLambda.h"
#include "TryFinally.h"
#include "TryCatch.h"
#include "Delete.h"
#include "FailedThen.h"
#include "NewInterface.h"
#include "NewCustomInterface.h"
#include "NewCustomInterface2.h"
#include "NewCustomInterface3.h"
#include "BindSimple.h"
#include "BindComplex.h"
#include "BindFormat.h"
#include "BindCustomInterface.h"
#include "BindCustomInterface2.h"
#include "ClassField.h"
#include "CallStaticMethod.h"
#include "NestedLambda.h"
#include "ClassMethod.h"
#include "ClassCtor.h"
#include "ClassDtor.h"
#include "StructCtor.h"
#include "StructCtor2.h"
#include "EnumCtor.h"
#include "EnumCtor2.h"
#include "WorkflowHints.h"
#include "WorkflowAttributes.h"
#include "CoRawCoroutine.h"
#include "CoRawCoroutine2.h"
#include "CoRawCoroutine3.h"
#include "CoRawCoroutine4.h"
#include "CoEnum.h"
#include "CoEnum2.h"
#include "CoAsync.h"

using namespace vl;
using namespace vl::console;
using namespace vl::reflection::description;

void LoadTestCaseTypes()
{
}

TEST_CASE(HelloWorld)
{
	WString expected = L"Hello, world!";
	WString actual = ::vl_workflow_global::HelloWorld::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpNot)
{
	WString expected = L"true, -2, -3, -5, -9, 254, 65533, 4294967291, 18446744073709551607";
	WString actual = ::vl_workflow_global::OpNot::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpPositive)
{
	WString expected = L"1, 2, 4, 8, 1, 2, 4, 8";
	WString actual = ::vl_workflow_global::OpPositive::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpNegative)
{
	WString expected = L"-1, -2, -4, -8";
	WString actual = ::vl_workflow_global::OpNegative::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpAdd)
{
	WString expected = L"3, 6, 12, 3, 6, 12, 4.5";
	WString actual = ::vl_workflow_global::OpAdd::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpSub)
{
	WString expected = L"-1, -2, -4, 4294967295, 4294967294, 18446744073709551612, -1.5";
	WString actual = ::vl_workflow_global::OpSub::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpMul)
{
	WString expected = L"2, 8, 32, 2, 8, 32, 4.5";
	WString actual = ::vl_workflow_global::OpMul::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpDiv)
{
	WString expected = L"0, 0, 0, 0, 0, 0, 0.5";
	WString actual = ::vl_workflow_global::OpDiv::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpMod)
{
	WString expected = L"1, 2, 4, 1, 2, 4";
	WString actual = ::vl_workflow_global::OpMod::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpShl)
{
	WString expected = L"4, 32, 1024, 4, 32, 1024";
	WString actual = ::vl_workflow_global::OpShl::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpShr)
{
	WString expected = L"0, 0, 0, 0, 0, 0";
	WString actual = ::vl_workflow_global::OpShr::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpAnd)
{
	WString expected = L"false, false, 0, 0, 0, 0, 0, 0";
	WString actual = ::vl_workflow_global::OpAnd::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpOr)
{
	WString expected = L"true, false, 3, 6, 12, 3, 6, 12";
	WString actual = ::vl_workflow_global::OpOr::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpXor)
{
	WString expected = L"true, false, 3, 6, 12, 3, 6, 12";
	WString actual = ::vl_workflow_global::OpXor::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpCompare)
{
	WString expected = L"true, false, false, true, false, true, true, false, false, false, false, false, true, true, true, true, false, false, false, true";
	WString actual = ::vl_workflow_global::OpCompare::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OpCompareReference)
{
	WString expected = L"false, true, false, false, true, true, false, false, true, true, true";
	WString actual = ::vl_workflow_global::OpCompareReference::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(ListProcessing)
{
	WString expected = L"5, 1, 5, 6, 1, 6";
	WString actual = ::vl_workflow_global::ListProcessing::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(MapProcessing)
{
	WString expected = L"5, 1, 5, 6, 1, 6";
	WString actual = ::vl_workflow_global::MapProcessing::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(ElementInSet)
{
	WString expected = L"true, false, true, false, true, false, false, true, true, false";
	WString actual = ::vl_workflow_global::ElementInSet::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(GlobalVariable)
{
	WString expected = L"30, 10";
	WString actual = ::vl_workflow_global::GlobalVariable::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(RecursiveFunction)
{
	WString expected = L"1, 1, 2, 3, 5";
	WString actual = ::vl_workflow_global::RecursiveFunction::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(LetIn)
{
	WString expected = L"30";
	WString actual = ::vl_workflow_global::LetIn::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(Property)
{
	WString expected = L"10, 20, 10, , This is , 20, Workflow, This is Workflow";
	WString actual = ::vl_workflow_global::Property::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(MethodClosure)
{
	WString expected = L"10, 20";
	WString actual = ::vl_workflow_global::MethodClosure::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(StaticMethod)
{
	WString expected = L"1, This is one, 2, This is two";
	WString actual = ::vl_workflow_global::StaticMethod::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(Event)
{
	WString expected = L"2, 10, 20, 2, 20, 30, true, false";
	WString actual = ::vl_workflow_global::Event::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(ControlFlow)
{
	WString expected = L"55, 55, 55, 55, 55";
	WString actual = ::vl_workflow_global::ControlFlow::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(IfNotNull)
{
	WString expected = L"{1} is a list, {1:2} is not a list";
	WString actual = ::vl_workflow_global::IfNotNull::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(ForEach)
{
	WString expected = L"[1, 2, 3, 4, 5][5, 4, 3, 2, 1]";
	WString actual = ::vl_workflow_global::ForEach::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(AnonymousLambda)
{
	WString expected = L"2, 3, 3, 4";
	WString actual = ::vl_workflow_global::AnonymousLambda::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(NamedLambda)
{
	WString expected = L"1, 1, 2, 3, 5";
	WString actual = ::vl_workflow_global::NamedLambda::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(OrderedLambda)
{
	WString expected = L"2, 3, 3, 4";
	WString actual = ::vl_workflow_global::OrderedLambda::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(TryFinally)
{
	WString expected = L"3115";
	WString actual = ::vl_workflow_global::TryFinally::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(TryCatch)
{
	WString expected = L"[Test1::catch][Test2::catch][Test2::finally][Test3::catch1][Test3::finally1][Test3::catch2][Test3::finally2][Test4::finally1][Test4::finally2]";
	WString actual = ::vl_workflow_global::TryCatch::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(Delete)
{
	WString expected = L"false, false, false, false, true";
	WString actual = ::vl_workflow_global::Delete::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(FailedThen)
{
	WString expected = L"-1, 110";
	WString actual = ::vl_workflow_global::FailedThen::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(NewInterface)
{
	WString expected = L"[1, 2, 3, 4, 5][5, 4, 3, 2, 1]";
	WString actual = ::vl_workflow_global::NewInterface::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(NewCustomInterface)
{
	WString expected = L"[100][15][15]";
	WString actual = ::vl_workflow_global::NewCustomInterface::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(NewCustomInterface2)
{
	WString expected = L"[100][15][15]";
	WString actual = ::vl_workflow_global::NewCustomInterface2::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(NewCustomInterface3)
{
	WString expected = L"[100][15][15]";
	WString actual = ::vl_workflow_global::NewCustomInterface3::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(BindSimple)
{
	WString expected = L"[10][30][60]";
	WString actual = ::vl_workflow_global::BindSimple::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(BindComplex)
{
	WString expected = L"[10][30][60]";
	WString actual = ::vl_workflow_global::BindComplex::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(BindFormat)
{
	WString expected = L"[The value has changed to 10][The value has changed to 20][The value has changed to 30]";
	WString actual = ::vl_workflow_global::BindFormat::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(BindCustomInterface)
{
	WString expected = L"[1][3][6][10][15]";
	WString actual = ::vl_workflow_global::BindCustomInterface::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(BindCustomInterface2)
{
	WString expected = L"[1][3][6][10][15]";
	WString actual = ::vl_workflow_global::BindCustomInterface2::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(ClassField)
{
	WString expected = L"0, 0, 1, 2, true, false";
	WString actual = ::vl_workflow_global::ClassField::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(CallStaticMethod)
{
	WString expected = L"55";
	WString actual = ::vl_workflow_global::CallStaticMethod::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(NestedLambda)
{
	WString expected = L"[1][2][[4][5][[3, 12]]]";
	WString actual = ::vl_workflow_global::NestedLambda::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(ClassMethod)
{
	WString expected = L"[0][100][2][1][100]";
	WString actual = ::vl_workflow_global::ClassMethod::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(ClassCtor)
{
	WString expected = L"[0][0][1][0][0][2][1][2]";
	WString actual = ::vl_workflow_global::ClassCtor::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(ClassDtor)
{
	WString expected = L"[x][y][z]";
	WString actual = ::vl_workflow_global::ClassDtor::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(StructCtor)
{
	WString expected = L"21";
	WString actual = ::vl_workflow_global::StructCtor::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(StructCtor2)
{
	WString expected = L"21";
	WString actual = ::vl_workflow_global::StructCtor2::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(EnumCtor)
{
	WString expected = L"1, 2, 4, 8, 3, 1, 0";
	WString actual = ::vl_workflow_global::EnumCtor::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(EnumCtor2)
{
	WString expected = L"1, 2, 4, 8, 3, 1, 0";
	WString actual = ::vl_workflow_global::EnumCtor2::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(WorkflowHints)
{
	WString expected = L"[1][10][100][1000][2][20][1][100][3]";
	WString actual = ::vl_workflow_global::WorkflowHints::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(WorkflowAttributes)
{
	WString expected = L"((1 + 2) * (3 + 4)) = 21";
	WString actual = ::vl_workflow_global::WorkflowAttributes::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(CoRawCoroutine)
{
	WString expected = L"[+0][-0][+1][-1][+2][-2][+3][-3][+4][-4][+Enough!][-5]";
	WString actual = ::vl_workflow_global::CoRawCoroutine::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(CoRawCoroutine2)
{
	WString expected = L"[+0][-0]![*]![+2][-1]![*]![-2]";
	WString actual = ::vl_workflow_global::CoRawCoroutine2::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(CoRawCoroutine3)
{
	WString expected = L"[+0][-0]!![-1][*]";
	WString actual = ::vl_workflow_global::CoRawCoroutine3::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(CoRawCoroutine4)
{
	WString expected = L"[+0][-0][+1][-1][-2][*]";
	WString actual = ::vl_workflow_global::CoRawCoroutine4::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(CoEnum)
{
	WString expected = L"[0][1][2][3][4]";
	WString actual = ::vl_workflow_global::CoEnum::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(CoEnum2)
{
	WString expected = L"[0][1][2][1][2][3][2][3][4]";
	WString actual = ::vl_workflow_global::CoEnum2::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}

TEST_CASE(CoAsync)
{
	WString expected = L"[0][+0][0][-0]![1][+1][1][-1]!";
	WString actual = ::vl_workflow_global::CoAsync::Instance().main();
	Console::WriteLine(L"    expected : " + expected);
	Console::WriteLine(L"    actual   : " + actual);
	TEST_ASSERT(actual == expected);
}
