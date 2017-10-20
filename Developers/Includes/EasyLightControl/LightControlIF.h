// filename: LightControlIF.h
#pragma once
// ILightControl
// This is one of EasyLightControlCOM COM component's interface
#include "EasyLightControlCOM.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyLightControlCOM{
	///=======================================================================
	/// Interface ILightControl's definition and IID
	///=======================================================================
	// {42D4A1DC-3AE5-4505-833D-EA49DDA442B1} 
EASYLIGHTCONTROLCOM_DEFINE_GUID(IID_ILightControl,0x42D4A1DC, 0x3AE5, 0x4505, 0x83, 0x3D, 0xEA, 0x49, 0xDD, 0xA4, 0x42, 0xB1);
	//___________________________________________________________________________
	MIDL_INTERFACE("42D4A1DC-3AE5-4505-833D-EA49DDA442B1")
	ILightControl : public IUnknown
	{
		STDMETHOD(SetWindow) (HWND hParent, LPCTSTR title) PUREV;
		STDMETHOD(LSSetValue)(int channel, unsigned char m_nMode, unsigned short m_nMA, unsigned char m_nPulse)PUREV;
		STDMETHOD(LSGetValue)(int channel, unsigned char &m_nMode, unsigned short &m_nMA, unsigned char &m_nPulse)PUREV;
		STDMETHOD(LSReset)(void)PUREV;
		STDMETHOD(LSSetCOMPort)(LPCTSTR COMPortID)PUREV;
		STDMETHOD(LSGetTemperture)(unsigned int & temp)PUREV;
		STDMETHOD_(BOOL, IsConnected)(void)PUREV;
		/*
		STDMETHOD_(flot, LSGetTempture)(void)PUREV;
		STDMETHOD_(SendCOMPort)(int portID)PUREV;
		*/

		//
		
	    
		

	};
};//namespace EasyLightControlCOM
