// filename: EasyPTMotor.h
#pragma once
#include <guiddef.h>
///=======================================================================
/// Helper Marcos
///=======================================================================
// 
#define EASYPTMOTOR_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	EXTERN_C const GUID DECLSPEC_SELECTANY  name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define EASYPTMOTOR_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define EASYPTMOTOR_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// EasyPTMotor COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	//
	//ProgID for Unicode Character Set 
	#define EasyPTMotor_ProgID "EasyPTMotor.EasyPTMotorDRU"
	//
	// COM GUID for Unicode Character Set 
   // {5FFF1614-0D67-4329-94DF-B5BA4889E7F5} 
   #define  CLSID_EasyPTMotor_IMPLEMENT   { 0x5fff1614, 0xd67, 0x4329, { 0x94, 0xdf, 0xb5, 0xba, 0x48, 0x89, 0xe7, 0xf5 } }    
	EASYPTMOTOR_DEFINE_GUIDSTRUCT("5FFF1614-0D67-4329-94DF-B5BA4889E7F5", CLSID_EasyPTMotor);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	//
	//ProgID for Multi-Byte Character Set 
	#define EasyPTMotor_ProgID "EasyPTMotor.EasyPTMotorDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {52E9C92F-2D07-472f-8D2A-5F095151A83B} 
   #define  CLSID_EasyPTMotor_IMPLEMENT   { 0x52e9c92f, 0x2d07, 0x472f, { 0x8d, 0x2a, 0x5f, 0x9, 0x51, 0x51, 0xa8, 0x3b } }    
	EASYPTMOTOR_DEFINE_GUIDSTRUCT("52E9C92F-2D07-472F-8D2A-5F095151A83B", CLSID_EasyPTMotor);
///====================================================================================================================
#endif
#define CLSID_EasyPTMotor EASYPTMOTOR_DEFINE_GUIDNAMED(CLSID_EasyPTMotor)
#define USING_EasyPTMotor
//
///=======================================================================
/// Interfaces Definition 
///=======================================================================
/*
#if defined(USING_EasyPTMotor_ComponentInformation) || defined(USING_EasyPTMotor) 
		#include "IEasyPTMotorComponentInformation.h" //ComponentInformation interface
#endif
*/
#if defined(USING_EasyPTMotor_PanMotor) || defined(USING_EasyPTMotor) 
		#include "IPanMotor.h" //PanMotor interface
#endif
#if defined(USING_EasyPTMotor_TiltMotor) || defined(USING_EasyPTMotor) 
		#include "ITiltMotor.h" //TiltMotor interface
#endif

#if defined(USING_EasyPTMotor_Device) || defined(USING_EasyPTMotor) 
		#include "IDevice.h" 
#endif
