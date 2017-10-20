// Defines the entry point for the console application.
//
#include "stdafx.h"
#include "windows.h"
#include "EasyAVEngine.h"
#include <math.h>
//
#ifndef OrbitAliLedAdr
//
//#define OrbitAliLedAdr 0x0002 // refer from Conexant SDK version CxAudioHidCli_1.0.7.0 and tested
#define OrbitAliLedAdr 0x0002 // refer from Conexant SDK version CxAudioHidCli_1.0.7.0 and tested
#define OrbitAliMuteAccessAdr 0x1018 // 
#define OrbitAliButtonAdr 0x1009 // refer from Conexant SDK version CxAudioHidCli_1.0.7.0 and tested
#define OrbitAliProductionLineSnAdr 0x00003F80 // refer from Conexant William's email
//#define OrbitAliAudioDspEnableAdr  // refer from Conexant William's email
//
#endif
/*
Write : 0x117C = 0x82
Read: 0x117D
Then Write 0x117D with value you got from the Read, but set the last bit to 1.
*/






//==========================================================================
// some helper functons for the sample code
void PrintBinary(BYTE b);
void FormatBytes(DWORD nSize, BYTE *pValue);
void MakeDataBytes(DWORD nSize, BYTE *pValue, BYTE b, bool bByteDiff);
//==========================================================================
// main 
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace EasyControl;


	BOOL bRet=FALSE;
	HRESULT hr;
	CoInitialize(NULL);
	{

		CString str;
		//===============================================================================
		// Create first COM instance
		CComPtr<EasyControl::IDeviceControl> pDC; 
		hr=pDC.CoCreateInstance( CLSID_EasyControl);
		if(pDC==NULL)
		{
#if defined(_UNICODE) 
			_tprintf(_T("\nPlease register EasyControlDRU.dll into system first."));
			_tprintf(_T("\nRun: regsvr32.exe EasyControlDRU.dll"));
#else
			_tprintf(_T("\nPlease register EasyControlDRM.dll into system first."));
			_tprintf(_T("\nRun: regsvr32.exe EasyControlDRM.dll"));
#endif

			::getchar(); 
			return 0;
		}
		DECLARE_STRING(sValue,MAX_PATH);		
		DECLARE_STRING(sName,MAX_PATH);		
		//===============================================================================
		// List Device basic infomration
		//===============================================================================

		if(pDC->IsDeviceConnected()==TRUE)
		{
			_tprintf(_T("\nDevice connexted!"));
			_tprintf(_T("\nList All Device Information!"));
			for(UINT i=0;i<pDC->DeviceStringGetCount() ;i++)
			{
				pDC->DeviceStringGet(i, sValue);
				pDC->DeviceStringNameGet(i,sName);
				_tprintf(_T("\n[%u].%s: "),i, sName);
				_tprintf(_T("%s"), sValue);
			}
		}//[endof]:if( pDC->IsDeviceConnected()
		else
		{
			_tprintf(_T("\nDevice not found!"));
		}
		BYTE b;



		//=========================================================================
		// EEPROM W/R for production serial number
		//=========================================================================
		{
			_tprintf(_T("\n\nEEPROM for Serial Number R/W test,..."));
			DWORD nSize=64;        
			BYTE *pValue=new BYTE[nSize];
			BYTE *pByteWrite=new BYTE[nSize];
			//=============================================================
			_tprintf(_T("\nRead current data in Eeprom..."));
			pDC->EepromRead(OrbitAliProductionLineSnAdr, nSize, pValue);		   
			FormatBytes(nSize, pValue);

			//=============================================================
			_tprintf(_T("\n\nMake new data and write to  Eeprom..."));
			MakeDataBytes(nSize, pByteWrite , 0xff, true);
			_tprintf(_T("\nWrite data into EEprom..."));
			pDC->EepromWrite(OrbitAliProductionLineSnAdr, nSize, pByteWrite);
			FormatBytes(nSize, pByteWrite);

			//=============================================================
			_tprintf(_T("\nRead current data in Eeprom..."));
			pDC->EepromRead(OrbitAliProductionLineSnAdr, nSize, pValue);		   
			FormatBytes(nSize, pValue);

			//=============================================================
			_tprintf(_T("\nVerify writed data..."));
			bool bTest=true;
			for(DWORD i=0;i<nSize;i++)
			{
				if(pValue[i]!=pByteWrite[i])
			 {
				 _tprintf(_T("\nByte[%d]..error!"),i);
				 bTest=false;
			 }
			}
			if(bTest==false)
				_tprintf(_T("\nEeprom access error!"));
			else
				_tprintf(_T("\nEeprom access ok!"));

			delete pByteWrite;
			delete pValue;

		}

		//=========================================================================
		// MUTE LED Set Status:
		//=========================================================================
		_tprintf(_T("\nPress enter key to start Mute LED test..."));
		::getchar(); 
		{
			_tprintf(_T("\n\nMute LED test..."));
			_tprintf(_T("\nMute LED ON..."));
			pDC->RegisterWriteBitFieldInByte(OrbitAliMuteAccessAdr , 3, 3, 1);
			_tprintf(_T("\nPress enter key to turn Mute LED OFF..."));
			::getchar(); 
			_tprintf(_T("\nMute LED OFF..."));
			pDC->RegisterWriteBitFieldInByte(OrbitAliMuteAccessAdr, 3, 3, 0);

		}

		//=========================================================================
		// Audio DSP Disable
		//=========================================================================
		{
			CComPtr<EasyControl::IAudioDeviceControl > pADC;
			hr=pDC.QueryInterface(&pADC);
			_tprintf(_T("\n\nDisable Audio Dsp,..."));
			
			if(pADC->AudioDspDisable()==TRUE)
				_tprintf(_T("Ok!"));
			else
				_tprintf(_T("Fail!"));
            //==================================
			//==============================================================================================
			_tprintf(_T("\nPress enter key to start Mute LED test via IAudioDeviceControl interface..."));
			::getchar(); 

			{
				_tprintf(_T("\n\nMute LED test..."));
				_tprintf(_T("\nMute LED ON..."));
				pADC->MuteLedSet(TRUE);
				_tprintf(_T("\nPress enter key to turn Mute LED OFF..."));
				::getchar(); 
				_tprintf(_T("\nMute LED OFF..."));
				pADC->MuteLedSet(FALSE);

			}
			//==========================================================================
			_tprintf(_T("\n\nRead Buttons and LEDs status,..."));
			pDC->RegisterReadByte( OrbitAliButtonAdr,&b);
			_tprintf(_T("[0x%X]"),b);
			for(int i=0;i<eAudioStatusCount;i++)
			{

				if(pADC->GetStatusRWType(i) == EasyControl::Read)
				{
					pADC->GetStatus2String(i,sValue);
					pADC->GetStatusName(i,sName);					

					_tprintf(_T("\n[%d].Value(%d), %s, BitPosition=%d, Address=0x%X, %s"),i,  
						pADC->GetStatus(i),
						sValue,
						pADC->GetStatusBitPosition(i),
						pADC->GetStatusAddress(i), 
						sName
						); 
				}
			}

		}

		//=========================================================================
		// Hook LED set status:
		{

		}


	}
	_tprintf(_T("\n\nDisconnected from Conexant HID device..."));
	::CoUninitialize(); 
	_tprintf(_T("\n\nPress enter key to exit,... "));
	::getchar(); 
	return 0;
}

