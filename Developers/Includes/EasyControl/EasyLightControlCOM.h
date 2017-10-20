// filename: EasyLightControlCOM.h
#pragma once
#include <guiddef.h>
///=======================================================================
/// Helper Marcos
///=======================================================================
// 
#define EASYLIGHTCONTROLCOM_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define EASYLIGHTCONTROLCOM_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define EASYLIGHTCONTROLCOM_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// EasyLightControlCOM COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	//
	//ProgID for Unicode Character Set 
	#define EasyLightControlCOM_ProgID "EasyLightControlCOM.EasyLightControlCOMDRU"
	//
	// COM GUID for Unicode Character Set 
   // {7553BE8B-D21A-4187-B927-2894A881121A} 
   #define  CLSID_EasyLightControlCOM_IMPLEMENT   { 0x7553BE8B, 0xD21A, 0x4187, { 0xB9, 0x27, 0x28, 0x94, 0xA8, 0x81, 0x12, 0x1A } }    
	EASYLIGHTCONTROLCOM_DEFINE_GUIDSTRUCT("7553BE8B-D21A-4187-B927-2894A881121A", CLSID_EasyLightControlCOM);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	//
	//ProgID for Multi-Byte Character Set 
	#define EasyLightControlCOM_ProgID "EasyLightControlCOM.EasyLightControlCOMDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {0185328F-2735-4418-88DA-6DE6EDB7A5F2} 
   #define  CLSID_EasyLightControlCOM_IMPLEMENT   { 0x185328F, 0x2735, 0x4418, { 0x88, 0xDA, 0x6D, 0xE6, 0xED, 0xB7, 0xA5, 0xF2 } }    
	EASYLIGHTCONTROLCOM_DEFINE_GUIDSTRUCT("0185328F-2735-4418-88DA-6DE6EDB7A5F2", CLSID_EasyLightControlCOM);
///====================================================================================================================
#endif
#define CLSID_EasyLightControlCOM EASYLIGHTCONTROLCOM_DEFINE_GUIDNAMED(CLSID_EasyLightControlCOM)
#define USING_EasyLightControlCOM
//
///=======================================================================
/// Interfaces Definition 
///=======================================================================
		//#include "EasyLightControlCOMMasterIF.h" //EasyLightControlCOMMaster interface
#if defined(USING_EasyLightControlCOM_LightControl) || defined(USING_EasyLightControlCOM) 
		#include "LightControlIF.h" //LightControl interface
#endif
