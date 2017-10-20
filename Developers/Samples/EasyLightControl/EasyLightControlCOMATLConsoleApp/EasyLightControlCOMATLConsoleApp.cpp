// Defines the entry point for the console application.
//
#include "stdafx.h"

#include "EasyLightControlCOM.h"
//#include "EasyAVEngine.h"

#ifndef LOG 
#define LOG _tprintf
#endif
int LightControl(void)
{

	HRESULT hr; CString str;
	CComPtr<EasyLightControlCOM::ILightControl> pLightControl;
	hr = pLightControl.CoCreateInstance(CLSID_EasyLightControlCOM);
	hr=pLightControl->LSSetCOMPort(_T("COM6"));
	if (FAILED(hr))
	{
		LOG(_T("\n[E]:fail to connect to instrument!"));
		return 0;
	}


	pLightControl->LSReset();
	hr = pLightControl->LSSetValue(0/*channel*/, 0/*mode*/, 110/*current (mA)*/, 0 /*Pulse*/);
	if (FAILED(hr))	{ LOG(_T("\n[E]:fail to Set channel 1 !")); }
	hr = pLightControl->LSSetValue(1/*channel*/, 0/*mode*/, 120/*current (mA)*/, 0/*Pulse*/);
	if (FAILED(hr)) { LOG(_T("\n[E]:fail to Set channel 2 !")); }

	{
		LOG(_T("\nLSGetValue...channel=0"));
		int channel = 0;	unsigned char m_nMode = 0; unsigned short m_nMA = 0; unsigned char m_nPulse = 0;
		pLightControl->LSGetValue(channel, m_nMode, m_nMA, m_nPulse);
		LOG(_T("\nChannel=%d, m_nMode=%d, m_nMA=%d, m_nPulse=%d,"), channel, m_nMode, m_nMA, m_nPulse);
	}
	//
	{
		LOG(_T("\nLSGetValue...channel=1"));
		int channel = 1;	unsigned char m_nMode = 0; unsigned short m_nMA = 0; unsigned char m_nPulse = 0;
		pLightControl->LSGetValue(channel, m_nMode, m_nMA, m_nPulse);
		LOG(_T("\nChannel=%d, m_nMode=%d, m_nMA=%d, m_nPulse=%d,"), channel, m_nMode, m_nMA, m_nPulse);
	}
	unsigned int  temp = 0;
	pLightControl->LSGetTemperture(temp);
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr; CString str;
	CoInitialize(NULL);
	//LoggingInterfaceAddressWrite();
	LOG(_T("[C]:EmptyLogFile"));;
	LightControl();
	LOG(_T("\n\nPress enter key to exit,... ")); ::getchar();
	::CoUninitialize();
	return 0;
}
