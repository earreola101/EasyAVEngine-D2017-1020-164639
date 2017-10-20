// filename: UltimateSCPI.h
#pragma once
#include <guiddef.h>
///=======================================================================
/// Helper Marcos
///=======================================================================
// 
#define ULTIMATESCPI_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define ULTIMATESCPI_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define ULTIMATESCPI_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// UltimateSCPI COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	//
	//ProgID for Unicode Character Set 
	#define UltimateSCPI_ProgID "UltimateSCPI.UltimateSCPIDRU"
	//
	// COM GUID for Unicode Character Set 
   // {3F25B3C3-FB2B-49ef-A445-9AF5A62B4FF2} 
   #define  CLSID_UltimateSCPI_IMPLEMENT   { 0x3f25b3c3, 0xfb2b, 0x49ef, { 0xa4, 0x45, 0x9a, 0xf5, 0xa6, 0x2b, 0x4f, 0xf2 } }    
	ULTIMATESCPI_DEFINE_GUIDSTRUCT("3F25B3C3-FB2B-49EF-A445-9AF5A62B4FF2", CLSID_UltimateSCPI);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	//
	//ProgID for Multi-Byte Character Set 
	#define UltimateSCPI_ProgID "UltimateSCPI.UltimateSCPIDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {373579E7-F325-4a32-83E5-4846DD3A343E} 
   #define  CLSID_UltimateSCPI_IMPLEMENT   { 0x373579e7, 0xf325, 0x4a32, { 0x83, 0xe5, 0x48, 0x46, 0xdd, 0x3a, 0x34, 0x3e } }    
	ULTIMATESCPI_DEFINE_GUIDSTRUCT("373579E7-F325-4A32-83E5-4846DD3A343E", CLSID_UltimateSCPI);
///====================================================================================================================
#endif
#define CLSID_UltimateSCPI ULTIMATESCPI_DEFINE_GUIDNAMED(CLSID_UltimateSCPI)
#define USING_UltimateSCPI
//
///=======================================================================
/// Interfaces Definition 
///=======================================================================
 
#if defined(USING_UltimateSCPI_SCPI) || defined(USING_UltimateSCPI) 
		#include "ISCPI.h" //SCPI interface
#endif

