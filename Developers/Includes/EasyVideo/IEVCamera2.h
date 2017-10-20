// filename: IEVCamera2.h
#pragma once
// IEVCamera2
// This is one of EasyVideo COM component's interface
#include "EasyVideoCOM.h" 
#include "IEVCameraControl.h"
#include "IEVCamera.h"
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyVideo{
	///=======================================================================
	/// Interface IEVCamera2's definition and IID
	///=======================================================================
	// {6F690287-4DA5-42ad-9BBC-8071A9F45284} 
EASYVIDEO_DEFINE_GUID(IID_IEVCamera2,0x6f690287, 0x4da5, 0x42ad, 0x9b, 0xbc, 0x80, 0x71, 0xa9, 0xf4, 0x52, 0x84);
	//___________________________________________________________________________
	MIDL_INTERFACE("6F690287-4DA5-42AD-9BBC-8071A9F45284")
	IEVCamera2 : public IUnknown
	{
	    STDMETHOD_(bool, IsDeviceConnected)(void)PUREV;  // Check is there a device connect with this CameraIndex. 
		STDMETHOD_(bool, IsPreviewing)(void)PUREV;    
		STDMETHOD(PreviewStart) (void) PUREV;
		STDMETHOD(PreviewStop) (void) PUREV;
		STDMETHOD(PreviewWindowSet) (HWND hwnd) PUREV;
		STDMETHOD(PreviewStyleSet) (ULONG PreviewStyle) PUREV;
		// Camera's general properties
		STDMETHOD(GetPID) (WORD& pid) PUREV;
		STDMETHOD(GetVID) (WORD& vid) PUREV;
		STDMETHOD(GetFriendlyName) ( LPTSTR pszFriendlyName) PUREV;
		//Get Set Camera Properties
		STDMETHOD_(UINT, PropertyGetCount)(GUID PropertySetGUID)PUREV;
		STDMETHOD(PropertyGet)(GUID PropertySetGUID, long PropertyID, PropertyType &pv)PUREV;
		STDMETHOD(PropertySet)(GUID PropertySetGUID, long PropertyID, PropertyType &pv)PUREV;
		STDMETHOD(PropertySetDefault)(GUID PropertySetGUID,ControlModeType ModeSet)PUREV;
		STDMETHOD(PropertyToStrring)(PropertyType &pv, LPTSTR pszPropStr)PUREV;
		// Get/Set Frame Rate 
		STDMETHOD(FrameRateSet)(double FrameRate)PUREV;
		STDMETHOD(FrameRateGet)(double &FrameRate)PUREV;
		//
		// Video Formats and Resolutions 
		STDMETHOD(FormatSet) (GUID VideoFormat, UINT  w,UINT h) PUREV;
		STDMETHOD(FormatGet) (UINT FormatIndex, GUID &FormatGuid )PUREV;  
		STDMETHOD_(UINT,FormatGetCount) (void) PUREV;  
		STDMETHOD(FormatGetCurrent) (GUID& VideoFormat, UINT& w,UINT& h) PUREV;
		//
		// Resolution   
		STDMETHOD(ResolutionGet) (GUID VideoFormat,UINT ResolutionIndex, SIZE &Resolution )PUREV;  
		STDMETHOD_(UINT,ResolutionGetCount)  (GUID VideoFormat)PUREV; 
		//
		STDMETHOD(VideoFrameSave) ( SaveVideoFrameModeEnum SampleLocation, LPCTSTR pszFullFilename)PUREV;
		STDMETHOD(VideoFrameSetProcessingFunction) (VIDEO_FRAME_PROC(fnVFP),int mode)PUREV; 
		//
		// Camera Device
		STDMETHOD(Attach) (WORD VID,WORD PID,LPTSTR pszFriendlyName=NULL,LPTSTR pszReserved=NULL) PUREV; 
		// Others
		STDMETHOD_(EasyVideo::IEVCameraControl*, CameraControl) (void) PUREV;
		STDMETHOD_(LPCTSTR, GetDescription) (UINT a) PUREV;
		STDMETHOD(RunSelfUintTest) (UINT options) PUREV;
		//Add methond for IEVCamera2
		STDMETHOD(OpenPropertyPage) (int type, HWND wnd) PUREV; 
		//STDMETHOD(GetPreviewResolution) (GUID &vf,int &width,int &height) PUREV; 
		
	};
};//namespace EasyVideo
