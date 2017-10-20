// filename: EVBayer3IF.h
#pragma once
// IEVBayer3
// This is one of EasyVideo COM component's interface
#include "EasyVideoCOM.h"

#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0

namespace EasyVideo{
	///=======================================================================
	/// Interface IEVBayer3's definition and IID
	///=======================================================================
	// {29D0C37D-8E43-4223-81BB-F933CD5CD440} 
EASYVIDEO_DEFINE_GUID(IID_IEVBayer3,0x29D0C37D, 0x8E43, 0x4223, 0x81, 0xBB, 0xF9, 0x33, 0xCD, 0x5C, 0xD4, 0x40);
	//___________________________________________________________________________
	MIDL_INTERFACE("29D0C37D-8E43-4223-81BB-F933CD5CD440")
	IEVBayer3 : public IUnknown
	{
        STDMETHOD(GetBayer)(bool&bEnable,int &BitsPerPixel,int &PacketFormat)PUREV;
		STDMETHOD(SetBayer)(bool bEnable,int  BitsPerPixel,int  PacketFormat)PUREV;
		STDMETHOD_(void, SetAlwaysTo08bits)(bool bAlwaysTo08Bits)PUREV;	
		STDMETHOD(SetBayerConfiguration)(LPCTSTR BayerConfiguration) PUREV;
	};

};//namespace EasyVideo






