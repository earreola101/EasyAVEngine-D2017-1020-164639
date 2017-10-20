// filename: EasyVideoCOM.h

#pragma once
#include <guiddef.h>

#ifndef INCLUDE_EasyVideoCOM
#define INCLUDE_EasyVideoCOM


///=======================================================================
/// Helper Marcos
///=======================================================================
// 

//tagVideoSamplingInfo
#define __VIDEO_FRAME_PROC_ARG (const EasyVideo::tagVideoSamplingInfo*  pVSI)
#define VIDEO_FRAME_PROC(__fnVFP) HRESULT (CALLBACK * __fnVFP) __VIDEO_FRAME_PROC_ARG
//#define VIDEO_FRAME_PROC(__fnVFP) (STDMETHODIMP) (CALLBACK * __fnVFP) __VIDEO_FRAME_PROC_ARG
#define VIDEO_FRAME_PROC_IMP(__fnVFP) STDMETHODIMP __fnVFP  __VIDEO_FRAME_PROC_ARG
///=======================================================================

#define EASYVIDEO_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define EV_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define EV_DEFINE_GUIDNAMED(n) __uuidof(struct n)     


///=======================================================================
/// EasyVideo COM Server Definition
///=======================================================================

#if defined(_UNICODE) // the client application is Unicode Character Set 
	// EasyVideo COM Component filename for Unicode Character Set 
	#define EasyVideo_MODULE_NAME "EasyVideoDRU.DLL"
	//
	//ProgID for Unicode Character Set 
	#define EasyVideoCOM_ProgID "EasyVideo.EasyVideoDRU"
	//
	// COM GUID for Unicode Character Set 
	// {A230BD25-4171-47a3-8B8D-69ADBCB66118} 
	#define  CLSID_EasyVideo_IMPLEMENT {0xa230bd25, 0x4171, 0x47a3, { 0x8b, 0x8d, 0x69, 0xad, 0xbc, 0xb6, 0x61, 0x18 } }    
	EV_DEFINE_GUIDSTRUCT("A230BD25-4171-47a3-8B8D-69ADBCB66118", CLSID_EasyVideo);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	// EasyVideo COM Component filename for Multi-Byte Character Set 
	#define EasyVideo_MODULE_NAME "EasyVideoDRM.DLL"
	//
	//ProgID for Multi-Byte Character Set 
	#define EasyVideoCOM_ProgID "EasyVideo.EasyVideoDRM"
	// 
	// COM GUID for Multi-Byte Character Set
	// {26C9173F-B158-467c-8E7E-56460DA21C56} 
	#define  CLSID_EasyVideo_IMPLEMENT {0x26c9173f, 0xb158, 0x467c, { 0x8e, 0x7e, 0x56, 0x46, 0xd, 0xa2, 0x1c, 0x56 } }
	EV_DEFINE_GUIDSTRUCT("26C9173F-B158-467c-8E7E-56460DA21C56", CLSID_EasyVideo);
#endif

#define CLSID_EasyVideo EV_DEFINE_GUIDNAMED(CLSID_EasyVideo)
//=======================================================================
//  EasyVideo PropertySet ID
//=======================================================================

// {62CE0DCD-678C-45f5-8A05-48FBE5AA903C}
// { 0x62ce0dcd, 0x678c, 0x45f5, { 0x8a, 0x5, 0x48, 0xfb, 0xe5, 0xaa, 0x90, 0x3c } }
EV_DEFINE_GUIDSTRUCT("62CE0DCD-678C-45f5-8A05-48FBE5AA903C", VideoProcAmp_PROPSETID);
#define VideoProcAmp_PROPSETID EV_DEFINE_GUIDNAMED(VideoProcAmp_PROPSETID)


// {704C828F-0668-403e-8BC1-89EFFC12BCEF}
// { 0x704c828f, 0x668, 0x403e, { 0x8b, 0xc1, 0x89, 0xef, 0xfc, 0x12, 0xbc, 0xef } }
EV_DEFINE_GUIDSTRUCT("704C828F-0668-403e-8BC1-89EFFC12BCEF", CameraControl_PROPSETID);
#define CameraControl_PROPSETID EV_DEFINE_GUIDNAMED(CameraControl_PROPSETID)


