///////////////////////////////////////////////////////////////////////////
// Workfile : OnCommand.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementation of class OnCommand
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "OnCommand.h"

OnCommand::OnCommand(BaseDevice* device)
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
		std::cout << "Error in OnCommand::OnCommand: " << error << std::endl;
	}
}
	
void OnCommand::Execute()
{
	mDevice->TurnOn();
}

void OnCommand::Undo()
{
	mDevice->UndoAction();
}