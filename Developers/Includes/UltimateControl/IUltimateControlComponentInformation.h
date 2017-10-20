// filename: IUltimateControlComponentInformation.h
#pragma once
// IComponentInformation
// This is one of UltimateControl COM component's interface
#include "UltimateControl.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace UltimateControl{
	///=======================================================================
	/// Interface IComponentInformation's definition and IID
	///=======================================================================
	// {088BF8DD-4891-40c5-B226-C6C8901850B3} 
ULTIMATECONTROL_DEFINE_GUID(IID_IUltimateControlComponentInformation,0x88bf8dd, 0x4891, 0x40c5, 0xb2, 0x26, 0xc6, 0xc8, 0x90, 0x18, 0x50, 0xb3);
	//___________________________________________________________________________
	MIDL_INTERFACE("088BF8DD-4891-40C5-B226-C6C8901850B3")
	IComponentInformation : public IUnknown
	{
	    STDMETHOD_(LPCTSTR, GetDescription) (UINT a) PUREV;
	    STDMETHOD(RunSelfUintTest) (UINT options) PUREV;
       STDMETHOD(GetComponentPathFileName)(LPTSTR pszFile) PUREV;
	};
};//namespace UltimateControl
