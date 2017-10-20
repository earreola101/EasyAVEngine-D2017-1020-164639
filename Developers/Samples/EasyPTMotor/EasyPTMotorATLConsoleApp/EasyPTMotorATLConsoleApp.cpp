#include "stdafx.h"
#include "windows.h"
#include "EasyPTMotor.h"
int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr; BOOL ret; CString str;	BYTE pi; WORD t,c;
	CString FMT(_T("\n[%d].PI(0x%X), Duration(%d)(0x%X), Counter(%d)(0x%X)"));
	CoInitialize(NULL);
	{
		CComPtr<EasyPTMotor::IDevice> pIDev; 
		CComPtr<EasyPTMotor::IPanMotor> pIP; 
		CComPtr<EasyPTMotor::ITiltMotor> pIT; 
		hr=pIDev.CoCreateInstance( CLSID_EasyPTMotor);
		bool ret=pIDev->ConnectToDevice(_T("Logitech ConferenceCam CC3000e"));
		if(!ret) 
		{
			_tprintf(_T("\n[E]. cannot connect to device!")); return FALSE;
		}
		pIDev.QueryInterface(&pIP); 
		pIDev.QueryInterface(&pIT); 
		//=======================================================================================
		// MCU2 firmware version 
		{
			BYTE Mcu2Ver[5];
			::RtlZeroMemory(Mcu2Ver,5); 
			BOOL b=pIDev->XUDIGetSelector11(&Mcu2Ver[0]); 
			_tprintf(_T("\n[M]:MCU2 Firmware version=")); 
			WORD *pW=(WORD *)&Mcu2Ver[3];
			_tprintf(_T("%d.%d.%d"), Mcu2Ver[2], Mcu2Ver[1],*pW); 

		}

		//=======================================================================================
		// Get Device Information All
		{
			TCHAR DI[1256];
			::RtlZeroMemory(DI,1256); 
			BOOL b=pIDev->XUDIGetAll(&DI[0]); 
			_tprintf(_T("\n[M]:Get Device Information All=%s"), DI); 
			
		}


		_tprintf(_T("\nMove Pan Motor..."));
		pIP->Move(Pan_CW,2000);  pIP->Stop();
		for(int i=0;i<2;i++)
		{
			ret=pIP->PIGet(pi);
			ret=pIP->GetDuration(t);
			ret=pIP->GetCounter(c);
			short int cs=(short int)c;
			_tprintf(FMT,i, pi,t,t ,cs,cs);
		}
		_tprintf(_T("\nMove Tilt Motor..."));
		pIT->Move(Tilt_Up,2000); pIT->Stop(); 
		for(int i=0;i<2;i++)
		{
			ret=pIT->PIGet(pi);
			ret=pIT->GetDuration(t);
			ret=pIT->GetCounter(c);
			short int cs=(short int)c;
			_tprintf(FMT,i, pi,t, t,cs,cs);
		}


		



	}
	::CoUninitialize(); 
	_tprintf(_T("\n\nPress enter key to exit,... ")); ::getchar(); 
	return 0;
}
