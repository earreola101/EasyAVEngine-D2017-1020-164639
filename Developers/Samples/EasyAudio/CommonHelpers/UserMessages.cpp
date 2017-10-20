
#include "UserMessages.h"// a  message handling class to show message string
// This is a common helper class for handling string message
//================================================================================================
CUserMessages::CUserMessages(void)
{
m_pAppTitle=_T("Simple Application");
}

CUserMessages::CUserMessages(LPCTSTR pAppTitle, MsgType* pErrorMsgLsit,DWORD MsgCount)
{
	SetAppTitle(pAppTitle);
	SetMsgList( pErrorMsgLsit, MsgCount);
};
//================================================================================================
CUserMessages::~CUserMessages(void)
{
}
//================================================================================================
void CUserMessages::SetAppTitle(LPCTSTR pAppTitle)
{
m_pAppTitle=pAppTitle;
}
//================================================================================================
void CUserMessages::SimpleMsg(LPCTSTR pStr)
{
	::MessageBox(0,pStr,m_pAppTitle,MB_OK); 
}
//================================================================================================
void CUserMessages::SetMsgList(MsgType* pErrorMsgLsit,DWORD MsgCount)
{
	m_pErrorMsgLsit=pErrorMsgLsit;
	m_MsgCount=MsgCount;
}
// =============================================================================================================
void CUserMessages::SimpleMsgByID(DWORD MsgID)
{
        // Output Result:
		
			for(DWORD i=0;i<m_MsgCount;i++)
			if((MsgID==m_pErrorMsgLsit[i].MsgID)) SimpleMsg(m_pErrorMsgLsit[i].pMsg); 

};