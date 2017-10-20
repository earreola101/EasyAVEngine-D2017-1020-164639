// filename: IDevice.h
#pragma once
// IDevice
// This is one of UltimateControl COM component's interface
#include "UltimateControl.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace UltimateControl{
	///=======================================================================
	/// Interface IDevice's definition and IID
	///=======================================================================
	// {2585AA58-A47A-4d5e-8071-74C9B9A50CE9} 
//#ifdef _USRDLL
 ULTIMATECONTROL_DEFINE_GUID(IID_IDevice,0x2585aa58, 0xa47a, 0x4d5e, 0x80, 0x71, 0x74, 0xc9, 0xb9, 0xa5, 0xc, 0xe9);
//#endif
#define ReportIDOpenDeviceAndSetTDEMode -1  // report ID <0 open only device only
#define ReportIDOpenDeviceAndNotSetTDEMode 256 // become ReportID=-1 and don't enable TDE mode
	//___________________________________________________________________________
	MIDL_INTERFACE("2585AA58-A47A-4D5E-8071-74C9B9A50CE9")
	IDevice : public IUnknown
	{
	
		STDMETHOD_(BOOL,OpenHIDDevice)(int overlapped, USHORT USB_VID, USHORT USB_PID, int ReportID=-1, int BufLen=0) PUREV;
		STDMETHOD_(void, CloseHID)(void) PUREV;
		STDMETHOD_(BOOL,GetFirmwareVersion)(BYTE * dat) PUREV; // get MCU1 firmware version
		
		//
		//ComponentID=0: MCU, the same as GetFirmwareVersion()
		//ComponentID=1: Audio chip 
		STDMETHOD_(BOOL,GetVersion)(int ComponentID, BYTE * dat) PUREV; // get component version
		STDMETHOD_(BOOL,TDEMode)(BOOL enable) PUREV;
		STDMETHOD_(BOOL,GetVersion2)(int ComponentID, pVersion2 ver) PUREV; // get component version

 
	};
};//namespace UltimateControl
