/***********************************************************************
Generated from ../Resources/Codegen/BindCustomInterface.txt
***********************************************************************/

#include "BindCustomInterface.h"

/***********************************************************************
Global Variables and Functions
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindCustomInterface)
	vl_workflow_global::BindCustomInterface instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.s = L"";
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindCustomInterface)

namespace vl_workflow_global
{
	::vl::Ptr<::vl::reflection::description::IValueSubscription> BindCustomInterface::Bind(::vl::Ptr<::ISummer> summer)
	{
		throw 0;
	}

	void BindCustomInterface::Execute(::vl::Ptr<::IAdder> adder)
	{
		throw 0;
	}

	::vl::WString BindCustomInterface::main()
	{
		throw 0;
	}

	BindCustomInterface& BindCustomInterface::Instance()
	{
		return Getvl_workflow_global_BindCustomInterface().instance;
	}








}

/***********************************************************************
Class (::ISummer)
***********************************************************************/

::vl::vint32_t ISummer::GetSum()
{
	throw 0;
}

/***********************************************************************
Class (::IAdder)
***********************************************************************/

void IAdder::Add(::vl::vint32_t value)
{
	throw 0;
}

