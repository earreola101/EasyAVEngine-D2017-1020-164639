// filename: IEVBayer2.h
#pragma once
// IEVBayer2
// This is one of EasyVideo COM component's interface
#include "EasyVideoCOM.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyVideo{
	///=======================================================================
	/// Interface IEVBayer2's definition and IID
	///=======================================================================
	// {E5A62567-8BC9-4087-B7E4-081AC704C95A} 
EASYVIDEO_DEFINE_GUID(IID_IEVBayer2,0xe5a62567, 0x8bc9, 0x4087, 0xb7, 0xe4, 0x8, 0x1a, 0xc7, 0x4, 0xc9, 0x5a);
	//___________________________________________________________________________
	MIDL_INTERFACE("E5A62567-8BC9-4087-B7E4-081AC704C95A")
	IEVBayer2 : public IUnknown
	{
	    STDMETHOD(GetBayer)(bool&bEnable,int &BitsPerPixel,int &PacketFormat)PUREV;
		STDMETHOD(SetBayer)(bool bEnable,int  BitsPerPixel,int  PacketFormat)PUREV;
		STDMETHOD_(void, SetAlwaysTo08bits)(bool bAlwaysTo08Bits)PUREV;

	};
};//namespace EasyVideo





