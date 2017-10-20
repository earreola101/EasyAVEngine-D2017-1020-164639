#include "stdafx.h"
#include "PIStatus.h"

CPIStatus::CPIStatus(void)
{
	m_StatusNeverChanged=true;
}

CPIStatus::~CPIStatus(void)
{
}

//
bool CPIStatus::IsPIStatusChanged(void)
{
	if(m_Status!=m_StatusK) return true;
	return false;
}
//
int CPIStatus::Status(void)
{
	return m_Status;
}
void CPIStatus::SetStatus(int val)
{
	m_StatusK= m_Status;
	m_Status=val;
};
//
CString CPIStatus::GetPIString(void)
{
	if(m_Status==1) return CString(_T("+"));
	if(m_Status==0) return CString(_T("-"));
	return CString(_T("?"));
};

int CPIStatus::GetPIDomain(void)
{
	if(m_Status==0) return -1;
	if(m_Status==1) return 1;
	return 0;
};
