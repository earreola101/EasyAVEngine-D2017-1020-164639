// Defines the entry point for the console application.
//
#include "stdafx.h"
#include "windows.h"
#include "UltimateControl.h"
#include "EasyVideo.h"

//_______________________________________________________________________________

//_______________________________________________________________________________

//_______________________________________________________________________________
CComPtr<UltimateControl::IDevice> pIDevice; 
//_______________________________________________________________________________
void CALLBACK LOG(LPCTSTR msg)
{
	_tprintf(_T("\n%s"),msg);
};
//_______________________________________________________________________________
CString KeyName[15];
DWORD  KeyValFree[15];
DWORD  KeyValPress[15];
//_______________________________________________________________________________
void CALLBACK KeyProc(DWORD key1)
{
	static int count;
	count++;
	_tprintf(_T("\n[%d]. Key Prss!(key code=0x%X)"),count, key1);
	BYTE *pb=(BYTE*)&key1;
	_tprintf(_T("B[2:0]=0x%x,0x%x,0x%x, "), pb[2], pb[1], pb[0]);
	BYTE key=pb[1];
	if(key>=1 && key<=15) _tprintf(_T("%s"),KeyName[key]);
	else _tprintf(_T("Unknown Key!!!"));

	//===========================================
	// Get touch press value
	CComPtr<UltimateControl::IButton> pIUC; 
	pIDevice->QueryInterface(&pIUC);
	DWORD val;
	pIUC->TouchGetValue(key, val); 
	KeyValPress[key]=val;
	_tprintf(_T(", PressValue=0x%X, FreeValue=0x%X, Diff=0x%X"),val, KeyValFree[key], val-KeyValFree[key]);
	_tprintf(_T("...ok!"));

};
//_______________________________________________________________________________
int _tmain(int argc, _TCHAR* argv[])
{
	// below for colossus
	KeyName[LOGI_TOUCH_KEY_HOOK_ON]=_T("KEY_HOOK_ON");
	KeyName[LOGI_TOUCH_KEY_HOOK_OFF]=_T("KEY_HOOK_OFF");
	KeyName[LOGI_TOUCH_KEY_VOL_UP]=_T("KEY_VOL_UP");
	KeyName[LOGI_TOUCH_KEY_VOL_DOWN]=_T("KEY_VOL_DOWN");
	KeyName[LOGI_TOUCH_KEY_LEFT]=_T("KEY_LEFT");
	KeyName[LOGI_TOUCH_KEY_RIGHT]=_T("KEY_RIGHT");
	KeyName[LOGI_TOUCH_KEY_DOWN]=_T("KEY_DOWN");
	KeyName[LOGI_TOUCH_KEY_UP]=_T("KEY_UP");
	KeyName[LOGI_TOUCH_KEY_ZO]=_T("KEY_ZO");
	KeyName[LOGI_TOUCH_KEY_SET]=_T("KEY_SET");
	KeyName[LOGI_TOUCH_KEY_MIC]=_T("KEY_MIC");
	KeyName[LOGI_TOUCH_KEY_ZI]=_T("KEY_ZI");
	KeyName[LOGI_TOUCH_KEY_FAR]=_T("KEY_FAR");
	KeyName[LOGI_TOUCH_KEY_BT]=_T("KEY_BT");

	bool bDemoFirmwareVersion=true;//  MCU1 FW version
	bool bDemoLED=false;
	bool bDemoLCD=false; int LCDStressCount=1000; //[V]:
	bool bDemoASICReadWrite=true; // Conexant ASIC
	bool bDemoButton=false;	 int ButtonStressCount=1; //[V]:
	bool bDemoButtonEvent=false;	 //[V]:
	bool bDemoTouchFirmwareVersion=false; int TouchFirmwareVersionStressCount=5000;
	bool bDemoFlashRW=false;
	//=======================================================================
	CComPtr<EasyVideo::IEVHelper> pCH; 
	CComPtr<EasyVideo::IEVCamera> pCam; 

	HRESULT hr=CoInitialize(NULL);
	pCH.CoCreateInstance(CLSID_EasyVideo);
	pCH.QueryInterface(&pCam);
	pCam->PreviewStart(); 
	//Sleep(2000);

	{
		CString str;
		hr=pIDevice.CoCreateInstance( CLSID_UltimateControl);
		//if(!pIDevice->OpenHIDDevice(0,0x046d, 0x0846)) 
		{
			//LOG(_T("Error OpenHIDDevice!"));
			//if(!pIDevice->OpenHIDDevice(0,0x046d, 0x084B)) 
			if(!pIDevice->OpenHIDDevice(0,0x046d, 0x0857)) 
				return FALSE;  
		}

		{ // set callback log function ...
			CComPtr<UltimateControl::IUniversalControl> pIUC; 
			hr=pIDevice->QueryInterface(&pIUC);
			pIUC->SetLogCallback(LOG); 
		}

		//===============================================================================
		// MCU1 Firmware Version access 
		//===============================================================================
		if(bDemoFirmwareVersion)
		{
			
			
			Version2 Ver;
			if(pIDevice->GetVersion2(0, &Ver)) //MCU
			{
				_tprintf(_T("\n[M]:MCU firmware version=%d.%d.%d"),Ver.major, Ver.minor, Ver.build);
			}	
			else
			{
				_tprintf(_T("\n[E]: cannot read MCU1 firmware version!"));
			}
			//
			if(pIDevice->GetVersion2(1, &Ver)) //Audio chip
			{
				_tprintf(_T("\n[M]:Audio chip firmware version=%d.%d.%d"),Ver.major, Ver.minor, Ver.build);
			}	
			else
			{
				_tprintf(_T("\n[E]: cannot read Audio chip firmware version!"));
			}

		}
		return 0;
		//===============================================================================
		// LED Access 
		//===============================================================================
		DWORD delay=500;
		if(bDemoLED)
		{
			CComPtr<UltimateControl::ILED> pILED; 
			hr=pIDevice->QueryInterface(&pILED);
			_tprintf(_T("\nLED set to RED... "));
			pILED->SetStatus(LED_RED); 
			Sleep(delay);
			//
			_tprintf(_T("\nLED set to Blue... "));
			pILED->SetStatus(LED_BLUE); 
			Sleep(delay);
			_tprintf(_T("\nLED set to Blink... "));
			pILED->SetStatus(LED_BLINK); 
			Sleep(delay);
			//_tprintf(_T("\nLED set to OFF... "));
			//pILED->SetStatus(LED_OFF); 
			Sleep(delay);
		}

		//===============================================================================
		// CxASIC Register Access 
		//===============================================================================
		if(bDemoASICReadWrite)
		{
			CComPtr<UltimateControl::IUniversalControl> pIUC; 
			hr=pIDevice->QueryInterface(&pIUC);
			WORD VolumeMutesAddress=0x1018; //refer Conexant doc page:27
			for(int i=0;i<2;i++)
			{

				_tprintf(_T("\nCxASIC register access... "));
				// write data into CxASIC register
				_tprintf(_T("\n[M]: write data:[0x%X] into CxASIC register."),i);

				if(!pIUC->ASICWriteByte(VolumeMutesAddress,i))

				{
					_tprintf(_T("\n[E]: Failure write CxASIC register with data:[0x%X] "),i);
				}

				//[read register]
				_tprintf(_T("\n Read back Data:"));
				BYTE recvDataBuf=0x00;
				if(!pIUC->ASICReadByte(VolumeMutesAddress, recvDataBuf))
				{
					_tprintf(_T("\n[E]: Failure read CxASIC register... "));
				}
				//
				if(recvDataBuf!=i) 
				{
					_tprintf(_T("\n[E]: Failure access CxASIC register... "));
				}else
				{
					_tprintf(_T("[0x%X] successful!"), recvDataBuf);
				}

			}//for

			//[Cx Firmware Verson]==================================
			{
				BYTE CxFirmwareVerson[4];
				WORD FirmwareVersionAddress=0x1001;

				_tprintf(_T("\n[M]: Conexant ASIC firmware version: "));
				for(int i=0;i<4;i++)
				{
					if(!pIUC->ASICReadByte(FirmwareVersionAddress+i, CxFirmwareVerson[i]))
					{
						_tprintf(_T("\n[E]: Failure read CxASIC register... "));
					}

				}
				_tprintf(_T("%d.%d.%d.%d"),CxFirmwareVerson[1],CxFirmwareVerson[0],CxFirmwareVerson[2],CxFirmwareVerson[3]);


				WORD FirmwarePatchVersionAddress=0x1584;
				BYTE CxFirmwarePatchVerson[3];
				for(int i=0;i<3;i++)
				{
					if(!pIUC->ASICReadByte(FirmwarePatchVersionAddress+i, CxFirmwarePatchVerson[i]))
					{
						_tprintf(_T("\n[E]: Failure read CxASIC register... "));
					}

				}
				_tprintf(_T("\nConexant ASIC Patch version:%x.%x.%x"),CxFirmwarePatchVerson[0],CxFirmwarePatchVerson[1],CxFirmwarePatchVerson[2]);

			}



		}



		//========================================================================
		if(bDemoFlashRW)
		{
			_tprintf(_T("\n[M]: DemoFlashRW..."));
			CComPtr<UltimateControl::IUniversalControl> pIUC; 
			hr=pIDevice->QueryInterface(&pIUC);
			_tprintf(_T("\nTDEDataWrite()..."));
			BYTE Data[12];
			for(int i=0;i<12;i++)
			{
				Data[i]=i; // put a test data
				_tprintf(_T("0x%X, "),Data[i]);
			}

			BOOL b=pIUC->TDEDataWrite(Data);
			for(int i=0;i<12;i++)
				Data[i]=0x00; // put a test data

			b=pIUC->TDEDataRead(Data);
			_tprintf(_T("\nTDEDataRead()..."));
			for(int i=0;i<12;i++)
			{
				_tprintf(_T("0x%X, "),Data[i]);
			}

		}
		//
		//========================================================================
		if(bDemoTouchFirmwareVersion)
		{

			CComPtr<UltimateControl::IButton> pIUC; 
			hr=pIDevice->QueryInterface(&pIUC);
			CString strk;
			int ErrorCount=0;
			for(int i=0;i<TouchFirmwareVersionStressCount;i++)
			{

				BYTE  FirmwareVer[4]; ::RtlZeroMemory( FirmwareVer,4);
				if(!pIUC->GetTouchFirmwareVersion(FirmwareVer)) 
				{
					_tprintf(_T("\n[E]: cannot read touch firmware version!"));
					//return FALSE;  
				}	
				else
				{
					str.Empty();
					/*
					for(int i=0;i<4;i++)
					{
					str.AppendFormat(_T("Byte[%d]=%d, "),i, FirmwareVer[i] );
					}
					_tprintf(_T("\n[M]:Byte order= %s"),str);
					*/
					pVersion p=(Version*)&FirmwareVer;
					str.Format(_T("\n[M]:(%d)."),i);_tprintf(str);
					str.Empty();
					str.AppendFormat(_T("Touch firmware version=%d.%d.%d"),p->major, p->minor, p->build);_tprintf(str);
					if(i>0)
						if(str!=strk)
						{
							ErrorCount++;
							_tprintf(_T("\n[W]:ErrorCount=%d, Error Ratio=%d %%"),ErrorCount ,(ErrorCount*100)/TouchFirmwareVersionStressCount);
						}
						strk=str;



				}
			}//[end]:if
			_tprintf(_T("\n[W]:ErrorCount=%d, Error Ratio=%d %%"),ErrorCount ,(ErrorCount*100)/TouchFirmwareVersionStressCount);
		}



		if(bDemoButton)
		{
			//===========================================
			// Get touch press value
			BYTE key;
			CComPtr<UltimateControl::IButton> pIUC; 
			pIDevice->QueryInterface(&pIUC);
			DWORD val;
			int ErrorCount=0;

			for(int n=0;n<ButtonStressCount;n++)
			{
				_tprintf(_T("\n\nCycle=%d, scan all touch button values..."), n);
				for(int i=1;i<=14;i++)
				{
					BOOL b=pIUC->TouchGetValue(i, val); 
					if(b)
					{

					 //
						if(val>1000 || val<=0)
					 {
						 _tprintf(_T("\n[E]:[%d]. %s Value=%d"), i, KeyName[i], val);						
						 _tprintf(_T("=>>>Error!!"));
						 ErrorCount++;					 
					 }
						else
						{
							_tprintf(_T("\n[M]:[%d]. %s Value=%d"), i, KeyName[i], val);						
						}

					}
					else
						_tprintf(_T("\n[M]:[%d]. %s Value=Error read!"), i, KeyName[i]);

					KeyValFree[i]=val;
					KeyValPress[i]=0;
				}
				//
				_tprintf(_T("\n[W]:ErrorCount=%d, Error Ratio=%d %%"),ErrorCount ,(ErrorCount*100)/ButtonStressCount);
			}





		}

		//===============================================================================
		// LCD Access 
		//===============================================================================
		if(bDemoLCD)
		{
			CComPtr<UltimateControl::ILCM> pILCD; 
			hr=pIDevice->QueryInterface(&pILCD);


			CString fname;
			CString dirr(_T("d:\\temp\\LCDLife\\"));
			CreateDirectory(dirr,0); 
			for(int i=0;i<LCDStressCount;i++)
			{
				_tprintf(_T("\n(%d).LCD set to ColorBar... "),i);
				pILCD->SetPattern(0); 
				fname.Format(_T("ColorBar(%d).bmp"),i);
				pCam->VideoFrameSave( EasyVideo::FrameBeforeRender, dirr+fname);
				//Sleep(delay);			
				//
				_tprintf(_T("\n(%d).LCD set to Mono... "),i);
				pILCD->SetPattern(1,0,255); 
				fname.Format(_T("Mono(%d).bmp"),i);
				pCam->VideoFrameSave( EasyVideo::FrameBeforeRender, dirr+fname);
				//Sleep(delay);
				//
				_tprintf(_T("\n(%d).LCD set to Border Pattern... "),i);
				pILCD->SetPattern(2,60);
				fname.Format(_T("Border(%d).bmp"),i);
				pCam->VideoFrameSave( EasyVideo::FrameBeforeRender, dirr+fname);			 			
				//Sleep(delay);
			}
			//
		}

		//====================================================================
		if(bDemoButtonEvent)
		{
			CComPtr<UltimateControl::IButton> pIUC; 
			hr=pIDevice->QueryInterface(&pIUC);

			pIUC->SetKeyCallback(KeyProc); 
			WORD kc;DWORD  KeyCapVal;
			// loop to wait and process callback data
			// start press touch key and see the console output key code into the KeyProc function

			::Beep(500,100); 
			_tprintf(_T("\n[M]: start press touch key and see the console output key code...(exit after 20 sec)"));

			for(int i=0;i<2000;i++)// 
			{
				//Sleep(3);
				pCH->SleepEx(10);
			}
			_tprintf(_T("\n[M]: reach 20 seconds, exit."));
			_tprintf(_T("\n[M]: Touch key test result:"));
			_tprintf(_T("\n[ID], KeyName, Press, Free, Diff"));
			for(int i=1;i<=14;i++)
			{
				_tprintf(_T("\n[%d], %s , %u, %u, %u"), i, KeyName[i], KeyValPress[i], KeyValFree[i],  KeyValPress[i]-KeyValFree[i]);
			}


			_tprintf(_T("\n[M]: end of touch key test."));
		}


		pIDevice->CloseHID(); 
		pIDevice.Release(); 
	}

	::CoUninitialize(); 
	_tprintf(_T("\n\nPress enter key to exit,... "));

	::getchar(); 
	return 0;
}
