// filename: IEVCameraControl.h
#pragma once
// IEVCameraControl.h
#include "EasyVideoCOM.h" 
#ifndef INCLUDE_IEVCameraControl
#define INCLUDE_IEVCameraControl
namespace EasyVideo{
	///=======================================================================
	/// Interface IIEVCameraControl's definition and IID
	///=======================================================================
	// {54EAB41D-77AC-4d65-964B-A656B563F56A} 
	static const IID IID_IEVCameraControl = { 0x54eab41d, 0x77ac, 0x4d65, { 0x96, 0x4b, 0xa6, 0x56, 0xb5, 0x63, 0xf5, 0x6a } };
	//___________________________________________________________________________
	MIDL_INTERFACE("54EAB41D-77AC-4D65-964B-A656B563F56A")
	IEVCameraControl : public IUnknown
	{
	    STDMETHOD_(LPCTSTR, GetDescription) (UINT a) = 0;
	    STDMETHOD(RunSelfUintTest) (UINT options) = 0;
	    STDMETHOD_(UINT,Count) (void) = 0;
	    
	};
};//namespace EasyVideoCOM
#endif //INCLUDE_IEVCameraControl