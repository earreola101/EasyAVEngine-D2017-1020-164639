#pragma once
//___________________________________________________________________________________________
class CPIStatus
{
private:
	int m_Status;
	int m_StatusK;
	

public:
	bool m_StatusNeverChanged;
public:
	CPIStatus(void);
	~CPIStatus(void);
	bool IsPIStatusChanged(void);
	int Status(void);
	void SetStatus(int val);
	CString GetPIString(void);
	int GetPIDomain(void);


};

