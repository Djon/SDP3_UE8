///////////////////////////////////////////////////////////////////////////
// Workfile : OffCommand.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of OffCommand.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef OFFCOMMAND_H
#define OFFCOMMAND_H

#include "Object.h"
#include "ICommand.h"
#include "BaseDevice.h"

class OffCommand :
	public Object,
	public ICommand
{
public:
	OffCommand(BaseDevice* device);
	void Execute();
	void Undo();

private:
	BaseDevice* mDevice;
};

#endif