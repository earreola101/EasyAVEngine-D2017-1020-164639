// filename: IAudioDeviceControl.h
#pragma once
// IAudioDeviceControl

#include "EasyControl.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyControl{

  enum eAccessType
	  {
		  Read=0x01,
		  Write=0x02,
		  ReadWrite=0x03,
	  };
		
enum eAudioUIStatus
	{
      ButtonMicMute,
	  ButtonHookON,
	  ButtonHookOFF,
	  ButtonVolumeUp,
	  ButtonVolumeDown,
	  LedGetMicMute,
	  LedGetHook,
	  LedSetMicMute,
	  eAudioStatusCount,
	};

#define UnknownStatus -1

	///=======================================================================
	/// Interface IAudioDeviceControl's definition and IID
	///=======================================================================
	// {B043D310-918D-4341-9D5E-C5FF03A47589} 
EASYCONTROL_DEFINE_GUID(IID_IAudioDeviceControl,0xb043d310, 0x918d, 0x4341, 0x9d, 0x5e, 0xc5, 0xff, 0x3, 0xa4, 0x75, 0x89);
	//___________________________________________________________________________
	MIDL_INTERFACE("B043D310-918D-4341-9D5E-C5FF03A47589")
	IAudioDeviceControl : public IUnknown
	{
	   
		STDMETHOD_(BOOL,AudioDspDisable)(void)PUREV;
		STDMETHOD_(BOOL,MuteLedSet)(BOOL bValue)PUREV;
		STDMETHOD_(BOOL,GetStatus)(UINT id)PUREV;
		STDMETHOD_(BOOL,GetStatus2String)(UINT id, LPTSTR str)PUREV;
		STDMETHOD_(BOOL,GetStatusName)(UINT id,  LPTSTR str)PUREV;
		STDMETHOD_(long,GetStatusAddress)(UINT id)PUREV;
		STDMETHOD_(BYTE,GetStatusBitPosition)(UINT id)PUREV;
		STDMETHOD_(BYTE,GetStatusRWType)(UINT id)PUREV;
		/*
		STDMETHOD_(BOOL,SetDeviceMappingID)(GUID ID)PUREV;
		*/

	};
};//namespace EasyControl
