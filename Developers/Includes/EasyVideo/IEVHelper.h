// filename: IEVHelper.h
#pragma once
// IEVHelper.h
#include "EasyVideoCOM.h" 
namespace EasyVideo{
///=======================================================================
/// Interface IEVHelper's definition and IID
///=======================================================================
// {B50EDA73-9E88-474b-BB2A-4498E92A8260} 
static const IID IID_IEVHelper = { 0xb50eda73, 0x9e88, 0x474b, { 0xbb, 0x2a, 0x44, 0x98, 0xe9, 0x2a, 0x82, 0x60 } };
//___________________________________________________________________________
MIDL_INTERFACE("B50EDA73-9E88-474B-BB2A-4498E92A8260")
IEVHelper : public IUnknown
{
    STDMETHOD_(LPCTSTR, GetDescription) (UINT a) = 0;
    STDMETHOD(RunSelfUintTest) (UINT options) = 0;
    STDMETHOD(SleepEx)(DWORD milliseconds)=0;
    STDMETHOD_(void, GUIDtoString)(GUID&  Guid , LPTSTR szGUID)=0;
    STDMETHOD(VideoFormatGuid2Name)(GUID &VideoFormatGuid,LPTSTR VideoFormatName)=0;
	STDMETHOD_(GUID,FindGuid)(LPCTSTR VideoFormatName)=0;

	
};
};//namespace EasyVideo
