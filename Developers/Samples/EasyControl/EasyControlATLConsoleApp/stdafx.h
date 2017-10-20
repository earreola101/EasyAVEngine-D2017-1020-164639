// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once
#ifndef _WIN32_WINNT          // Allow use of features specific to Windows XP or later.
#define _WIN32_WINNT 0x0501     // Change this to the appropriate value to target other versions of Windows.
#endif
#include <stdio.h>
#include <tchar.h>
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit
#include <atlbase.h>
#include <atlstr.h>
// TODO: reference additional headers your program requires here
// 
#define DECLARE_STRING(__StrName,__size) TCHAR __StrName[__size]; RtlZeroMemory( __StrName,__size);
