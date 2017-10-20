// EasyVideoBayer3Dlg.h : header file
#pragma once
#include "resource.h"
//#include "EasyAVEngine.h"
#include "EasyVideo.h"

class CEasyVideoBayer3Dlg : public CDialog
{
public:
	CEasyVideoBayer3Dlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_DLGCLIENT_DIALOG };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPreviewBayer3();
	afx_msg void OnDestroy();
	afx_msg void OnPreviewStop();
	int TakeQuickBayerSnapShot2016(CString BayerConfiguration);
	//
	int LOG_(CString LogMsg);
	CListBox m_LogList;
	HRESULT hr;
	CString str;
	CComPtr<EasyVideo::IEVCamera3> pCamera;
	int count;
	
};
