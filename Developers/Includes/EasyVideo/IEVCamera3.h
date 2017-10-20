// filename: IEVCamera2.h
#pragma once
// IEVCamera2
// This is one of EasyVideo COM component's interface
#include "EasyVideoCOM.h" 
#include "IEVCameraControl.h"
#include "IEVCamera.h"
#include "IEVCamera2.h"
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyVideo{
	///=======================================================================
	/// Interface IEVCamera3's definition and IID
	///=======================================================================
	// {C1A32593-698E-430c-B9B3-CE591BB43BA2}
    EASYVIDEO_DEFINE_GUID(IID_IEVCamera3,0xc1a32593, 0x698e, 0x430c, 0xb9, 0xb3, 0xce, 0x59, 0x1b, 0xb4, 0x3b, 0xa2);
	//___________________________________________________________________________
	MIDL_INTERFACE("C1A32593-698E-430c-B9B3-CE591BB43BA2")
	IEVCamera3 : public IUnknown
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

//===========================================
// VideoFrameSetProcessingFunction mode
#define ModeAfterSouorce 1
#define ModeBeforeRender 0
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
		//
		//Add methonds for IEVCamera3: improve EasyVideo to work with 2 pin source filter
		STDMETHOD(PinCurWorkingID)(int PinID) PUREV;      //Set Current Working pin for interface's methods
		STDMETHOD(EnablePin)(int PinID, BOOL bl) PUREV; //bl=TRUE: Enable pin to run, bl=FALSE: disable pin without connect any down filter
		STDMETHOD_(int,GetSourceCapturePinCount)(void)  PUREV;      //Get Source Filter's out put pin count 

		
	};
};//namespace EasyVideo
