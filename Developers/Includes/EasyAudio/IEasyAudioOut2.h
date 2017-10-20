// filename: IEasyAudioOut2.h
#pragma once
// IEasyAudioOut2
// This is one of EasyAudio COM component's interface
#include "EasyAudio.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyAudio{
	///=======================================================================
	/// Interface IEasyAudioOut2's definition and IID
	///=======================================================================
	// {4221B538-E5F3-450C-9130-EDE82BB22434} 
EASYAUDIO_DEFINE_GUID(IID_IEasyAudioOut2,0x4221B538, 0xE5F3, 0x450C, 0x91, 0x30, 0xED, 0xE8, 0x2B, 0xB2, 0x24, 0x34);
	//___________________________________________________________________________
	MIDL_INTERFACE("4221B538-E5F3-450C-9130-EDE82BB22434")
	IEasyAudioOut2 : public IUnknown
	{
		
		//Get current device's string property.
		//Parameters:
		//	propertyName: the property name can get from GetStringPropertyName().
		//Returns: BSTR value of the property.
		STDMETHOD_(BSTR, GetStringProperty) (LPCTSTR propertyName) PUREV;
		
		// attach IEasyAudioOut2 interface to a audio output device with a list id (AudioOutID).
		//Parameters:
		//	AudioOutID: the range is from 0 to IEasyAudioControl::AODGetCount()-1.
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(Attach)(int AudioOutID)PUREV;

		// attach IEasyAudioOut2 interface to a device output with a FriendlyName.
		//Parameters:
		//	FriendlyName: the friendly name for the device.
		//Returns: if the method succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.
		STDMETHOD(AttachByFriendlyName)(LPCTSTR FriendlyName)PUREV;
		
		//get current volume from DirectShow render device.
		//Parameters:
		//	plVolume:
		//	the volume, as a number from ?0,000 to 0, inclusive. 
		//	Full volume is 0, and ?0,000 is silence. 
		//	Multiply the desired decibel level by 100. For example, ?0,000 = ?00 dB.
		STDMETHOD(GetVolume)(long* plVolume)PUREV;
		
		//set volume for DirectShow render device.
		//Parameters:
		//	lVolume:
		//	specifies the volume, as a number from ?0,000 to 0, inclusive. 
		//	Full volume is 0, and ?0,000 is silence. 
		//	Multiply the desired decibel level by 100. For example, ?0,000 = ?00 dB.
		STDMETHOD(SetVolume)(long lVolume)PUREV;
		
		/* above are the same as IEasyVideoOut
		//====================================================================
		// Below are new methods for IEasyVideoOut2
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
		//	counts of properties.
		STDMETHOD_(int, GetStringPropertyCount) (void) PUREV;

		//get property name via index
		//Parameters:
		//	index: the input index for the property, the index range is from 0 to GetStringPropertyCount()-1;
		//Returns: 
		//	 the return try is the BSTR string for the property name.
		STDMETHOD_(BSTR, GetStringPropertyName) (int index)  PUREV;
		//==========================================================================
	};
};//namespace EasyAudio
