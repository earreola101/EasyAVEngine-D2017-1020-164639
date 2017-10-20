// filename: IEasyAudioIn2.h
#pragma once
// IEasyAudioIn2
// This is one of EasyAudio COM component's interface
#include "EasyAudio.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyAudio{
	///=======================================================================
	/// Interface IEasyAudioIn2's definition and IID
	///=======================================================================
	// {DF6FBB8E-90BB-40E0-BB1E-38BB7ADB66A7} 
EASYAUDIO_DEFINE_GUID(IID_IEasyAudioIn2,0xDF6FBB8E, 0x90BB, 0x40E0, 0xBB, 0x1E, 0x38, 0xBB, 0x7A, 0xDB, 0x66, 0xA7);
	//___________________________________________________________________________
	MIDL_INTERFACE("DF6FBB8E-90BB-40E0-BB1E-38BB7ADB66A7")
	IEasyAudioIn2 : public IUnknown
	{
	    STDMETHOD_(LPCTSTR, GetDescription) (UINT a) PUREV; //
	    STDMETHOD(RunSelfUintTest) (UINT options) PUREV;  //
		
		//Get current device's string property.
		//Parameters:
		//	PropertyName: the property name can get from GetStringPropertyName().
		//Returns: BSTR value of the property.
		STDMETHOD_(BSTR, GetStringProperty) (LPCTSTR PropertyName) PUREV;

		//Query if the device attached to this IEasyAudioIn2 is connecting to the system.
		//returns: 
		//	 TRUE: the device is connecting to the system.
		//	FALSE: the device is not connecting to the system.
		STDMETHOD_(BOOL, IsDeviceConnected)(void)PUREV;
	    
	    // attach IEasyAudioIn2 interface to a audio input device with a list id (AudioInputID).
		//Parameters:
		//	AudioInputID: the range is from 0 to IEasyAudioControl::AIDGetCount()-1.
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(Attach)(int AudioInputID)PUREV;

		//Attach IEasyAudioIn2 interface to a input device with a FriendlyName.
		//Parameters:
		//	FriendlyName: the friendly name for the device.
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(AttachByFriendlyName)(LPCTSTR FriendlyName)PUREV;
		//
		// Set audio input device's  current audio fromat.
		//Parameters:
		//	wFormatTag: WAVE_FORMAT_PCM
		//	nChannels: 1=mono, 2=stereo
		//	wBitsPerSample: bits per sample
		//	nSamplesPerSec: sample rate, samples per second
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(FormatSet)(
			WORD wFormatTag=WAVE_FORMAT_PCM, // 
            WORD nChannels=2, // 1=mono, 2=stereo
			WORD wBitsPerSample=16, // bits per sample
			DWORD nSamplesPerSec=16000 // sample rate, samples per second
			)PUREV;
		//
		// Get audio input device's audio fromat according to the audio fromat list index(FmtListIndex).
		//Parameters:
		//	wFormatTag: WAVE_FORMAT_PCM
		//	nChannels: 1=mono, 2=stereo
		//	wBitsPerSample: bits per sample
		//	nSamplesPerSec: sample rate, samples per second
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(FormatGet)(
			int FmtListIndex,
			WORD& wFormatTag, // WAVE_FORMAT_PCM
            WORD& nChannels, // 1=mono, 2=stereo
			WORD& wBitsPerSample, // bits per sample
			DWORD& nSamplesPerSec// sample rate, samples per second
			)PUREV;

	   // Get audio input device's current audio fromat.
		//Parameters:
		//	wFormatTag: WAVE_FORMAT_PCM
		//	nChannels: 1=mono, 2=stereo
		//	wBitsPerSample: bits per sample
		//	nSamplesPerSec: sample rate, samples per second
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(FormatGetCurrent)(
			WORD& wFormatTag, // WAVE_FORMAT_PCM
            WORD& nChannels, // 1=mono, 2=stereo
			WORD& wBitsPerSample, // bits per sample
			DWORD& nSamplesPerSec// sample rate, samples per second
			)PUREV;

	   //Get current audio input device's recording level.	
	   //Parameters:
	   //	pVol: the volume level, range is from 0.0 to 1.0, Zero indicates that the recording level is off; 
	    //	the value 1.0 indicates that the recording level is at full volume. Intermediate values are also allowed.
	   //Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
	   STDMETHOD(RecordingLevelGet)(double* pVol)PUREV;

        //Set current audio input device's recording level.	
   	    //Parameters:
	    //	Vol: the volume level, range is from 0.0 to 1.0, Zero indicates that the recording level is off; 
	    //	the value 1.0 indicates that the recording level is at full volume. Intermediate values are also allowed.
	    //Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(RecordingLevelSet)(double Vol)PUREV;

		//Get current device's audio format counts.
		//Returns: 
		//	 counts of current device's audio format.
		STDMETHOD_(int,FormatGetCount)(void)PUREV;


		//Set the wavefile to become the audio input source.
		//Parameters:
		//	filename: full path file name for the audio media file(*.wav).
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(SourceWaveFileNameSet) (LPTSTR filename) PUREV;
		
		/* above are the same as IEasyVideoIn
		//====================================================================
		// Below are new methods for IEasyVideoIn2
		//====================================================================
		*/


		//get the device's volume
		//Parameters:
		//	level: the value range from 0 to 100.
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		//remark:
		//  the device must a hardware device, by qurery hardware via IsHWDevice() and return TRUE.
		STDMETHOD (HWVolumeGet)(float &level) PUREV;

		//set the device's volume
		//Parameters:
		//	level: the value range from 0 to 100.
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		//remark:
		//  the device must a hardware device, by qurery hardware via IsHWDevice() and return TRUE.
		STDMETHOD (HWVolumeSet)(float level) PUREV;

		//get the device's mute current setting
		//Parameters:
		//	SW=TRUE: the device is mute ON, no sound.
		//	SW=FALSE: the device is mute OFF, no sound.
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		//remark:
		//  the device must a hardware device, by qurery hardware via IsHWDevice() and return TRUE.
		STDMETHOD (HWMuteGet)(BOOL &SW) PUREV;

		//set the device's mute value
 	    //Parameters:
		//	SW=TRUE: the device is mute ON, no sound.
		//	SW=FALSE: the device is mute OFF, no sound.
		// returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		//remark:
		//  the device must a hardware device, by qurery hardware via IsHWDevice() and return TRUE.
		STDMETHOD (HWMuteSet)(BOOL SW) PUREV;

        
		// Use this to Open audio device's configuration property page.
		// returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(OpenDevicePropertyPage) (void) PUREV;
		

		//set this device to bcome system default audio device
		// returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		//remark:
		//  the device must a hardware device, by qurery hardware via IsHWDevice() and return TRUE.
		STDMETHOD(SetSystemDefaultAudioDevice) (void) PUREV;

		//Query if the device is current system default audio device.
		//returns: 
		//	 TRUE: the device is current system default audio device.
		//	FALSE: this device is not the system default audio device.
		STDMETHOD_(BOOL, IsSystemDefaultAudioDevice) (void) PUREV;
		//

		//Query if the device is a harware device
		//returns: 
		//	 TRUE: the device is a hardware device.
		//	FALSE: this device is not a hardware device.
		STDMETHOD_(BOOL,IsHWDevice)(void) PUREV;
		
		//get string property count.
		//Returns: 
		//	 counts of the property name.
		STDMETHOD_(int, GetStringPropertyCount) (void) PUREV;

		//get property name via index
		//Parameters:
		//	index: the input index for the property, the index range is from 0 to GetStringPropertyCount()-1;
		//Returns: 
		//	 the return value is the BSTR string for the property name.
		STDMETHOD_(BSTR, GetStringPropertyName) (int index)  PUREV;
		//==========================================================================

	};
};//namespace EasyAudio
