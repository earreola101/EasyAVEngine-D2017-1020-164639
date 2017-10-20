// EasyVideoBayer3.h : main header file for the PROJECT_NAME application
#pragma once
#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif
#include "resource.h"		// main symbols
class CEasyVideoBayer3App : public CWinApp
{
public:
	CEasyVideoBayer3App();
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};
extern CEasyVideoBayer3App theApp;
