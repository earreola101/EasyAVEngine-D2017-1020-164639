// filename: EasyLensMotor.h
#pragma once
#include <guiddef.h>
///=======================================================================
/// Helper Marcos
///=======================================================================
// 
#define EASYLENSMOTOR_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define EASYLENSMOTOR_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define EASYLENSMOTOR_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// EasyLensMotor COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	//
	//ProgID for Unicode Character Set 
	#define EasyLensMotor_ProgID "EasyLensMotor.EasyLensMotorDRU"
	//
	// COM GUID for Unicode Character Set 
   // {9E8D898E-0D7A-4975-94A2-6B92668DD76C} 
   #define  CLSID_EasyLensMotor_IMPLEMENT   { 0x9e8d898e, 0xd7a, 0x4975, { 0x94, 0xa2, 0x6b, 0x92, 0x66, 0x8d, 0xd7, 0x6c } }    
	EASYLENSMOTOR_DEFINE_GUIDSTRUCT("9E8D898E-0D7A-4975-94A2-6B92668DD76C", CLSID_EasyLensMotor);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	//
	//ProgID for Multi-Byte Character Set 
	#define EasyLensMotor_ProgID "EasyLensMotor.EasyLensMotorDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {1EA809D3-B74A-472b-BCB8-534E3E9800C2} 
   #define  CLSID_EasyLensMotor_IMPLEMENT   { 0x1ea809d3, 0xb74a, 0x472b, { 0xbc, 0xb8, 0x53, 0x4e, 0x3e, 0x98, 0x0, 0xc2 } }    
	EASYLENSMOTOR_DEFINE_GUIDSTRUCT("1EA809D3-B74A-472B-BCB8-534E3E9800C2", CLSID_EasyLensMotor);
///====================================================================================================================
#endif
#define CLSID_EasyLensMotor EASYLENSMOTOR_DEFINE_GUIDNAMED(CLSID_EasyLensMotor)
#define USING_EasyLensMotor
//
///=======================================================================
/// Interfaces Definition 
///=======================================================================

#if defined(USING_EasyLensMotor_MotorControl) || defined(USING_EasyLensMotor) 
		#include "IMotorControl.h" //MotorControl interface
#endif
#if defined(USING_EasyLensMotor_MotorControlAdvanced) || defined(USING_EasyLensMotor) 
		#include "IMotorControlAdvanced.h" //MotorControlAdvanced interface
#endif
