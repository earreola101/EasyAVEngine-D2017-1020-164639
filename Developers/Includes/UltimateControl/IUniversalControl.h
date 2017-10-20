// filename: IUniversalControl.h
#pragma once
// IUniversalControl
// This is one of UltimateControl COM component's interface
#include "UltimateControl.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
//


#define LOG_PROC(__fnVFP) void (CALLBACK * __fnVFP) (LPCTSTR msg)


namespace UltimateControl{
	///=======================================================================
	/// Interface IUniversalControl's definition and IID
	///=======================================================================
	// {FCE83379-543E-4bc6-84B8-0DDF8ACFCF2C} 
ULTIMATECONTROL_DEFINE_GUID(IID_IUniversalControl,0xfce83379, 0x543e, 0x4bc6, 0x84, 0xb8, 0xd, 0xdf, 0x8a, 0xcf, 0xcf, 0x2c);
	//___________________________________________________________________________
	MIDL_INTERFACE("FCE83379-543E-4BC6-84B8-0DDF8ACFCF2C")
	IUniversalControl : public IUnknown
	{  
		STDMETHOD_(void, SetLogCallback)(LOG_PROC(fnVFP)) PUREV;
		STDMETHOD_(BOOL, ReportWriteByte)(BYTE ReportID, BYTE *pData, DWORD DataLen) PUREV;
		STDMETHOD_(BOOL, ReportReadByte) (BYTE ReportID, BYTE *recvDataBuf, ULONG DataLen) PUREV;
		STDMETHOD_(BOOL, GetDataArray)(BYTE RpID1, BYTE CmdID, BYTE RpID2, DWORD *pDiagData, int  DiagDataCount)PUREV;
        //
		STDMETHOD_(BOOL, ASICWriteByte)(DWORD adr, BYTE dat) PUREV;
		STDMETHOD_(BOOL, ASICReadByte)(DWORD adr, BYTE & dat) PUREV;
		STDMETHOD_(BOOL, TDEDataWrite)(BYTE* pData) PUREV;
		STDMETHOD_(BOOL, TDEDataRead)(BYTE* pData) PUREV;
		
		//		
	};
};//namespace UltimateControl
