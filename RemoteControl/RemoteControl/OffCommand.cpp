///////////////////////////////////////////////////////////////////////////
// Workfile : OffCommand.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementation of class OffCommand
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "OffCommand.h"

OffCommand::OffCommand(BaseDevice* device)
{
	if(device == 0)
	{
		std::string error = "Error in OffCommand::OffCommand: no valid pointer";
		throw (error); 
	}
	mDevice = device;
}
	
void OffCommand::Execute()
{
	mDevice->TurnOff();
}

void OffCommand::Undo()
{
	mDevice->UndoAction();
}