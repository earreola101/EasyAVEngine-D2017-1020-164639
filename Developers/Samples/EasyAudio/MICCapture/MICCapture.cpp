// MICCapture.cpp : Defines the entry point for the console application.
#pragma once
#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "EasyAudio.h"
#include "UserMessages.h"// a error message handling class to show message string
//================================================================================================
enum MsgIDList
{
  MIC_CAPTURE_OK=0,//
  EasyAudioWarningCreateInstance,//
  EasyAudioWarningSetAudioSource,
  EasyAudioWarningSetAudioOutDevice,
  EasyAudioWarningSetAudioOutWaveFile
};
//================================================================================================
CUserMessages::MsgType ErrorMsg[]=
{
	{MIC_CAPTURE_OK,_T("\nSuccess: MIC Capture ok!\n Please see the output wavefile.")},
	{EasyAudioWarningCreateInstance,_T("\nWarning: CoCreateInstance(): Can't Create EasyAudio component Object.\n Please run: RegSvr32 EasyAudioDRU.dll")},
	{EasyAudioWarningSetAudioSource,_T("\nWarning: Please check SetAudioSource()'s arguments.")},
	{EasyAudioWarningSetAudioOutDevice,_T("\nWarning: Please check SetAudioOutDevice()'s arguments.")},
	{EasyAudioWarningSetAudioOutWaveFile,_T("\nWarning: Please check SetAudioOutWaveFile()'s arguments.")},
};


// =============================================================================================================
int _tmain(int argc, _TCHAR* argv[])
{
	// a error message handling class to show message string
	CUserMessages umsg(_T("EasyAudio MIC Capture Ver 0.1, 2011-06"),ErrorMsg, sizeof(ErrorMsg) / sizeof(ErrorMsg[0]));
//================================================================================================
//[Start]: Configuration for MIC capture
//================================================================================================
//LPTSTR sMICFriendlyName=_T("麥克風 (5- Webcam C260)");
//LPTSTR sMICFriendlyName=_T("麥克風 (Webcam C170)");
LPTSTR sMICFriendlyName=_T("EasyAudioSource");
WORD nChannel=1;
WORD nBits=16;
WORD nSamplesPerSec=16000;
double Volume=1.0;
DWORD DelaySamplingCount=000;
DWORD SamplingCount=8192;
LPTSTR OutputWavefilename=_T("Ch(1)_Bits(16)_Rate(16000)_Samples(8192).wav");
//================================================================================================
//[End]:Configuration for MIC capture
//================================================================================================
_tprintf(_T("\n[Test Case]: MIC in and output to wavefile"));
{
	CoInitialize(NULL);

	EasyAudio::IEasyAudioControl * pEAC=NULL;
	DWORD MsgID=0;
	HRESULT hr=CoCreateInstance( CLSID_EasyAudio,NULL,CLSCTX_INPROC_SERVER,EasyAudio::IID_IEasyAudioControl,(void**) &pEAC);
	{
		if(FAILED(hr)) {MsgID=EasyAudioWarningCreateInstance;}
		if(SUCCEEDED(hr)){
			pEAC->AIDGetCount();// Enumerate and get the amount of AID(audio input device) in the system.
			pEAC->AODGetCount();// Enumerate and get the amount of AOD(audio output device) in the system.
		}
		
		// =============================================================================================================
		// Audio Source: USB audio Device
		if(SUCCEEDED(hr)) {
			hr= pEAC->SetAudioSource(sMICFriendlyName,nChannel/*channel*/,nBits/*bits*/,nSamplesPerSec,Volume/*volume*/);
			if(FAILED(hr)) {MsgID=EasyAudioWarningSetAudioSource;}
		}// =============================================================================================================
		// Audio Out: Speaker device: No specified
		if(SUCCEEDED(hr)) {
			hr= pEAC->SetAudioOutDevice(_T(""),0); // Full volume is 0, and –10,000 is silence. 
			if(FAILED(hr)) {MsgID=EasyAudioWarningSetAudioOutDevice;}
		}// =============================================================================================================
		// Audio output wavefile: 
		if(SUCCEEDED(hr)) 
		{
			hr= pEAC->SetAudioOutWaveFile(OutputWavefilename,DelaySamplingCount,SamplingCount);
			if(FAILED(hr)) {MsgID=EasyAudioWarningSetAudioOutWaveFile;}
		}
		// =============================================================================================================
		//             (DelaySamplingCount)                   (SamplingCount)
		//[Play Audio]-------------------->[Auto Start Capture]----------->[Auto Stop Capture]-->[Stop play]--->[return]
		if(SUCCEEDED(hr)) hr=pEAC->Play(TRUE); // play=>wait=>stop
		// =============================================================================================================
        // Output Result:
		umsg.SimpleMsgByID(MsgID);// show the result msaage string
		if(pEAC!=NULL) pEAC->Release();/// Release resource
	}
	  CoFreeUnusedLibraries();
	CoUninitialize();
}
	return 0;
}
