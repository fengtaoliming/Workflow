/***********************************************************************
Generated from ../Resources/Codegen/TypeTesting.txt
***********************************************************************/

#include "TypeTesting.h"

/***********************************************************************
Global Variables and Functions
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_TypeTesting)
	vl_workflow_global::TypeTesting instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_TypeTesting)

namespace vl_workflow_global
{
	::vl::WString TypeTesting::main()
	{
		throw 0;
	}

	TypeTesting& TypeTesting::Instance()
	{
		return Getvl_workflow_global_TypeTesting().instance;
	}
}

