// Defines the entry point for the console application.
//
#include "stdafx.h"
#include "windows.h"

#include "ZoomFocusMotor.h"
int _tmain(int argc, _TCHAR* argv[])
{
	
	CoInitialize(NULL);

	//[Start]:Configuration (1)
	LPCTSTR DeviceName=_T("USB Video Device");
	LPCTSTR MotorType=_T("Focus");
	//LPCTSTR MotorType=_T("Zoom"); 
	bool EnableDetailLogMesage=true;
	int Cycles=1;
	int DelayTime=50;
	//[End]:Configuration (1)
	bool ret;

	for(int i=0;i<Cycles;i++)
	{
		_tprintf(_T("\nSingleStep=%3d"),i+1);
		{
			CZoomFocusMotor zf;
			//[Start]:Configuration (2)
			zf.PassedCountDef=5;
			// Stop Conditions
			zf.AllowMaxBacklashOutputTimes=4;
			zf.TotalMovingCount=zf.PassedCountDef*30;
			zf.SetLog(EnableDetailLogMesage);
			zf.DelayTime=DelayTime;
			ret=zf.pMC->ConnectToDevice(DeviceName);
			if(ret==FALSE) break;
			zf.pMCA->MotorTypeSetByName(MotorType);		
			//
			zf.SingleStep=1;

			//zf.SingleStep=i+1;
			zf.RunTestBacklash();
		}
	}

	::CoUninitialize(); 
	_tprintf(_T("\n\nPress enter key to exit,... "));
	::getchar(); 
	return 0;
}
