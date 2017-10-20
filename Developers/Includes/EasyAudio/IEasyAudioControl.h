// filename: IEasyAudioControl.h
#pragma once
// IEasyAudioControl
// This is one of EasyAudio COM component's interface
#include "EasyAudio.h" 
#include "IEasyAudioIn.h" //EasyAudioIn interface
#include "IEasyAudioOut.h" //EasyAudioOut interface

#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0

namespace EasyAudio{
	///=======================================================================
	/// Interface IEasyAudioControl's definition and IID
	///=======================================================================
	// {B5F57EBA-A82F-42e9-A4EA-6A03974152E2} 
EASYAUDIO_DEFINE_GUID(IID_IEasyAudioControl,0xb5f57eba, 0xa82f, 0x42e9, 0xa4, 0xea, 0x6a, 0x3, 0x97, 0x41, 0x52, 0xe2);
	//___________________________________________________________________________
	MIDL_INTERFACE("B5F57EBA-A82F-42E9-A4EA-6A03974152E2")
	IEasyAudioControl : public IUnknown
	{
		STDMETHOD_(int, AIDGetCount) (void) PUREV;
		STDMETHOD_(int, AODGetCount) (void) PUREV;		
		STDMETHOD(Play) (BOOL bWaitCaptureTime=FALSE) PUREV;
		STDMETHOD(Stop) (void) PUREV;
        //
		STDMETHOD(SetAudioSource)( LPTSTR AIS, WORD nChannels=2,WORD wBitsPerSample=16, DWORD nSamplesPerSec=16000, double AIDVolume=1.0)PUREV;// max vol=1.0, min vol=0.0
		STDMETHOD(SetAudioOutDevice)( LPTSTR AOD, long OutVol=0)PUREV;
		STDMETHOD(SetAudioOutWaveFile)( LPTSTR AOWF, ULONG DelaySamplingCount, ULONG SamplingCount)PUREV;
		STDMETHOD_(BOOL,IsPlaying)(void)PUREV;
	};
};//namespace EasyAudio
#undef PUREV