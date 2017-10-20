// filename: IDevice.h
#pragma once
// IDevice
// This is one of EasyPTMotor COM component's interface
#include "EasyPTMotor.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyPTMotor{
	///=======================================================================
	/// Interface IDevice's definition and IID
	///=======================================================================
	// {36C3F378-B547-45ff-B134-0D081DE2633E} 
EASYPTMOTOR_DEFINE_GUID(IID_IDevice,0x36c3f378, 0xb547, 0x45ff, 0xb1, 0x34, 0xd, 0x8, 0x1d, 0xe2, 0x63, 0x3e);
	//___________________________________________________________________________
	MIDL_INTERFACE("36C3F378-B547-45FF-B134-0D081DE2633E")
	IDevice : public IUnknown
	{
	    STDMETHOD_(bool, ConnectToDevice)(LPCTSTR aDeviceName, WORD vid=0, WORD pid=0) PUREV;
		STDMETHOD_(BOOL, GetCmdStatus)(BYTE & b) PUREV;
		STDMETHOD_(BOOL, XUDIGetSelector11)(BYTE *pB) PUREV;
		STDMETHOD_(BOOL, XUDIGetAll)(LPTSTR pDI) PUREV;
		STDMETHOD_(BOOL, XUEepromBytesRead)(WORD adr, BYTE *pB, int DataSize) PUREV;
		STDMETHOD_(BOOL, XUEepromBytesWrite)(WORD adr, BYTE *pB, int DataSize) PUREV;
		
		
		//
	};
};//namespace EasyPTMotor
