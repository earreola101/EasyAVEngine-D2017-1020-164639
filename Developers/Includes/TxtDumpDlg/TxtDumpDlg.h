// filename: TxtDumpDlg.h
#pragma once
#include <guiddef.h>
///=======================================================================
/// Helper Marcos
///=======================================================================
// 


#define TXTDUMPDLG_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
       
#define TXTDUMPDLG_DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
#define TXTDUMPDLG_DEFINE_GUIDNAMED(n) __uuidof(struct n)  
///=======================================================================
/// TxtDumpDlg COM Server Definition
///=======================================================================
#if defined(_UNICODE) // the client application is Unicode Character Set 
	// TxtDumpDlg COM Component filename for Unicode Character Set 
	#define TxtDumpDlg_MODULE_NAME "TxtDumpDlgDRU.DLL"
	//
	//ProgID for Unicode Character Set 
	#define TxtDumpDlg_ProgID "TxtDumpDlg.TxtDumpDlgDRU"
	//
	// COM GUID for Unicode Character Set 
   // {9CE8756A-873D-4ba0-9F47-0AEA043C1C81} 
   #define  CLSID_TxtDumpDlg_IMPLEMENT   { 0x9ce8756a, 0x873d, 0x4ba0, { 0x9f, 0x47, 0xa, 0xea, 0x4, 0x3c, 0x1c, 0x81 } }    

	TXTDUMPDLG_DEFINE_GUIDSTRUCT("9CE8756A-873D-4BA0-9F47-0AEA043C1C81", CLSID_TxtDumpDlg);
///====================================================================================================================
#else // // the client application is Multi-Byte Character Set 
	// TxtDumpDlg COM Component filename for Multi-Byte Character Set 
	#define TxtDumpDlg_MODULE_NAME "TxtDumpDlgDRM.DLL"
	//
	//ProgID for Multi-Byte Character Set 
	#define TxtDumpDlg_ProgID "TxtDumpDlg.TxtDumpDlgDRM"
	//
	// COM GUID for Multi-Byte Character Set 
   // {2AA9CB76-4EBF-411d-AA1D-CD597C6F9858} 
   #define  CLSID_TxtDumpDlg_IMPLEMENT   { 0x2aa9cb76, 0x4ebf, 0x411d, { 0xaa, 0x1d, 0xcd, 0x59, 0x7c, 0x6f, 0x98, 0x58 } }    

	TXTDUMPDLG_DEFINE_GUIDSTRUCT("2AA9CB76-4EBF-411D-AA1D-CD597C6F9858", CLSID_TxtDumpDlg);
///====================================================================================================================
#endif
#define CLSID_TxtDumpDlg TXTDUMPDLG_DEFINE_GUIDNAMED(CLSID_TxtDumpDlg)
#define USING_TxtDumpDlg
//
///=======================================================================
/// Interfaces Definition 
///=======================================================================

#if defined(USING_TxtDumpDlg_TextDumpDialog) || defined(USING_TxtDumpDlg) 
		#include "ITextDumpDialog.h" //TextDumpDialog interface
#endif

#include "MasterLoggingIF.h" //MasterLogging interface

//Some helper 
//#define LOG if(_pLog!=0) _pLog->Out
