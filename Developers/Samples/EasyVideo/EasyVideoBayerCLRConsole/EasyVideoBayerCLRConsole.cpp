// EasyVideoCLRConsole.cpp : main project file.

#include "stdafx.h"
#include <windows.h>
#include <TChar.h>
#pragma comment(lib, "Ole32.lib")
//#define _WIN32_WINNT 0x501
#include "atlstr.h"
#include "EasyAVEngine.h"
#using <mscorlib.dll>
using namespace System;
int count=0;
extern "C" void mainCRTStartup();


//=========================================================================================
[System::STAThread]
int MyMain()  //the new entry point
{
	HRESULT hr = CoInitialize(0);//Initialize COM
	mainCRTStartup();//Initialize the CRT
	CoUninitialize();
	return 0;
}
//=========================================================================================
int TakeQuickBayerSnapShot();
int TakeQuickBayerSnapShot2016(CString BayerConfiguration);
//=========================================================================================
//int main(array<System::String ^> ^args)
int main()
{

	Console::WriteLine(L"Hello Welcome to EasyVideo World...");
	::System::String ^str;

	{	DWORD id = ::GetCurrentThreadId(); Console::WriteLine(); }
	Console::WriteLine(L"\nStarting stress test with bayer preview...");
	//int TestCount=200000;
	int TestCount = 2;
	for (int i = 0; i < TestCount; i++)
	{
		Console::WriteLine(str->Format("\nTestCount:{0:D}", i));
		//TakeQuickBayerSnapShot();

#define Bolide2017		
//#define BRIO

#ifdef Bolide2017
		TakeQuickBayerSnapShot2016(_T("VID(46d).PID(881).SensorID(0).Mode(YUY2inMJPG)"));// for YUY2 in MJPG container
		TakeQuickBayerSnapShot2016(_T("VID(46d).PID(881).SensorID(0)")); // for Sensor Bayer Mode
#endif

#ifdef BRIO		
		// for IR sensor
		//TakeQuickBayerSnapShot2016(_T("VID(46d).PID(85E).SensorID(1)"));

		// for 4K sensor
		TakeQuickBayerSnapShot2016(_T("VID(46d).PID(85E).SensorID(0)"));
#endif

	}

	return 0;
}
//=========================================================================================
int TakeQuickBayerSnapShot()
{
	HRESULT hr;
	EasyVideo::IEVCamera  *pCamera = NULL;
	hr = CoCreateInstance(CLSID_EasyVideo, NULL, CLSCTX_INPROC_SERVER, EasyVideo::IID_IEVCamera, reinterpret_cast<void**> (&pCamera));
	if (pCamera == NULL)	return 0;
	EasyVideo::IEVBayer3 *pEVB = NULL;
	pCamera->QueryInterface(EasyVideo::IID_IEVBayer, reinterpret_cast<void**> (&pEVB));
	bool bEnableBayer;
	int BBP, BMode;
	pEVB->GetBayer(bEnableBayer, BBP, BMode);// get device bayer mode

#define BAYER_MODE
#ifdef BAYER_MODE
	BMode = 5;// for babylon set this for IR and 4K sensor
	pEVB->SetBayer(true, BBP, BMode);/*enable bayer mode.*/ Sleep(1000);
	hr = pCamera->FormatSet(EasyVideo::MEDIASUBTYPE_YUY2, 640, 480);	Sleep(100);
	//SetBayerConfiguration
	//hr=pCamera->FormatSet(EasyVideo::MEDIASUBTYPE_YUY2,1920,1080);	Sleep(500);
#else
	pEVB->SetBayer(false,BBP,BMode);// enable bayer mode.
	hr=pCamera->FormatSet(EasyVideo::MEDIASUBTYPE_YUY2,640,480);
#endif	
	::System::String ^str;
	pEVB->Release();
	DWORD t1, t2, elapsed; t1 = ::GetTickCount();
	hr = pCamera->VideoFrameSetProcessingFunction(NULL, 0);
	{	DWORD id = ::GetCurrentThreadId(); Console::WriteLine(str->Format("\nThreadID:{0:D}", id)); }
	Console::WriteLine(str->Format("\nStrat Preview Bayer..."));
	hr = pCamera->PreviewStart(); Sleep(500);
#define USING_IEVHelper
#ifdef USING_IEVHelper
	//=====================================================================
	//In CLR Console or Native Console app, it should uses IEVHelper::SleepEx() to replace the Sleep();
	//=====================================================================
	Console::WriteLine(str->Format("\nDelay 2000 mSeconds."));
	//if(false)
	{
		EasyVideo::IEVHelper *pEH = NULL;
		hr = pCamera->QueryInterface(EasyVideo::IID_IEVHelper, reinterpret_cast<void**> (&pEH));
		pEH->SleepEx(6000);
		pEH->Release();
	}
#else
	Sleep(5000);// don't use the Sleep() in console mode with EasyVideo , it will lock your preview window.
#endif
	t2 = GetTickCount();  elapsed = t2 - t1;

	Console::WriteLine(str->Format("\nTotal Duration Time:{0:D} mSec", elapsed));
	if (pCamera->IsPreviewing())
	{
		//hr=pCamera->VideoFrameSave(EasyVideo::FrameBeforeRender,_T(""));
		CString strr;
		strr.Format(_T("Bayer(%d).bmp"), count);
		// hr=pCamera->VideoFrameSave(EasyVideo::FrameBeforeRender, strr) ;
		count++;

	}
	{	DWORD id = ::GetCurrentThreadId(); Console::WriteLine(str->Format("\nThreadID:{0:D}", id)); }
	Console::WriteLine(str->Format("\nPreviewStop..."));
	hr = pCamera->VideoFrameSetProcessingFunction(NULL, 0);
	hr = pCamera->PreviewStop(); Sleep(500);
	hr = pCamera->VideoFrameSetProcessingFunction(NULL, 0);
	Console::WriteLine(str->Format("...ok!"));
	pCamera->Release(); pCamera = NULL;
	return 0;
}


