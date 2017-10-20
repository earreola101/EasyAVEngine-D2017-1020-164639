// filename: IEasyVideoCmd.h
#pragma once
// IEasyVideoCmd
// This is one of EasyVideo COM component's interface
#include "EasyVideoCOM.h" 
#define LOG_PROC(__fnVFP) void (CALLBACK * __fnVFP) (LPCTSTR msg)
namespace EasyVideo{
	///=======================================================================
	/// Interface IEasyVideoCmd's definition and IID
	///=======================================================================
	// {190503DB-6E4E-4f90-8559-6D146E6BEA3C} 
EASYVIDEO_DEFINE_GUID(IID_IEasyVideoCmd,0x190503db, 0x6e4e, 0x4f90, 0x85, 0x59, 0x6d, 0x14, 0x6e, 0x6b, 0xea, 0x3c);
	//___________________________________________________________________________
	MIDL_INTERFACE("190503DB-6E4E-4F90-8559-6D146E6BEA3C")
	IEasyVideoCmd : public IUnknown
	{
	    STDMETHOD_(LPCTSTR, GetDescription) (UINT a) = 0;
	    STDMETHOD(RunSelfUintTest) (UINT options) = 0;
		STDMETHOD(SetConfiguration) (LPCTSTR Config) = 0;
		STDMETHOD(GetConfiguration) (LPTSTR Config) = 0;
		STDMETHOD(Run) (void) = 0;
		STDMETHOD(Launch)( LOG_PROC(fnVFP), CString &RetStr, CString InFile=_T(""), CString CmdLine=_T(""))=0;
	};
};//namespace EasyVideo
