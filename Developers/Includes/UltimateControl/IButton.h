// filename: IButton.h
#pragma once
// IButton
// This is one of UltimateControl COM component's interface
#include "UltimateControl.h" 

/* Touch Number key */
//TDE Touch key for Colossus
#define LOGI_TOUCH_KEY_HOOK_ON						 	( 0x01 )
#define LOGI_TOUCH_KEY_HOOK_OFF					 	( 0x02 )
#define LOGI_TOUCH_KEY_VOL_UP						 	( 0x03 )
#define LOGI_TOUCH_KEY_VOL_DOWN					 	( 0x04 )
/*
#define LOGI_TOUCH_KEY_LEFT							 	( 0x05 )     // from Jason
#define LOGI_TOUCH_KEY_RIGHT							 	( 0x06 ) // from Jason
*/
#define LOGI_TOUCH_KEY_LEFT							 	( 0x06 )    // Juwien@2013-0814
#define LOGI_TOUCH_KEY_RIGHT							 	( 0x05 )  // Juwien@2013-0814

#define LOGI_TOUCH_KEY_DOWN							 	( 0x07 )
#define LOGI_TOUCH_KEY_UP							 	( 0x08 )
#define LOGI_TOUCH_KEY_ZO							 	( 0x09 )
#define LOGI_TOUCH_KEY_SET							 	( 0x0A )
#define LOGI_TOUCH_KEY_MIC							 	( 0x0B )
#define LOGI_TOUCH_KEY_ZI							 	( 0x0C )
#define LOGI_TOUCH_KEY_FAR							 	( 0x0D )
#define LOGI_TOUCH_KEY_BT							 	( 0x0E )


#define KEY_PROC(__fnVFP) void (CALLBACK * __fnVFP) (DWORD TouchkeyID)
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0

namespace UltimateControl{
	///=======================================================================
	/// Interface IButton's definition and IID
	///=======================================================================
	// {C76525FC-041F-4f74-BE02-122FDEE5755E} 
ULTIMATECONTROL_DEFINE_GUID(IID_IButton,0xc76525fc, 0x41f, 0x4f74, 0xbe, 0x2, 0x12, 0x2f, 0xde, 0xe5, 0x75, 0x5e);
	//___________________________________________________________________________
	MIDL_INTERFACE("C76525FC-041F-4F74-BE02-122FDEE5755E")
	IButton : public IUnknown
	{
	    
		STDMETHOD_(void, SetKeyCallback)(KEY_PROC(fnVFP)) PUREV;
		STDMETHOD_(BOOL, TouchGetValue)(DWORD KeyCode, DWORD & KeyCapVal) PUREV;
		STDMETHOD_(BOOL,GetTouchFirmwareVersion)(BYTE * dat) PUREV;
		STDMETHOD_(BOOL, GetAllKeysStatus)(DWORD & KeyVal) PUREV;
	};
};//namespace UltimateControl
