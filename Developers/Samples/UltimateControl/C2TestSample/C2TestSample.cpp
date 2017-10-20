#include "stdafx.h"
#include "C2TestSample.h"
#include "C2KeyTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//
CWinApp theApp; // The one and only application object
using namespace std;


//
//================================================================================
// Defines the entry point for the console application.
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	//
	_tprintf(_T("\n-------------------------------------------------------------"));
	_tprintf(_T("\nC2TestSample Version 0.86, Since 2015"));
	_tprintf(_T("\n-------------------------------------------------------------"));
	//
	if (!InitializeMFC())return 1;//// initialize MFC and print and error on failure
	int nRetCode = 0;
	CC2KeyTest C2key;
	if (C2key.Init())
	{ // Tow mode, (1)key event mode, (2) pooling mode, each mode can get key status
		//  suggest use the key event mode, remote control only work with  key event mode
		C2key.RegisterKeyEventCallbackFunction(); // key event mode, after user press a key, key event call into call back function

		for (int i = 0; i < 10; i++)
		{
			C2key.OnGetAllKeyStatus(); // pooling mode: get key status 
		}
	

	}


	return nRetCode;
}
//======================================================================================================
