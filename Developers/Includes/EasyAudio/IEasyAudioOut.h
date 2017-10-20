// filename: IEasyAudioOut.h
#pragma once
// IEasyAudioOut
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
	/// Interface IEasyAudioOut's definition and IID
	///=======================================================================
	// {5EAF9678-2062-4094-B3A3-53077DD47093} 
EASYAUDIO_DEFINE_GUID(IID_IEasyAudioOut,0x5eaf9678, 0x2062, 0x4094, 0xb3, 0xa3, 0x53, 0x7, 0x7d, 0xd4, 0x70, 0x93);
	//___________________________________________________________________________
	MIDL_INTERFACE("5EAF9678-2062-4094-B3A3-53077DD47093")
	IEasyAudioOut : public IUnknown
	{	    
		STDMETHOD_(BSTR, GetStringProperty) (LPCTSTR propertyName) PUREV;
		STDMETHOD(Attach)(int AudioOutID)PUREV;
		STDMETHOD(AttachByFriendlyName)(LPCTSTR FriendlyName)PUREV;
		STDMETHOD(GetVolume)(long* pVol)PUREV;
		STDMETHOD(SetVolume)(long pVol)PUREV;
		/*
		 // Specifies the volume, as a number from ¡V10,000 to 0, inclusive. 
         // Full volume is 0, and ¡V10,000 is silence. 
         // Multiply the desired decibel level by 100. For example, ¡V10,000 = ¡V100 dB.
		*/
		
	};
};//namespace EasyAudio

#undef PUREV

