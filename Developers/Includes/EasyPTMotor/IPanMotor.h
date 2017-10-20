// filename: IPanMotor.h
#pragma once
// IPanMotor
// This is one of EasyPTMotor COM component's interface
#include "EasyPTMotor.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
//------------------------------
#define Pan_CW 1
#define Pan_CCW -1
#define Pan_Stop 0

namespace EasyPTMotor{
	///=======================================================================
	/// Interface IPanMotor's definition and IID
	///=======================================================================
	// {FEE9D331-0136-404e-81C3-4E311997A809} 
EASYPTMOTOR_DEFINE_GUID(IID_IPanMotor,0xfee9d331, 0x136, 0x404e, 0x81, 0xc3, 0x4e, 0x31, 0x19, 0x97, 0xa8, 0x9);
	//___________________________________________________________________________
	MIDL_INTERFACE("FEE9D331-0136-404E-81C3-4E311997A809")
	IPanMotor : public IUnknown
	{
	    
		STDMETHOD_(BOOL,PIGet)(BYTE & pi) PUREV;
	    STDMETHOD_(BOOL,GetDuration)(WORD & t) PUREV;
	    STDMETHOD_(BOOL,GetCounter)(WORD & c) PUREV;
		STDMETHOD_(BOOL,Stop)(void) PUREV;
		STDMETHOD_(BOOL,Move)(int direction, int delaytime) PUREV;
		

	};
};//namespace EasyPTMotor
