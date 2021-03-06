#include "../../Source/CppTypes.h"
#include "../../Source/Helper.h"

#if defined VCZH_MSVC
using namespace vl::filesystem;
#endif

void LoadTypes()
{
	LoadPredefinedTypes();
	LoadParsingTypes();
	XmlLoadTypes();
	JsonLoadTypes();
	WfLoadTypes();
	LoadCppTypes();
	TEST_ASSERT(GetGlobalTypeManager()->Load());
}

void UnloadTypes()
{
	TEST_ASSERT(GetGlobalTypeManager()->Unload());
	TEST_ASSERT(ResetGlobalTypeManager());
}

#if defined VCZH_MSVC
int wmain(int argc, wchar_t* argv[])
#elif defined VCZH_GCC
int main()
#endif
{
#if defined VCZH_MSVC
	{
		Folder folder(GetTestOutputPath());
		if (!folder.Exists())
		{
			TEST_ASSERT(folder.Create(false) == true);
		}
	}
#endif
	LoadTypes();
	unittest::UnitTest::RunAndDisposeTests();
	UnloadTypes();
	ReleaseWorkflowTable();
	ThreadLocalStorage::DisposeStorages();
#if defined VCZH_MSVC && defined VCZH_CHECK_MEMORY_LEAKS
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}
