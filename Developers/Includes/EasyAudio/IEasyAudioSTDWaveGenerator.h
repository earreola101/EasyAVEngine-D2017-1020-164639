// filename: IEasyAudioSTDWaveGenerator.h
#pragma once
// IEasyAudioSTDWaveGenerator
// This is one of EasyAudio COM component's interface
#include "EasyAudio.h" 
namespace EasyAudio{
	///=======================================================================
	/// Interface IEasyAudioSTDWaveGenerator's definition and IID
	///=======================================================================
	// {A59FF9C8-098C-4615-86A3-85A57E3276B9} 
EASYAUDIO_DEFINE_GUID(IID_IEasyAudioSTDWaveGenerator,0xa59ff9c8, 0x98c, 0x4615, 0x86, 0xa3, 0x85, 0xa5, 0x7e, 0x32, 0x76, 0xb9);
	//___________________________________________________________________________
	MIDL_INTERFACE("A59FF9C8-098C-4615-86A3-85A57E3276B9")
	IEasyAudioSTDWaveGenerator : public IUnknown
	{
		STDMETHOD(SetSTDWaveFormat)(UINT SignalType, double SignalFrequency, double  SignalAmplitude, double AmplitudeOffset)=0;
		//STDMETHOD(Enable)(bool enable)=0;
	};
};//namespace EasyAudio
