#pragma once
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
//================================================================================================
// This is a common helper class for handling string message
// a message handling class to show message string
//================================================================================================
class CUserMessages
{
//=============================
public:
	typedef struct MsgType
{
	DWORD MsgID;
	LPCTSTR pMsg;
}MsgType,*pErrorMsgType;
//=============================
private:

LPCTSTR m_pAppTitle;
DWORD m_MsgCount;
MsgType* m_pErrorMsgLsit;
//=============================
public:
	CUserMessages(void);
	~CUserMessages(void);
	CUserMessages(LPCTSTR pAppTitle, MsgType* pErrorMsgLsit,DWORD MsgCount);
	void SimpleMsg(LPCTSTR pStr);
	void SimpleMsgByID(DWORD MsgID);
	void SetAppTitle(LPCTSTR pAppTitle);
	void SetMsgList(MsgType* pErrorMsgLsit,DWORD MsgCount);
};
