// filename: ISCPI.h
#pragma once
// ISCPI
// This is one of UltimateSCPI COM component's interface
#include "UltimateSCPI.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace UltimateSCPI{
	///=======================================================================
	/// Interface ISCPI's definition and IID
	///=======================================================================
	// {490C087E-C805-4ed2-AC79-4C5E5706B139} 
ULTIMATESCPI_DEFINE_GUID(IID_ISCPI,0x490c087e, 0xc805, 0x4ed2, 0xac, 0x79, 0x4c, 0x5e, 0x57, 0x6, 0xb1, 0x39);
	//___________________________________________________________________________
	MIDL_INTERFACE("490C087E-C805-4ED2-AC79-4C5E5706B139")
	ISCPI : public IUnknown
	{
	    
		STDMETHOD(SCPI)(LPCTSTR szSCPICmd) PUREV; // Send out SCPI command to instrument 
	    STDMETHOD(SCPIDeviceEnum)(BOOL bFindFirst) PUREV;// if the bFindFirst=TRUE, will find first SCPI device only
		STDMETHOD(SetCommunicationControl)(LPCTSTR bcdStr)PUREV;
		STDMETHOD_(int, GetDeviceCount)(void) PUREV; //  when SCPIDeviceEnum(TRUE) then always return 0 or 1,  SCPIDeviceEnum(FALSE) can return more then 1
		//
	    STDMETHOD(GetLastInput)(LPTSTR szRet) PUREV; // input from SCPI device.
		STDMETHOD_(int, GetCOMPortID)(int EnumerattionIndex) PUREV; // apply only SCPIDeviceEnum(FALSE)
        STDMETHOD (SetCOMPortID)(int COMPortID) PUREV; // 
		STDMETHOD_(void, SetTimeout)(DWORD Timeout) PUREV; // 
		STDMETHOD_(DWORD, GetSCPICmdDurationTime)(void) PUREV; // 
		STDMETHOD( SetLTrim)(int count) PUREV; //  LTrim charactor for instrument echo value
		STDMETHOD_(bool, IsInstrumentConnected)(int COMPortID) PUREV; // 
		STDMETHOD_(int, FindFirstInstrument)(void) PUREV; // 
		STDMETHOD_(BOOL, IsCOMPortAppeared)(int COMPortID) PUREV; // 

		

		


	};
};//namespace UltimateSCPI
