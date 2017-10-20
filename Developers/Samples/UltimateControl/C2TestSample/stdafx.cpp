// filename: 
#include "stdafx.h"

//======================================================================================================
bool InitializeMFC(void)
{
	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		_tprintf(_T("\nFatal Error: MFC initialization failed\n"));
		return false;
	}
		return true;
}
