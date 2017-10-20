#pragma once
#include "EasyLensMotor.h"
#include "PIStatus.h"
//___________________________________________________________________________________________
//
class CZoomFocusMotor
{

public:
    CComPtr<EasyLensMotor::IMotorControl> pMC; 
	CComPtr<EasyLensMotor::IMotorControlAdvanced> pMCA; 
	HRESULT hr;
	CZoomFocusMotor(void);
	~CZoomFocusMotor(void);
	int RunTestBacklash(void);	
	
	bool m_bLog;
	int SetLog(bool bLog);	
	int BacklashOutputTimes;
	int SingleStep;
	int m_Backlash[1000];
	int m_BacklashCount;
	CPIStatus PI;
	int TotalMovingCount;
	int DelayTime;
	int PassedCountDef;
	int AllowMaxBacklashOutputTimes;
	TCHAR ch[255];
	int m_PISamplingCount;
	int m_PISamplingDelay;
	int BacklashGetAvg(void);
	int m_Direction;
	
	double ratio;
	CString str;
	void DirectionSetToGotoPI(int PIvalue);
	int iDir;
	int RunMoveLens(void);
};
//___________________________________________________________________________________________

