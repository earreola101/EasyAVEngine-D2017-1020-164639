#pragma once
#include "UltimateControl.h"
#define LOG2 _tprintf


class CC2KeyTest
{
public:
	CC2KeyTest();
	~CC2KeyTest();
	void OnKeyEvent(BYTE KeyID);
	CString OnGetAllKeyStatus();
	CComPtr<UltimateControl::IDevice> pIDevice;
	BOOL Init();
	HRESULT hr;
	int RegisterKeyEventCallbackFunction();
	BYTE EventKeyRet;
};

