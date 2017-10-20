// filename: ITextDumpDialog.h
#pragma once
// ITextDumpDialog
// This is one of TxtDumpDlg COM component's interface
#include "TxtDumpDlg.h" 
#ifndef PUREV
	#define PUREV =0
#else
	#undef  PUREV
	#define PUREV =0
#endif
namespace TxtDumpDlg{
	///=======================================================================
	/// Interface ITextDumpDialog's definition and IID
	///=======================================================================
	// {278F218F-BE1B-4b10-8761-09036AA9A398} 
TXTDUMPDLG_DEFINE_GUID(IID_ITextDumpDialog,0x278f218f, 0xbe1b, 0x4b10, 0x87, 0x61, 0x9, 0x3, 0x6a, 0xa9, 0xa3, 0x98);
	//___________________________________________________________________________
	MIDL_INTERFACE("278F218F-BE1B-4B10-8761-09036AA9A398")
	ITextDumpDialog : public IUnknown
	{
	    STDMETHOD_(LPCTSTR, GetDescription) (UINT a) PUREV;//discard
	    STDMETHOD(RunSelfUintTest) (UINT options) PUREV;//discard
		//
		STDMETHOD(ShowDialog)(LPCTSTR pTitle)PUREV;
		STDMETHOD(SetText)(LPCTSTR pContext)PUREV;
		STDMETHOD(AppendText)(LPCTSTR pContext)PUREV;
		STDMETHOD(ClearText)(void)PUREV;
		//
		STDMETHOD(GetContext)(LPTSTR pContext)PUREV;
		STDMETHOD_(UINT, GetContextSize)(void)PUREV;
		STDMETHOD(SetLogFileName)(LPCTSTR LogFileName)PUREV;
		STDMETHOD(Out)(LPCTSTR strMessage,...)PUREV;
		STDMETHOD(AlsoLogTo)(TxtDumpDlg::ITextDumpDialog *pLog) PUREV;
		STDMETHOD(Line)(int length,LPTSTR s=_T("=")) PUREV;
		STDMETHOD(Show)(BOOL bShow) PUREV;
		STDMETHOD(LogToLogWindow)(BOOL bLog2Window) PUREV;

	//ClearLog
	//ResetError
	//ResetWarning
		STDMETHOD(SendLogCmd)(LPCTSTR LogCmd) PUREV;
		STDMETHOD_(BSTR, GetValue)(LPCTSTR Keyname) PUREV;
		/*
		Load Debug Category
		*/

	};
};//namespace TxtDumpDlg
#undef PUREV