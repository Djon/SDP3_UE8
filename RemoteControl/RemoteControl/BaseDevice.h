///////////////////////////////////////////////////////////////////////////
// Workfile : BaseDevice.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of BaseDevice.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef BASEDEVICE_H
#define BASEDEVICE_H

#include "Object.h"
#include "IDevice.h"
#include "OnOffState.h"

class BaseDevice :
	public Object,
	public IDevice
{
public:
	BaseDevice() : mState(eOff), mLastState(eOff) {}
	void Info(std::ostream& stream) = 0;
	void TurnOff();
	void TurnOn();
	void UndoAction();

protected:
	OnOffState mState;

private:
	OnOffState mLastState;
};

#endif