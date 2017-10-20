// filename: EasyAudio.h
#pragma once
#include <guiddef.h>
///=======================================================================
/// Helper Marcos
///=======================================================================
// 
#define EASYAUDIO_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define EASYAUDIO_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define EASYAUDIO_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// EasyAudio COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	// EasyAudio COM Component filename for Unicode Character Set 
	#define EasyAudio_MODULE_NAME "EasyAudioDRU.DLL"
	//
	//ProgID for Unicode Character Set 
	#define EasyAudio_ProgID "EasyAudio.EasyAudioDRU"
	//
	// COM GUID for Unicode Character Set 
   // {A334057E-8A73-47bc-A79D-7CAB6E8D4E84} 
   #define  CLSID_EasyAudio_IMPLEMENT   { 0xa334057e, 0x8a73, 0x47bc, { 0xa7, 0x9d, 0x7c, 0xab, 0x6e, 0x8d, 0x4e, 0x84 } }    
	EASYAUDIO_DEFINE_GUIDSTRUCT("A334057E-8A73-47BC-A79D-7CAB6E8D4E84", CLSID_EasyAudio);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	// EasyAudio COM Component filename for Multi-Byte Character Set 
	#define EasyAudio_MODULE_NAME "EasyAudioDRM.DLL"
	//
	//ProgID for Multi-Byte Character Set 
	#define EasyAudio_ProgID "EasyAudio.EasyAudioDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {58BEB84B-6BE3-4a93-8F56-B1265C7C4B69} 
   #define  CLSID_EasyAudio_IMPLEMENT   { 0x58beb84b, 0x6be3, 0x4a93, { 0x8f, 0x56, 0xb1, 0x26, 0x5c, 0x7c, 0x4b, 0x69 } }    
	EASYAUDIO_DEFINE_GUIDSTRUCT("58BEB84B-6BE3-4A93-8F56-B1265C7C4B69", CLSID_EasyAudio);
///====================================================================================================================
#endif
#define CLSID_EasyAudio EASYAUDIO_DEFINE_GUIDNAMED(CLSID_EasyAudio)
#define USING_EasyAudio
//
#include "EasyAudioWaveFile.h" //EasyAudioWaveFile component
#include "IEasyAudioControl.h"
#include "IEasyAudioIn.h"
#include "IEasyAudioIn2.h"
#include "IEasyAudioOut.h"
#include "IEasyAudioOut2.h"
#include "IEasyAudioSTDWaveGenerator.h"
#include "IEasyAudioCalibratedProfile.h" // Audio Calibrated Profile mechanism
 
	



	
