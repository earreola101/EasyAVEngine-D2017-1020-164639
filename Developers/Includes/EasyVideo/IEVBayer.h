// filename: IEVBayer.h
#pragma once
// IEVBayer.h
#include "EasyVideoCOM.h" 
namespace EasyVideo{
	///=======================================================================
	/// Interface IEVBayer's definition and IID
	///=======================================================================
	// {F9A22974-0147-42c3-91F1-1F91D0BECA39} 
	EASYVIDEO_DEFINE_GUID(IID_IEVBayer,0xf9a22974, 0x147, 0x42c3, 0x91, 0xf1, 0x1f, 0x91, 0xd0, 0xbe, 0xca, 0x39);
	//___________________________________________________________________________
	MIDL_INTERFACE("F9A22974-0147-42C3-91F1-1F91D0BECA39")
IEVBayer : public IUnknown
	{
		STDMETHOD(GetBayer)(bool&bEnable,int &BitsPerPixel,int &PacketFormat)=0;
		STDMETHOD(SetBayer)(bool bEnable,int  BitsPerPixel,int  PacketFormat)=0;
	};

};//namespace EasyVideo

