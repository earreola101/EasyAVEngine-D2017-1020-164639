// filename: ITiltMotor.h
#pragma once
// ITiltMotor
// This is one of EasyPTMotor COM component's interface
#include "EasyPTMotor.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
//------------------------------
#define Tilt_Up 1
#define Tilt_Down -1
#define Tilt_Stop 0
namespace EasyPTMotor{

	///=======================================================================
	/// Interface ITiltMotor's definition and IID
	///=======================================================================
	// {359FD28A-7F70-40e5-A93B-9B993CE02BEE} 
	EASYPTMOTOR_DEFINE_GUID(IID_ITiltMotor,0x359fd28a, 0x7f70, 0x40e5, 0xa9, 0x3b, 0x9b, 0x99, 0x3c, 0xe0, 0x2b, 0xee);
	//___________________________________________________________________________
	MIDL_INTERFACE("359FD28A-7F70-40E5-A93B-9B993CE02BEE")
	ITiltMotor : public IUnknown
	{
		STDMETHOD_(BOOL,PIGet)(BYTE & pi) PUREV;
	    STDMETHOD_(BOOL,GetDuration)(WORD & t) PUREV;
	    STDMETHOD_(BOOL,GetCounter)(WORD & c) PUREV;
		STDMETHOD_(BOOL,Stop)(void) PUREV;
		STDMETHOD_(BOOL,Move)(int direction, int delaytime) PUREV;

	};
};//namespace EasyPTMotor