//==============================================================================================
void FormatBytes(DWORD nSize, BYTE *pValue)
{
	_tprintf(_T("\nDump Eeprom data with %d bytes... \n"),nSize);		

	for(int i=0;i<nSize;i++)
	{
		if((i-(i/16)*16)==0 &&i>0) _tprintf(_T("\n"));		
		_tprintf(_T("%2X, "),pValue[i]);		

	}

}

//==============================================================================================
void MakeDataBytes(DWORD nSize, BYTE *pValue, BYTE b, bool bByteDiff)
{
	if(bByteDiff)
	{
		for(int i=0;i<nSize;i++)
		{
			pValue[i]=i;
		}
	}
	else
	{
		for(int i=0;i<nSize;i++)
		{
			pValue[i]=b;
		}
	}
}

//==============================================================================================
void PrintBinary(BYTE b)
{
	CString str1,BF,bbf,str;
	str.Empty(); 
	BF.Empty();
	for(int i=0;i<8;i++)
	{
		bbf.Format(_T("[%d]"),i);
		BF=bbf+BF;
	}
	_tprintf(_T("\nBinary=%s"),BF);
	for(int i=0;i<8;i++)
	{
		str1.Format(_T("[%d]"), ( b& (long) pow(2.0,(long)i))>0);
		str=str1+str;
	}
	_tprintf(_T("\nBinary=%s"),str);

}