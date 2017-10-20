// filename: EasyAVEngine.h
#pragma once
#include <guiddef.h>
///=======================================================================
/// Helper Marcos
///=======================================================================
// 
#define EASYAVENGINE_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define EASYAVENGINE_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define EASYAVENGINE_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// EasyAVEngine COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	//
	//ProgID for Unicode Character Set 
	#define EasyAVEngine_ProgID "EasyAVEngine.EasyAVEngineDRU"
	//
	// COM GUID for Unicode Character Set 
   // {9B6A7923-604B-496F-9DAA-8BD708807A35} 
   #define  CLSID_EasyAVEngine_IMPLEMENT   { 0x9B6A7923, 0x604B, 0x496F, { 0x9D, 0xAA, 0x8B, 0xD7, 0x8, 0x80, 0x7A, 0x35 } }    
	EASYAVENGINE_DEFINE_GUIDSTRUCT("9B6A7923-604B-496F-9DAA-8BD708807A35", CLSID_EasyAVEngine);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	//
	//ProgID for Multi-Byte Character Set 
	#define EasyAVEngine_ProgID "EasyAVEngine.EasyAVEngineDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {60486B69-0AD2-49AF-843F-DCD95CA80FD9} 
   #define  CLSID_EasyAVEngine_IMPLEMENT   { 0x60486B69, 0xAD2, 0x49AF, { 0x84, 0x3F, 0xDC, 0xD9, 0x5C, 0xA8, 0xF, 0xD9 } }    
	EASYAVENGINE_DEFINE_GUIDSTRUCT("60486B69-0AD2-49AF-843F-DCD95CA80FD9", CLSID_EasyAVEngine);
///====================================================================================================================
#endif
#define CLSID_EasyAVEngine EASYAVENGINE_DEFINE_GUIDNAMED(CLSID_EasyAVEngine)
#define USING_EasyAVEngine
//
///=======================================================================
/// Interfaces Definition 
///=======================================================================
		#include "EasyAVEngineMasterIF.h" //EasyAVEngineMaster interface
