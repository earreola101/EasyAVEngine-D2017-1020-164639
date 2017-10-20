// filename: ILED.h
#pragma once
// ILED
// This is one of UltimateControl COM component's interface
#include "UltimateControl.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace UltimateControl{

#define LED_RED   0x01
#define LED_BLUE  0x02
#define LED_BLINK 0x03
#define LED_OFF   0x00
	///=======================================================================
	/// Interface ILED's definition and IID
	///=======================================================================
	// {BF9E291E-9B09-4a67-8D04-AFCED9E32D94} 
ULTIMATECONTROL_DEFINE_GUID(IID_ILED,0xbf9e291e, 0x9b09, 0x4a67, 0x8d, 0x4, 0xaf, 0xce, 0xd9, 0xe3, 0x2d, 0x94);
	//___________________________________________________________________________
	MIDL_INTERFACE("BF9E291E-9B09-4A67-8D04-AFCED9E32D94")
	ILED : public IUnknown
	{
	
		STDMETHOD(SetStatus) (BYTE status) PUREV;
		
	};
};//namespace UltimateControl
