// filename: EasyControl.h
#pragma once
#include <guiddef.h>
///=======================================================================
/// Helper Marcos
///=======================================================================
// 
#define EASYCONTROL_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define EASYCONTROL_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define EASYCONTROL_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// EasyControl COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	//
	//ProgID for Unicode Character Set 
	#define EasyControl_ProgID "EasyControl.EasyControlDRU"
	//
	// COM GUID for Unicode Character Set 
   // {93BD6FF8-313D-44b4-A079-24A18EC0DE8B} 
   #define  CLSID_EasyControl_IMPLEMENT   { 0x93bd6ff8, 0x313d, 0x44b4, { 0xa0, 0x79, 0x24, 0xa1, 0x8e, 0xc0, 0xde, 0x8b } }    
	EASYCONTROL_DEFINE_GUIDSTRUCT("93BD6FF8-313D-44B4-A079-24A18EC0DE8B", CLSID_EasyControl);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	//
	//ProgID for Multi-Byte Character Set 
	#define EasyControl_ProgID "EasyControl.EasyControlDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {B9768ABD-7478-4ddd-A8F1-E0B665E9954E} 
   #define  CLSID_EasyControl_IMPLEMENT   { 0xb9768abd, 0x7478, 0x4ddd, { 0xa8, 0xf1, 0xe0, 0xb6, 0x65, 0xe9, 0x95, 0x4e } }    
	EASYCONTROL_DEFINE_GUIDSTRUCT("B9768ABD-7478-4DDD-A8F1-E0B665E9954E", CLSID_EasyControl);
///====================================================================================================================
#endif
#define CLSID_EasyControl EASYCONTROL_DEFINE_GUIDNAMED(CLSID_EasyControl)
#define USING_EasyControl
//
///=======================================================================
/// Interfaces Definition 
///=======================================================================

#if defined(USING_EasyControl_DeviceControl) || defined(USING_EasyControl) 
		#include "IDeviceControl.h" //DeviceControl interface
#endif

#include "IAudioDeviceControl.h"
