// filename: IEasyAudioIn.h
#pragma once
// IEasyAudioIn
// This is one of EasyAudio COM component's interface
#include "EasyAudio.h" 
#ifndef PUREV
	#define PUREV =0
#else
	#undef  PUREV
	#define PUREV =0
#endif
namespace EasyAudio{
	///=======================================================================
	/// Interface IEasyAudioIn's definition and IID
	///=======================================================================
	// {A339AF49-4B62-4339-B0F2-6BC3C1E774C9} 
EASYAUDIO_DEFINE_GUID(IID_IEasyAudioIn,0xa339af49, 0x4b62, 0x4339, 0xb0, 0xf2, 0x6b, 0xc3, 0xc1, 0xe7, 0x74, 0xc9);
	//___________________________________________________________________________
	MIDL_INTERFACE("A339AF49-4B62-4339-B0F2-6BC3C1E774C9")
	IEasyAudioIn : public IUnknown
	{
	    STDMETHOD_(LPCTSTR, GetDescription) (UINT a) PUREV;
	    STDMETHOD(RunSelfUintTest) (UINT options) PUREV;
		STDMETHOD_(BSTR, GetStringProperty) (LPCTSTR propertyName) PUREV;
		STDMETHOD_(BOOL, IsDeviceConnected)(void)PUREV;
	    
		STDMETHOD(Attach)(int AudioInputID)PUREV;
		STDMETHOD(AttachByFriendlyName)(LPCTSTR FriendlyName)PUREV;
		//
		STDMETHOD(FormatSet)(
			WORD wFormatTag=WAVE_FORMAT_PCM, // 
            WORD nChannels=2, // 1=mono, 2=stereo
			WORD wBitsPerSample=16, // bits per sample
			DWORD nSamplesPerSec=16000 // sample rate, samples per second
			)PUREV;
		//
		STDMETHOD(FormatGet)(
			int index,
			WORD& wFormatTag, // WAVE_FORMAT_PCM
            WORD& nChannels, // 1=mono, 2=stereo
			WORD& wBitsPerSample, // bits per sample
			DWORD& nSamplesPerSec// sample rate, samples per second
			)PUREV;

	   STDMETHOD(FormatGetCurrent)(
			WORD& wFormatTag, // WAVE_FORMAT_PCM
            WORD& nChannels, // 1=mono, 2=stereo
			WORD& wBitsPerSample, // bits per sample
			DWORD& nSamplesPerSec// sample rate, samples per second
			)PUREV;


		STDMETHOD(RecordingLevelGet)(double* pVol)PUREV;
		STDMETHOD(RecordingLevelSet)(double Vol)PUREV;
		STDMETHOD_(int,FormatGetCount)(void)PUREV;
		STDMETHOD(SourceWaveFileNameSet) (LPTSTR filename) PUREV;
	};
};//namespace EasyAudio
#undef PUREV