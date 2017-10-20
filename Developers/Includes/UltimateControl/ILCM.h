// filename: ILCM.h
#pragma once
// ILCM
// This is one of UltimateControl COM component's interface
#include "UltimateControl.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace UltimateControl{
	///=======================================================================
	/// Interface ILCM's definition and IID
	///=======================================================================
	// {FA2DBE42-81F3-47cf-9279-99182367D011} 
ULTIMATECONTROL_DEFINE_GUID(IID_ILCM,0xfa2dbe42, 0x81f3, 0x47cf, 0x92, 0x79, 0x99, 0x18, 0x23, 0x67, 0xd0, 0x11);
	//___________________________________________________________________________
	MIDL_INTERFACE("FA2DBE42-81F3-47CF-9279-99182367D011")
	ILCM : public IUnknown
	{
	   
		STDMETHOD(SetPattern) (BYTE PatternID,BYTE v1=0,BYTE v2=0,BYTE v3=0) PUREV;
		 
	};
};//namespace UltimateControl
