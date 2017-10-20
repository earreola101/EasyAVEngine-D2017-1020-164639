// filename: IOneWire.h
#pragma once
// IOneWire
// This is one of UltimateControl COM component's interface
#include "UltimateControl.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace UltimateControl{
	///=======================================================================
	/// Interface IOneWire's definition and IID
	///=======================================================================
	// {974C4EB0-86AE-4e62-8931-97507E12AEF8} 
ULTIMATECONTROL_DEFINE_GUID(IID_IOneWire,0x974c4eb0, 0x86ae, 0x4e62, 0x89, 0x31, 0x97, 0x50, 0x7e, 0x12, 0xae, 0xf8);
	//___________________________________________________________________________
	MIDL_INTERFACE("974C4EB0-86AE-4E62-8931-97507E12AEF8")
	IOneWire : public IUnknown
	{
	    STDMETHOD_(LPCTSTR, GetDescription) (UINT a)PUREV;
	    STDMETHOD(RunSelfUintTest) (UINT options) PUREV;
	};
};//namespace UltimateControl
