// filename: IEasyAudioCalibratedProfile.h
#pragma once
// IEasyAudioCalibratedProfile
// This is one of EasyAudio COM component's interface
#include "EasyAudio.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyAudio{
	///=======================================================================
	/// Interface IEasyAudioCalibratedProfile's definition and IID
	///=======================================================================
	// {34B59C19-2C1E-4cf0-A691-6D67A41EB903} 
EASYAUDIO_DEFINE_GUID(IID_IEasyAudioCalibratedProfile,0x34b59c19, 0x2c1e, 0x4cf0, 0xa6, 0x91, 0x6d, 0x67, 0xa4, 0x1e, 0xb9, 0x3);
	//___________________________________________________________________________
	MIDL_INTERFACE("34B59C19-2C1E-4CF0-A691-6D67A41EB903")
	IEasyAudioCalibratedProfile : public IUnknown
	{
		//
		STDMETHOD(GetCalibratedProfileFilename) (LPTSTR fileanme) PUREV;
		STDMETHOD(EnableCalibratedProfile) (BOOL bVal) PUREV;
		STDMETHOD(GetCurrentProfile) (double & Frequency, double & amp) PUREV;
	};
};//namespace EasyAudio
