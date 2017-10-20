#include "stdafx.h"
#include "ZoomFocusMotor.h"
//___________________________________________________________________________________________
CZoomFocusMotor::CZoomFocusMotor(void)
{
	m_bLog=false;
	BacklashOutputTimes=0;
	m_BacklashCount=-1;
	m_PISamplingCount=10; 
	m_PISamplingDelay=5;  //mSecond
	SingleStep=1;
	PI.SetStatus(0);
	m_Direction=0x01;

	hr=pMC.CoCreateInstance(CLSID_EasyLensMotor);
	if(pMC==NULL) 
	{
		CString str(_T("\nPlease run RegSvr32 EasyLensMotorXXX.dll first."));
		_tprintf(str); 
		::MessageBox(0,str,_T("EasyLensMotor Error!"),0);
		return;
	}
    hr=pMC->QueryInterface(&pMCA);
	RtlZeroMemory(ch,255); 
}
//___________________________________________________________________________________________
CZoomFocusMotor::~CZoomFocusMotor(void)
{
	for(int i=0;i<=m_BacklashCount;i++)
	{
		_tprintf(_T("\n(%2d).Backlash= %3d x MovingSteps(%d) (Steps)"),i+1, m_Backlash[i], SingleStep);	
	}
}
//___________________________________________________________________________________________
int CZoomFocusMotor::SetLog(bool bLog)
{
	m_bLog=bLog;
	return m_bLog;
}
//______________________________________________________________________________________________________________
int CZoomFocusMotor::BacklashGetAvg(void)
{
	int sum=0;
	for(int i=0;i<m_BacklashCount;i++)
	{
		sum=sum+m_Backlash[i];
	}
	return sum/m_BacklashCount;
};
//______________________________________________________________________________________________________________
void CZoomFocusMotor::DirectionSetToGotoPI(int PIvalue)
{
	if(PIvalue==0) {pMC->DirectionSet(0x01);iDir=1;}
	if(PIvalue==1) {pMC->DirectionSet(0x02);iDir=-1;}
}
//___________________________________________________________________________________________
int CZoomFocusMotor::RunTestBacklash(void)
{			
	int count=0; // 
	int PassedCount=0;
	int PassedCountDiff=1;
	int PositionIndex=0;
	BOOL ret=FALSE;
	PI.SetStatus( pMCA->GetPIStatus(true,m_PISamplingCount, m_PISamplingDelay,ratio) );
	_tprintf(_T(", PI(%d)Ratio=%3.1f %%"),PI.Status() , ratio);
	//=================================================

	int flag=0;	
	// refer PIStatus to init moving directon to goto PI
	DirectionSetToGotoPI(PI.Status());
	//
	for(int i=0; i<TotalMovingCount; i++)
	{  
		
		PI.SetStatus( pMCA->GetPIStatus(false, m_PISamplingCount, m_PISamplingDelay,ratio) );
		_tprintf(_T(", PI(%d)Ratio=%3.1f %%"),PI.Status() , ratio);
		
if(PI.IsPIStatusChanged()) { 
			flag=1; 
			PassedCountDiff=1;
			PositionIndex=0;
			PI.m_StatusNeverChanged=false;
		}
		if( abs(PassedCount)>=PassedCountDef) 
		{
			PassedCountDiff=-1;
			PassedCount=0;
			flag=0;				
		}
		//
		PositionIndex=PositionIndex+PassedCountDiff;
		if(flag==1)
		{
			PassedCount=PassedCount+PassedCountDiff;
			if(PassedCount==0) {flag=0;}
		}
		
		//
		if(flag==0)
		{
			DirectionSetToGotoPI(PI.Status());
		}
		//
		RtlZeroMemory(ch,255); pMCA->DirectionGetString(ch); str=ch;
		pMC->MovingStepsSet(SingleStep); 
		pMC->MoveMotor(); 
		Sleep(DelayTime);
	
		
		//=====================================================		 

		if(PI.IsPIStatusChanged())
		{				
			if(BacklashOutputTimes!=0)
			{
				int bl=(count-2*PassedCountDef);
				_tprintf(_T("\n=> Backlash= %d x MovingSteps (Steps)"),bl);	
				m_BacklashCount++;
				m_Backlash[m_BacklashCount]=bl; 
			}
			BacklashOutputTimes++;
			if(BacklashOutputTimes>AllowMaxBacklashOutputTimes) break;
			count=1;
			_tprintf(_T("\n[PI Status Changed]..."));	
		}
		else
		{
			count++; 
		}
		//---------------------------------------------------------------------------------------------
		if(m_bLog)
		{

			RtlZeroMemory(ch,255); pMCA->MoveMotorGetStatusString(ch); str=ch;				
			_tprintf(_T("\n(%5d).PI(%s)=%d(%4d), PassedCount=%3d, PP(%d) Flag(%2d), MovingCmd:%s"),i+1, PI.GetPIString(), PI.Status(), count, PassedCount*iDir, PositionIndex*PI.GetPIDomain(), flag, str);
		}
	}//for

	if(PI.m_StatusNeverChanged==true)
	{
		ret=FALSE;
	}
	return ret;// 
}
//______________________________________________________________________________________________________________
int CZoomFocusMotor::RunMoveLens(void)
{

PI.SetStatus( pMCA->GetPIStatus(true,m_PISamplingCount, m_PISamplingDelay,ratio) );
_tprintf(_T("\nPI(%d)Ratio=%3.1f %%"),PI.Status() , ratio);
//
       pMC->DirectionSet(m_Direction); 
        RtlZeroMemory(ch,255); pMCA->DirectionGetString(ch); str=ch;
		pMC->MovingStepsSet(SingleStep); 
		pMC->MoveMotor(); 
		_tprintf(_T("\nMove Motor..."));
		Sleep(DelayTime);
		RtlZeroMemory(ch,255); pMCA->MoveMotorGetStatusString(ch); str=ch;	
		_tprintf(str);

//
PI.SetStatus( pMCA->GetPIStatus(true,m_PISamplingCount, m_PISamplingDelay,ratio) );
_tprintf(_T("\nPI(%d)Ratio=%3.1f %%"),PI.Status() , ratio);

	return 0;
}
