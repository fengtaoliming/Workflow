/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/StructCtor2.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "StructCtor2.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::StructCtor2::
#define GLOBAL_NAME ::vl_workflow_global::StructCtor2::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::StructCtor2::Instance()
#define USERIMPL(...)

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_StructCtor2)
	vl_workflow_global::StructCtor2 instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_StructCtor2)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::vint32_t StructCtor2::Do(::Point p)
	{
		return (p.x + p.y);
	}

	::vl::WString StructCtor2::main()
	{
		auto a = [&](){ ::Point __vwsn_temp__; __vwsn_temp__.x = 1; __vwsn_temp__.y = 2; return __vwsn_temp__; }();
		auto b = [&](){ ::Point __vwsn_temp__; __vwsn_temp__.x = 3; __vwsn_temp__.y = 4; return __vwsn_temp__; }();
		return ::vl::__vwsn::ToString(((GLOBAL_NAME Do(a) + GLOBAL_NAME Do(b)) + GLOBAL_NAME Do([&](){ ::Point __vwsn_temp__; __vwsn_temp__.x = 5; __vwsn_temp__.y = 6; return __vwsn_temp__; }())));
	}

	StructCtor2& StructCtor2::Instance()
	{
		return Getvl_workflow_global_StructCtor2().instance;
	}
}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ
#undef USERIMPL

/***********************************************************************
Reflection
***********************************************************************/

namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			IMPL_CPP_TYPE_INFO(Point)

#define _ ,
			BEGIN_STRUCT_MEMBER(::Point)
				STRUCT_MEMBER(x)
				STRUCT_MEMBER(y)
				STRUCT_MEMBER(z)
			END_STRUCT_MEMBER(::Point)

#undef _
			class StructCtor2TypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::Point)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif

			bool LoadStructCtor2Types()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<StructCtor2TypeLoader>());
				}
#endif
				return false;
			}
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
