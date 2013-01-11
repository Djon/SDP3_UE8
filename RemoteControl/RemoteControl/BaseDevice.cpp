///////////////////////////////////////////////////////////////////////////
// Workfile : BaseDevice.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementation of class BaseDevice
///////////////////////////////////////////////////////////////////////////

#include "BaseDevice.h"

void BaseDevice::TurnOff()
{
	mLastState = mState;
	mState = eOff;
}

void BaseDevice::TurnOn()
{
	mLastState = mState;
	mState = eOn;
}

void BaseDevice::UndoAction()
{
	mState = mLastState;
}