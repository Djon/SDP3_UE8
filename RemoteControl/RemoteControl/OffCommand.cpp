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
	try
	{
		if(device == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		mDevice = device;
	}
	catch (std::string const& error)
	{
		std::cout << "Error in OffCommand::OffCommand: " << error << std::endl;
	}
}
	
void OffCommand::Execute()
{
	mDevice->TurnOff();
}

void OffCommand::Undo()
{
	mDevice->UndoAction();
}