//=========================================================================================
HRESULT hr;

//

//=========================================================================================
void DelayMessage(EasyVideo::IEVCamera3  *pCamera, DWORD msec)
{
	//=====================================================================
	//In CLR Console or Native Console app, it should uses IEVHelper::SleepEx() to replace the Sleep();
	::System::String ^str;
	Console::WriteLine(str->Format("\nDelay..."));
	{
		EasyVideo::IEVHelper *pEH = NULL;
		hr = pCamera->QueryInterface(EasyVideo::IID_IEVHelper, reinterpret_cast<void**> (&pEH));
		pEH->SleepEx(msec);
		pEH->Release();
	}

}
//=========================================================================================
int TakeQuickBayerSnapShot2016(CString BayerConfiguration)
{
	EasyVideo::IEVCamera3  *pCamera = NULL;
	hr = CoCreateInstance(CLSID_EasyVideo, NULL, CLSCTX_INPROC_SERVER, EasyVideo::IID_IEVCamera3, reinterpret_cast<void**> (&pCamera));
	if (pCamera == NULL)	return 0;
	//Set Bayer 
	{
		EasyVideo::IEVBayer3 *pEVB = NULL;
		pCamera->QueryInterface(EasyVideo::IID_IEVBayer3, reinterpret_cast<void**> (&pEVB));
		pEVB->SetBayerConfiguration(BayerConfiguration);
		pEVB->Release();
	}

	{
		pCamera->PreviewWindowSet(0);
		pCamera->PreviewStyleSet(3);
	}
	::System::String ^str;
	hr = pCamera->VideoFrameSetProcessingFunction(NULL, 0);
	Console::WriteLine(str->Format("\nStrat Preview ..."));
	hr = pCamera->PreviewStart();
	DelayMessage(pCamera, 10000);

	if (pCamera->IsPreviewing())
	{
		double fp;	pCamera->FrameRateGet(fp);
		WORD PID;  pCamera->GetPID(PID);
		CString strr;	strr.Format(_T("PID(%X)-Image(%d)-FPS(%2.1f).bmp"), PID, count, fp);
		hr = pCamera->VideoFrameSave(EasyVideo::FrameBeforeRender, strr);
		count++;
	}
	DelayMessage(pCamera, 1000);
	Console::WriteLine(str->Format("\nPreviewStop..."));

	hr = pCamera->PreviewStop(); 

	Console::WriteLine(str->Format("...ok!"));
	DelayMessage(pCamera, 2000);
	pCamera->Release(); 
	pCamera = NULL;

	return 0;
}


