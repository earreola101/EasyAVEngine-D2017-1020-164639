// EasyVideoBayer3.cpp : Defines the class behaviors for the application.
#include "stdafx.h"
#include "EasyVideoBayer3WinApp.h"
#include "EasyVideoBayer3Dlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
BEGIN_MESSAGE_MAP(CEasyVideoBayer3App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()
//___________________________________________________________________________________________________
CEasyVideoBayer3App::CEasyVideoBayer3App()
{
}
CEasyVideoBayer3App theApp;
//___________________________________________________________________________________________________
BOOL CEasyVideoBayer3App::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	CWinApp::InitInstance();
	AfxEnableControlContainer();
	// Standard initialization
	// If you are not using these features and wish to reduce the size of your final executable, you should remove from the following
	// the specific initialization routines you do not need Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	CEasyVideoBayer3Dlg dlg; m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		
	}
	else if (nResponse == IDCANCEL)
	{
		
	}
	return FALSE; //exit the application
}
