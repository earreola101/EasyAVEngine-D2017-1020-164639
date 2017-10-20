// filename: EasyAVEngineMasterIF.h
#pragma once
// IEasyAVEngineMaster
// This is one of EasyAVEngine COM component's interface
#include "EasyAVEngine.h" 

#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyAVEngine{
	///=======================================================================
	/// Interface IEasyAVEngineMaster's definition and IID
	///=======================================================================
	// {EDE8F629-E200-41B4-A1CF-BA2BCFDBD867} 
	EASYAVENGINE_DEFINE_GUID(IID_IEasyAVEngineMaster, 0xEDE8F629, 0xE200, 0x41B4, 0xA1, 0xCF, 0xBA, 0x2B, 0xCF, 0xDB, 0xD8, 0x67);
	//___________________________________________________________________________
	MIDL_INTERFACE("EDE8F629-E200-41B4-A1CF-BA2BCFDBD867")
	IEasyAVEngineMaster : public IUnknown
	{
		STDMETHOD_(LPCTSTR, GetDescription) (UINT a) PUREV;
		STDMETHOD(RunSelfUintTest) (UINT options) PUREV;
		STDMETHOD(GetComponentPathFileName)(LPTSTR pszFile) PUREV;
		STDMETHOD(SetWindow) (HWND hParent, LPCTSTR title) PUREV;
		STDMETHOD_(BSTR, GetEasyAVEngineVersion) (void)PUREV;
		STDMETHOD_(BSTR, GetEasyAVEnginePath)(void)PUREV;
		STDMETHOD(CheckModuleVersion)(void)PUREV;
		STDMETHOD_(int, GetModuleCount)(void)PUREV;
	};
};//namespace EasyAVEngine
