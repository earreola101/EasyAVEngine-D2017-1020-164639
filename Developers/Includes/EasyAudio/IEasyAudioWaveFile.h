// filename: IWaveFile.h
#pragma once
// IEasyAudioWaveFile
// This is one of EasyAudioWaveFile COM component's interface
#include "EasyAudioWaveFile.h" 
#include <mmsystem.h>
namespace EasyAudio{
#define WAVEFILE_READ   1
#define WAVEFILE_WRITE  2
#ifndef PUREV
#define PUREV =0
#endif
	///=======================================================================
	/// Interface IEasyAudioWaveFile's definition and IID
	///=======================================================================
	// {8AFF6B97-38D2-4664-B4B3-DE8783DEBDD7} 
EASYAUDIOWAVEFILE_DEFINE_GUID(IID_IEasyAudioWaveFile,0x8aff6b97, 0x38d2, 0x4664, 0xb4, 0xb3, 0xde, 0x87, 0x83, 0xde, 0xbd, 0xd7);
	//___________________________________________________________________________
	MIDL_INTERFACE("8AFF6B97-38D2-4664-B4B3-DE8783DEBDD7")
	IEasyAudioWaveFile : public IUnknown
	{
	   
		STDMETHOD(Open)( LPTSTR strFileName, WAVEFORMATEX* pwfx, DWORD dwFlags )PUREV;
		STDMETHOD(OpenRead)( LPTSTR strFileName)PUREV;
	    STDMETHOD(OpenFromMemory)( BYTE* pbData, ULONG ulDataSize, WAVEFORMATEX* pwfx, DWORD dwFlags )PUREV;
        STDMETHOD(Close)(void)PUREV;
        STDMETHOD(Read)( BYTE* pBuffer, DWORD dwSizeToRead, DWORD* pdwSizeRead )PUREV;
        STDMETHOD(Write)( UINT nSizeToWrite, BYTE* pbData, UINT* pnSizeWrote )PUREV;
		STDMETHOD_(DWORD,GetSize)(void)PUREV;
        STDMETHOD(ResetFile)(void)PUREV;
        STDMETHOD_(WAVEFORMATEX*,GetFormat)(void)PUREV;
		STDMETHOD(SaveWaveFormatInfoToTxt)(LPCTSTR filename)PUREV;
		STDMETHOD_(DWORD,TotalBytesPerChannel)(void)PUREV;
		STDMETHOD_(DWORD,TotalSamplesPerChannel)(void)PUREV;
		STDMETHOD_(DWORD,BitRate)(void)PUREV;
		//=====================================================
		STDMETHOD_(WORD,Channels)(void)PUREV;
		STDMETHOD_(WORD,BitsPerSample)(void)PUREV;
		STDMETHOD_(DWORD,SamplesPerSec)(void)PUREV;
		//=====================================================
		STDMETHOD_(double,TotalDurationTime)(void)PUREV;
		STDMETHOD(ExtractChannelData)(LPTSTR DestWaveFileName,WORD ChannelGet)PUREV;

	};
};//namespace EasyAudio
#undef PUREV

