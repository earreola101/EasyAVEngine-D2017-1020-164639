// filename: EasyAudioWaveFile.h
#pragma once
#include <guiddef.h>

///=======================================================================
/// Helper Marcos
///=======================================================================
// 
#define EASYAUDIOWAVEFILE_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define EASYAUDIOWAVEFILE_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define EASYAUDIOWAVEFILE_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// EasyAudioWaveFile COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	//
	//ProgID for Unicode Character Set 
	#define EasyAudioWaveFile_ProgID "EasyAudioWaveFile.EasyAudioWaveFileDRU"
	//
	// COM GUID for Unicode Character Set 
   // {4F9F481C-EA0C-405c-8A3C-53691DA05D05} 
   #define  CLSID_EasyAudioWaveFile_IMPLEMENT   { 0x4f9f481c, 0xea0c, 0x405c, { 0x8a, 0x3c, 0x53, 0x69, 0x1d, 0xa0, 0x5d, 0x5 } }    
	EASYAUDIOWAVEFILE_DEFINE_GUIDSTRUCT("4F9F481C-EA0C-405C-8A3C-53691DA05D05", CLSID_EasyAudioWaveFile);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	//
	//ProgID for Multi-Byte Character Set 
	#define EasyAudioWaveFile_ProgID "EasyAudioWaveFile.EasyAudioWaveFileDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {B5D95BB1-C7DD-473f-9FFE-66041A58AB01} 
   #define  CLSID_EasyAudioWaveFile_IMPLEMENT   { 0xb5d95bb1, 0xc7dd, 0x473f, { 0x9f, 0xfe, 0x66, 0x4, 0x1a, 0x58, 0xab, 0x1 } }    
	EASYAUDIOWAVEFILE_DEFINE_GUIDSTRUCT("B5D95BB1-C7DD-473F-9FFE-66041A58AB01", CLSID_EasyAudioWaveFile);
///====================================================================================================================
#endif
#define CLSID_EasyAudioWaveFile EASYAUDIOWAVEFILE_DEFINE_GUIDNAMED(CLSID_EasyAudioWaveFile)
#define USING_EasyAudioWaveFile
//
///=======================================================================
/// Interfaces Definition 
///=======================================================================

#if defined(USING_EasyAudioWaveFile_WaveFile) || defined(USING_EasyAudioWaveFile) 
		#include "IEasyAudioWaveFile.h" //WaveFile interface
#endif
