///////////////////////////////////////////////////////////////////////////
// Workfile : OnCommand.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of OnCommand.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef ONCOMMAND_H
#define ONCOMMAND_H

#include "Object.h"
#include "ICommand.h"
#include "BaseDevice.h"

class OnCommand :
	public Object,
	public ICommand
{
public:
	OnCommand(BaseDevice* device);
	void Execute();
	void Undo();

private:
	BaseDevice* mDevice;
};

#endif