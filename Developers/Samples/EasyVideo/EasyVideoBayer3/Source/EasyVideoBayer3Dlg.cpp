// EasyVideoBayer3Dlg.cpp : implementation file
//
#include "stdafx.h"
#include "EasyVideoBayer3WinApp.h"
#include "EasyVideoBayer3Dlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define LOG(xxx) { CString s; USES_CONVERSION;	s.Format(_T("%s(%d): %s(): "), A2T(THIS_FILE), __LINE__, A2T(__FUNCTION__)); g_pDlg->LOG_(s+xxx);}
CEasyVideoBayer3Dlg *g_pDlg=NULL;
//___________________________________________________________________________________________________
CEasyVideoBayer3Dlg::CEasyVideoBayer3Dlg(CWnd* pParent /*=NULL*/) : CDialog(CEasyVideoBayer3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	CoInitialize(NULL);
	pCamera = NULL;
	count = 0;
	::CreateDirectory(_T("c:\\temp\\"), 0);
	g_pDlg = this;
}
//___________________________________________________________________________________________________
void CEasyVideoBayer3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_LogList);
}
//___________________________________________________________________________________________________
BEGIN_MESSAGE_MAP(CEasyVideoBayer3Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CEasyVideoBayer3Dlg::OnPreviewBayer3)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CEasyVideoBayer3Dlg::OnPreviewStop)
END_MESSAGE_MAP()
//___________________________________________________________________________________________________
BOOL CEasyVideoBayer3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);	SetIcon(m_hIcon, FALSE);
	if (pCamera == NULL) 	{ hr = pCamera.CoCreateInstance(CLSID_EasyVideo); }
	SetForegroundWindow();
	return TRUE;  // return TRUE  unless you set the focus to a control
}
//___________________________________________________________________________________________________
void CEasyVideoBayer3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
	
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}
//___________________________________________________________________________________________________
void CEasyVideoBayer3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
//___________________________________________________________________________________________________
HCURSOR CEasyVideoBayer3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//___________________________________________________________________________________________________
void CEasyVideoBayer3Dlg::OnDestroy()
{
	CDialog::OnDestroy();
}
//___________________________________________________________________________________________________
STDMETHODIMP  VideoFrameProcMain(const EasyVideo::tagVideoSamplingInfo* pVSP)
{
	LOG(_T("\nInto callback function for Video Processing..."));
	return S_OK;
}
//___________________________________________________________________________________________________
int CEasyVideoBayer3Dlg::TakeQuickBayerSnapShot2016(CString BayerConfiguration)
{
	{//Set Bayer 
		LOG(_T("\nQuery IEVBayer3 interface..."));
		CComPtr<EasyVideo::IEVBayer3> pEVB; pCamera.QueryInterface(&pEVB);
		LOG(_T("\nSetBayerConfiguration..."));
		pEVB->SetBayerConfiguration(BayerConfiguration);
	}
	LOG(_T("\nAssign callback function for real video processing..."));
	hr = pCamera->VideoFrameSetProcessingFunction(VideoFrameProcMain, 0/*process RGB24 Frame before render*/);
	LOG(_T("\nStrat Preview Bayer..."));
	hr = pCamera->PreviewStart();
	if (pCamera->IsPreviewing())
	{
		CString strr;	strr.Format(_T("c:\\temp\\Bayer(%d).bmp"), count);
		LOG(_T("\nSave video frame to file:"));	LOG(strr);
		hr = pCamera->VideoFrameSave(EasyVideo::FrameBeforeRender, strr);
		count++;
	}
	LOG(_T("Preview...ok!"));
	return 0;
}
//___________________________________________________________________________________________________
void CEasyVideoBayer3Dlg::OnPreviewBayer3()
{	

	TakeQuickBayerSnapShot2016(_T("VID(114d).PID(8589).SensorID(1)"));// for IR sensor AIT FW
	//TakeQuickBayerSnapShot2016(_T("VID(114d).PID(8589).SensorID(0)"));// for 4K sensor AIT FW
	//TakeQuickBayerSnapShot2016(_T("VID(46d).PID(85E).SensorID(1)"));// for IR sensor Logi FW
	//TakeQuickBayerSnapShot2016(_T("VID(46d).PID(85E).SensorID(0)"));// for 4K sensor Logi FW
}
//___________________________________________________________________________________________________
void CEasyVideoBayer3Dlg::OnPreviewStop()
{
	LOG(_T("PreviewStop..."));
	hr = pCamera->PreviewStop(); Sleep(500);
	LOG(_T("...ok!"));
}
//___________________________________________________________________________________________________
int CEasyVideoBayer3Dlg::LOG_(CString LogMsg)
{
	m_LogList.AddString(LogMsg);
	m_LogList.SetCurSel(m_LogList.GetCount() - 1);
	return 0;
}
