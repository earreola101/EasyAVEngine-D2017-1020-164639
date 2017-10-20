// filename: UltimateControl.h
#pragma once
#include <guiddef.h>
///=======================================================================
/// Helper Marcos
///=======================================================================
// 
#define ULTIMATECONTROL_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define ULTIMATECONTROL_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define ULTIMATECONTROL_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// UltimateControl COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	//
	//ProgID for Unicode Character Set 
	#define UltimateControl_ProgID "UltimateControl.UltimateControlDRU"
	//
	// COM GUID for Unicode Character Set 
   // {D4613DFE-EC79-4730-B2DE-57A8630ED753} 
   #define  CLSID_UltimateControl_IMPLEMENT   { 0xd4613dfe, 0xec79, 0x4730, { 0xb2, 0xde, 0x57, 0xa8, 0x63, 0xe, 0xd7, 0x53 } }    
	ULTIMATECONTROL_DEFINE_GUIDSTRUCT("D4613DFE-EC79-4730-B2DE-57A8630ED753", CLSID_UltimateControl);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	//
	//ProgID for Multi-Byte Character Set 
	#define UltimateControl_ProgID "UltimateControl.UltimateControlDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {499ADDF1-970C-4097-9B92-27A780F27FBB} 
   #define  CLSID_UltimateControl_IMPLEMENT   { 0x499addf1, 0x970c, 0x4097, { 0x9b, 0x92, 0x27, 0xa7, 0x80, 0xf2, 0x7f, 0xbb } }    
	ULTIMATECONTROL_DEFINE_GUIDSTRUCT("499ADDF1-970C-4097-9B92-27A780F27FBB", CLSID_UltimateControl);
///====================================================================================================================
#endif
#define CLSID_UltimateControl ULTIMATECONTROL_DEFINE_GUIDNAMED(CLSID_UltimateControl)
#define USING_UltimateControl

//___________________________________________________________________________________
typedef struct __Version__
{
	WORD build;	
	BYTE major;
	BYTE minor;	
} Version, *pVersion;
//___________________________________________________________________________________

typedef struct __Version2__
{
	WORD build;	
	BYTE minor;	
	BYTE major;
} Version2, *pVersion2;


typedef struct __VersionDSP__
{
	BYTE major;
	BYTE minor;
	WORD build;
	
} VersionDSP, *pVersionDSP;

//
///=======================================================================
/// Interfaces Definition 
///=======================================================================
#if defined(USING_UltimateControl_ComponentInformation) || defined(USING_UltimateControl) 
		#include "IUltimateControlComponentInformation.h" //ComponentInformation interface
#endif
#if defined(USING_UltimateControl_Button) || defined(USING_UltimateControl) 
		#include "IButton.h" //Button interface
#endif
#if defined(USING_UltimateControl_Device) || defined(USING_UltimateControl) 
		#include "IDevice.h" //Device interface
#endif
#if defined(USING_UltimateControl_LCM) || defined(USING_UltimateControl) 
		#include "ILCM.h" //LCM interface
#endif
#if defined(USING_UltimateControl_LED) || defined(USING_UltimateControl) 
		#include "ILED.h" //LED interface
#endif
#if defined(USING_UltimateControl_OneWire) || defined(USING_UltimateControl) 
		#include "IOneWire.h" //OneWire interface
#endif
#if defined(USING_UltimateControl_UniversalControl) || defined(USING_UltimateControl) 
		#include "IUniversalControl.h" //UniversalControl interface
#endif
