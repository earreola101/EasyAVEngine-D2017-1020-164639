#include "stdafx.h"
#include "C2KeyTest.h"

CC2KeyTest *g_pCC2KeyTest=NULL;
//_______________________________________________________________________________
void CALLBACK LOGCB(LPCTSTR msg)
{
	LOG2(_T("\n%s"), msg);
};
//_______________________________________________________________________________
void CALLBACK KeyEventCallBackProcess(DWORD key1)
{
	
	BYTE *pb = (BYTE*)&key1;
	CString str; str.Format(_T("\n[M]:Key Prss! Byte[2:0]=0x%x,0x%x,0x%x, keycode=Byte[1]=0x%x,"), pb[2], pb[1], pb[0], pb[1]);
	LOG2(str);
	//dlg->KeyResultShow();
	//dlg->OnKeyEvent(pb[1]);
	if(pb[1]!=0) g_pCC2KeyTest->EventKeyRet=pb[1];
};
//___________________________________________________________________________________________________
CC2KeyTest::CC2KeyTest()
{
	EventKeyRet=0;
	g_pCC2KeyTest=this;

	hr = CoInitialize(NULL);	
	hr = pIDevice.CoCreateInstance(CLSID_UltimateControl);
}
//___________________________________________________________________________________________________
CC2KeyTest::~CC2KeyTest()
{
}
//___________________________________________________________________________________________________
void CC2KeyTest::OnKeyEvent(BYTE KeyID)
{
	return;
}
//___________________________________________________________________________________________________
CString CC2KeyTest::OnGetAllKeyStatus()
{
	// Get touch press value
	CComPtr<UltimateControl::IButton> pIUC;
	pIDevice->QueryInterface(&pIUC);
	DWORD val;
	pIUC->GetAllKeysStatus(val);
	 //show key bit status
		CString BitShow;
		for (int j = 0; j<32; j++) { int b = (val >> j & 1);	 BitShow.AppendFormat(_T("%d"), b); }
		LOG2(_T("\n[M]:AllKeysStatus Bits=[%s] val=%d "), BitShow, val);
	 
	return CString(BitShow);
}
//___________________________________________________________________________________________________
BOOL CC2KeyTest::Init()
{
	if (!pIDevice->OpenHIDDevice(0, 0x046d, 0x0857))
	{
		LOG2(_T("\n[E]: Device (PID=0x0857) not found! please close App and connect device first."));
		return FALSE;
	}
	LOG2(_T("\n[M]:Device connected!"));
	//
	return TRUE;
}
//___________________________________________________________________________________________________
int CC2KeyTest::RegisterKeyEventCallbackFunction()
{
	
		CComPtr<UltimateControl::IButton> pIUC;
		hr = pIDevice->QueryInterface(&pIUC);
		pIUC->SetKeyCallback(KeyEventCallBackProcess);
	
	return 0;
}
