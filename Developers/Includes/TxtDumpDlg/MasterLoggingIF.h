// filename: MasterLoggingIF.h
#pragma once
// IMasterLogging
// This is one of TxtDumpDlg COM component's interface
#include "TxtDumpDlg.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace TxtDumpDlg{
	///=======================================================================
	/// Interface IMasterLogging's definition and IID
	///=======================================================================
	// {D0CBFF0B-E121-492B-8572-F8EDCFBB2B76} 
TXTDUMPDLG_DEFINE_GUID(IID_IMasterLogging,0xD0CBFF0B, 0xE121, 0x492B, 0x85, 0x72, 0xF8, 0xED, 0xCF, 0xBB, 0x2B, 0x76);
	//___________________________________________________________________________
	MIDL_INTERFACE("D0CBFF0B-E121-492B-8572-F8EDCFBB2B76")
	IMasterLogging : public IUnknown
	{
		STDMETHOD(SetLogFileName)(LPCTSTR LogFileName)PUREV;
		STDMETHOD(Out)(LPCTSTR strMessage, ...)PUREV;
		STDMETHOD_(BSTR, GetValue)(LPCTSTR Keyname) PUREV;
		//STDMETHOD_(void, SetParentWnd)(HWND ParentWnd) PUREV;
#define LoggingShowWindow     0x0001// 
#define LoggingOutputToWindow 0x0002// 1:TRUE, O: FALSE

		STDMETHOD_(void, SetLogging)(int CID, WORD LoggingSettings) PUREV;
		STDMETHOD_(WORD, GetLogging)(int CID) PUREV;
	};
};//namespace TxtDumpDlg
