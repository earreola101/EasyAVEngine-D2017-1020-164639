// filename: IDeviceControl.h
#pragma once
// IDeviceControl
// This is one of EasyControl COM component's interface
#include "EasyControl.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyControl{
	///=======================================================================
	/// Interface IDeviceControl's definition and IID
	///=======================================================================
	// {E4028058-2647-416c-80A6-A0B1A3425A75} 
EASYCONTROL_DEFINE_GUID(IID_IDeviceControl,0xe4028058, 0x2647, 0x416c, 0x80, 0xa6, 0xa0, 0xb1, 0xa3, 0x42, 0x5a, 0x75);
	//___________________________________________________________________________
	MIDL_INTERFACE("E4028058-2647-416C-80A6-A0B1A3425A75")
	IDeviceControl : public IUnknown
	{
	
		
		STDMETHOD_(BOOL, IsDeviceConnected) (void) PUREV;
		STDMETHOD_(UINT, DeviceStringGetCount) (void) PUREV;
		STDMETHOD(DeviceStringGet) (UINT ItemID, LPTSTR str) PUREV;
		STDMETHOD(DeviceStringNameGet) (UINT ItemID, LPTSTR str) PUREV;
		STDMETHOD_(BOOL, RegisterReadByte)( DWORD address, BYTE *pValue) PUREV;
		STDMETHOD_(BOOL, RegisterWriteByte)( DWORD address, BYTE value) PUREV;

		STDMETHOD_(BOOL, RegisterReadBitFieldInByte)(
		DWORD				address,
		size_t				startBit,
		size_t				endBit,
		BYTE			  * pValue
		) PUREV;
		STDMETHOD_(BOOL, RegisterWriteBitFieldInByte)(
		DWORD				address,
		size_t				startBit,
		size_t				endBit,
		BYTE				value
		) PUREV;

	    STDMETHOD_(BOOL, EepromRead)( DWORD address, DWORD DataSize, BYTE * pValue) PUREV;
        STDMETHOD_(BOOL, EepromWrite)( DWORD address, DWORD DataSize, BYTE * pValue) PUREV;
		STDMETHOD_(BOOL, ConnectByPnpId)(USHORT vendorID, USHORT productID) PUREV;
		
	};
};//namespace EasyControl

