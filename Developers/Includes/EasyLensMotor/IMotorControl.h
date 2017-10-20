// filename: IMotorControl.h
#pragma once
// IMotorControl
// This is one of EasyLensMotor COM component's interface
#include "EasyLensMotor.h" 
#ifdef PUREV
#undef  PUREV
#endif
#define PUREV =0
namespace EasyLensMotor{
	///=======================================================================
	/// Interface IMotorControl's definition and IID
	///=======================================================================
	// {E5F6129D-E9B0-4a43-8199-564649EAEC0F} 
EASYLENSMOTOR_DEFINE_GUID(IID_IMotorControl,0xe5f6129d, 0xe9b0, 0x4a43, 0x81, 0x99, 0x56, 0x46, 0x49, 0xea, 0xec, 0xf);
	//___________________________________________________________________________
	MIDL_INTERFACE("E5F6129D-E9B0-4A43-8199-564649EAEC0F")
	IMotorControl : public IUnknown
	{
	    //PI
		STDMETHOD_(bool, ConnectToDevice)(LPCTSTR DeviceName)PUREV; // conect to device via device name
		STDMETHOD_(int,  PIStatus)(bool bSetPreviousPItoCurrent=false)PUREV; // get PI status, 0:(-) side, 1:(+) side
		STDMETHOD_(bool, IsPIStatusChanged)(void)PUREV; // check if the PI status change, before call this, call PIStatus() first
		//Motor type
		
		STDMETHOD_(bool, MotorTypeSet)(BYTE val)PUREV; // assign motor via BYTE value, it could be 0x01 (focus) or 0x02(zoom)
		STDMETHOD_(int,  MotorType)(void)PUREV; // get motor type value		
		//
		STDMETHOD_(int,  MoveMotor)(void)PUREV; // call this method to move motor
		
		//SingleStep
		STDMETHOD_(int, MovingSteps)(void)PUREV; // get single step value
		STDMETHOD_(void,MovingStepsSet)(int val)PUREV; // set single step value
		
		//Direction
		STDMETHOD_(int, Direction)(void)PUREV; // get motor moving direction 0x01: -->, 0x02:<---
		STDMETHOD_(void,DirectionSet)(int dirVal)PUREV; // assign motor moving direction
		

	
	};
};//namespace EasyLensMotor
