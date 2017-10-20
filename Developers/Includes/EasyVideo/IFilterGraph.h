// filename: IFilterGraph.h
#pragma once
// IFilterGraph
// This is one of EasyVideo COM component's interface
#include "EasyVideoCOM.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyVideo{
	///=======================================================================
	/// Interface IFilterGraph's definition and IID
	///=======================================================================
	// {3A2DD736-FD35-4DFF-9293-FE21CEF03EA4} 
EASYVIDEO_DEFINE_GUID(IID_IFilterGraph,0x3A2DD736, 0xFD35, 0x4DFF, 0x92, 0x93, 0xFE, 0x21, 0xCE, 0xF0, 0x3E, 0xA4);
	//___________________________________________________________________________
	MIDL_INTERFACE("3A2DD736-FD35-4DFF-9293-FE21CEF03EA4")
	IFilterGraph : public IUnknown
	{
	    STDMETHOD_(LPCTSTR, GetDescription) (UINT a)PUREV;
	    STDMETHOD(SetFilterGraphUsage) (UINT options) PUREV;
	};
};//namespace EasyVideo
