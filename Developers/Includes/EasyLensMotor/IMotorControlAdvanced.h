// filename: IMotorControlAdvanced.h
#pragma once
// IMotorControlAdvanced
// This is one of EasyLensMotor COM component's interface
#include "EasyLensMotor.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyLensMotor{
	///=======================================================================
	/// Interface IMotorControlAdvanced's definition and IID
	///=======================================================================
	// {8227356A-CD27-4dcf-A3EA-E7C8FBD61F33} 
EASYLENSMOTOR_DEFINE_GUID(IID_IMotorControlAdvanced,0x8227356a, 0xcd27, 0x4dcf, 0xa3, 0xea, 0xe7, 0xc8, 0xfb, 0xd6, 0x1f, 0x33);
	//___________________________________________________________________________
	MIDL_INTERFACE("8227356A-CD27-4DCF-A3EA-E7C8FBD61F33")
	IMotorControlAdvanced : public IUnknown
	{
	    
		STDMETHOD_(bool, MotorTypeSetByName)(LPCTSTR ZoomOrFocus)PUREV; // assign motor type via name, it could be "focus" or "zoom"
		STDMETHOD_(void, MotorTypeGetString)(LPTSTR val)PUREV;//Helper Functions: get motor type string name
		STDMETHOD_(void, MoveMotorGetStatusString)(LPTSTR val)PUREV;//Helper Functions
		STDMETHOD_(void, DirectionGetString)(LPTSTR val)PUREV;//Helper Functions: get motor direction readable name.	
		STDMETHOD_(int,  GetPIStatus)(bool bSetPreviousPItoCurrent, int SampleTimes, DWORD PISamplingDelay, double &ratio)PUREV;// get SampleTimes PI status.

	};
};//namespace EasyLensMotor