// {FCDE5EEA-9F5F-4a38-95CC-2B18DDDE5A4C}
// { 0xfcde5eea, 0x9f5f, 0x4a38, { 0x95, 0xcc, 0x2b, 0x18, 0xdd, 0xde, 0x5a, 0x4c } }
EV_DEFINE_GUIDSTRUCT("FCDE5EEA-9F5F-4a38-95CC-2B18DDDE5A4C", FrameRate_PROPSETID);
#define FrameRate_PROPSETID EV_DEFINE_GUIDNAMED(FrameRate_PROPSETID)


namespace EasyVideo{

///=======================================================================================
/// Data Types
///=======================================================================================
	typedef struct tagVideoSamplingInfo
	{
		BYTE* lpImage; // point to image memory.
		long cbBufSize; //  image buffer size.
		GUID SamplingVideoFormat; // video format for this sampling frame.
		//GUID DeviceVideoFormat; // video format for the device frame.
		SIZE size; // video resolution 
		double CurFrameRate;
	} VideoSamplingInfo, *pVideoSamplingInfo;
	//

///=======================================================================================

	class PropertyType
	{ 
	
	public:
		enum PropMode 
		{
			AUTO= 1,
			MANUAL= 2
		}PropMode ;

		PropertyType()
		{
			Reset();
		};	 
///=======================================================================================
		void Reset(void)
		{
			
			DefMax=(0);
			DefMin=(0);
			DefStep=(0);
			DefVal=(0);
			DefMode=(0);
			CurVal=(0);
			CurMode=(0);
			RtlZeroMemory(PropName,255);  
			PropID=(0);
		};

///=======================================================================================
		
		TCHAR PropName[255];
		UINT PropID; // the propery index inside the property set
		//
		long DefMax; //R: default max
		long DefMin; //R: default min 
		long DefStep;//R: default step
		long DefVal; //R: default value
		long DefMode;//R: enable or disable, auto or manual

		long CurVal; //R/W: current value
		long CurMode;//R/W: enable or disable, auto or manual, 
		//CurMode=2; //Manual mode
		//CurMode=1;//Auto mode
	};   //class PropertyType
///=======================================================================================
typedef enum ControlModeType{
			DefaultAndSetAuto=1,// set default first then set auto
			DefaultAndSetManual=2,// set default first then manual
			KeepCurValAndSetManual,// keep current value and set manual
			KeepCurValAndSetAuto   // keep current value only set auto
		} ControlModeType;

///=======================================================================================
	class VideoProcAmp//:public ControlMode
	{
	public:
		enum {
			BRIGHTNESS,                 // RW O
			CONTRAST,                   // RW O
			HUE,                        // RW O
			SATURATION,                 // RW O
			SHARPNESS,                  // RW O
			GAMMA,                      // RW O
			COLORENABLE,                // RW O
			WHITEBALANCE,               // RW O
			BACKLIGHT_COMPENSATION      // RW O
			, GAIN                      // RW O
			, DIGITAL_MULTIPLIER        // RW O
			, DIGITAL_MULTIPLIER_LIMIT  // RW O
			, WHITEBALANCE_COMPONENT    // RW O
			, POWERLINE_FREQUENCY       // RW O  

		} KSPROPERTY_VIDCAP_VIDEOPROCAMP;

	};//class VideoProcAmp

///============================================================
	class CameraControl//:public ControlMode
	{
	public:
 
		//typedef enum KSPROPERTY_VIDCAP_CAMERACONTROL{
		enum {
			PAN,                       // RW O
			TILT,                      // RW O
			ROLL,                      // RW O
			ZOOM,                      // RW O
			EXPOSURE,                  // RW O
			IRIS,                      // RW O
			FOCUS                      // RW O
			, SCANMODE                 // RW O
			, PRIVACY                  // RW O
			, PANTILT                  // RW O
			, PAN_RELATIVE             // RW O
			, TILT_RELATIVE            // RW O
			, ROLL_RELATIVE            // RW O
			, ZOOM_RELATIVE            // RW O
			, EXPOSURE_RELATIVE        // RW O
			, IRIS_RELATIVE            // RW O
			, FOCUS_RELATIVE           // RW O
			, PANTILT_RELATIVE         // RW O
			, FOCAL_LENGTH             // R  O    
			, AUTO_EXPOSURE_PRIORITY   // RW O
		} KSPROPERTY_VIDCAP_CAMERACONTROL;

	};//class CameraControl

};//namespace EasyVideo

#define VID_IGNORE NULL
#define PID_IGNORE NULL

#endif //INCLUDE_EasyVideoCOM