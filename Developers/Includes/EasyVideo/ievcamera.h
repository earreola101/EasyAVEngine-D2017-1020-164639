// filename: IEVCamera.h
#pragma once
// IEVCamera.h
#include "EasyVideoCOM.h" 
#include "IEVCameraControl.h"

#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyVideo{
	enum  SaveVideoFrameModeEnum
	{
		FrameAfterSource=0,
		FrameAfterSourceWithBayerFilter4Sonix,
		FrameBeforeRender,
	};
	//=============================================================================
	// Define those video format is supported by EasyVideo
	//=============================================================================
	// BR08 MediaType
	// {38305242-0000-0010-8000-00AA00389B71} BR08
	static const GUID MEDIASUBTYPE_BR08 = {0x38305242, 0x0000, 0x0010,  0x80, 0x00, 0x00, 0xaa, 0x0, 0x38, 0x9b, 0x71};
	//
	// BR10 MediaType
	// {30315242-0000-0010-8000-00AA00389B71} BR10
	static const GUID MEDIASUBTYPE_BR10 = {0x30315242, 0x0000, 0x0010,  0x80, 0x00, 0x00, 0xaa, 0x0, 0x38, 0x9b, 0x71};
	//
	// BR12 MediaType
	// {32315242-0000-0010-8000-00AA00389B71} BR12
	static const GUID MEDIASUBTYPE_BR12 = {0x32315242, 0x0000, 0x0010,  0x80, 0x00, 0x00, 0xaa, 0x0, 0x38, 0x9b, 0x71};
	//
	// YUY2 MediaType
	// 32595559-0000-0010-8000-00AA00389B71  'YUY2' == MEDIASUBTYPE_YUY2
	static const GUID MEDIASUBTYPE_YUY2={0x32595559, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71};
	//
	// I420 MediaType
	static const GUID MEDIASUBTYPE_I420 = {0x30323449, 0x0000, 0x0010,  0x80, 0x00, 0x00, 0xaa, 0x0, 0x38, 0x9b, 0x71};
	//
	// RGB24 MediaType
	// e436eb7d-524f-11ce-9f53-0020af0ba770 
	static const GUID MEDIASUBTYPE_RGB24={0xe436eb7d, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70};
	//
	// H.264 MediaType
	// 34363248-0000-0010-8000-00AA00389B71
	static const GUID MEDIASUBTYPE_H264 = {0x34363248, 0x0000, 0x0010,  0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71};
	//
	// MJPG MediaType
	// 47504A4D-0000-0010-8000-00AA00389B71  
	static const GUID MEDIASUBTYPE_MJPG = {0x47504A4D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9b, 0x71};
	///=======================================================================
	/// Interface IEVCamera's definition and IID
	///=======================================================================
	// {000983B2-CC82-4215-B4A8-5ED7FA5F9177} 
	//static const IID IID_IEVCamera = { 0x983b2, 0xcc82, 0x4215, { 0xb4, 0xa8, 0x5e, 0xd7, 0xfa, 0x5f, 0x91, 0x77 } };
	EASYVIDEO_DEFINE_GUID(IID_IEVCamera,0x983b2, 0xcc82, 0x4215, 0xb4, 0xa8, 0x5e, 0xd7, 0xfa, 0x5f, 0x91, 0x77);
	//
	/*
	EV_DEFINE_GUIDSTRUCT("000983B2-CC82-4215-B4A8-5ED7FA5F9177", IID_IEVCamera);
	#define IID_IEVCamera EV_DEFINE_GUIDNAMED(IID_IEVCamera)
	*/
	//___________________________________________________________________________
	//
	MIDL_INTERFACE("000983B2-CC82-4215-B4A8-5ED7FA5F9177")
IEVCamera : public IUnknown
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
		//=======================================================================
		// Video Formats and Resolutions 
		STDMETHOD(FormatSet) (GUID VideoFormat, UINT  w,UINT h) PUREV;
		STDMETHOD(FormatGet) (UINT FormatIndex, GUID &FormatGuid )PUREV;  
		STDMETHOD_(UINT,FormatGetCount) (void) PUREV;  
		STDMETHOD(FormatGetCurrent) (GUID& VideoFormat, UINT& w,UINT& h) PUREV;
		//=======================================================================
		// Resolution   
		STDMETHOD(ResolutionGet) (GUID VideoFormat,UINT ResolutionIndex, SIZE &Resolution )PUREV;  
		STDMETHOD_(UINT,ResolutionGetCount)  (GUID VideoFormat)PUREV; 
		//=======================================================================
		STDMETHOD(VideoFrameSave) ( SaveVideoFrameModeEnum SampleLocation, LPCTSTR pszFullFilename)PUREV;
		STDMETHOD(VideoFrameSetProcessingFunction) (VIDEO_FRAME_PROC(fnVFP),int mode)PUREV; 
		// Camera Device
		STDMETHOD(Attach) (WORD VID,WORD PID,LPTSTR pszFriendlyName=NULL,LPTSTR pszReserved=NULL) PUREV; 
		// others
		STDMETHOD_(EasyVideo::IEVCameraControl*, CameraControl) (void) PUREV;
		STDMETHOD_(LPCTSTR, GetDescription) (UINT a) PUREV;
		STDMETHOD(RunSelfUintTest) (UINT options) PUREV;
	};

};//namespace EasyVideo
