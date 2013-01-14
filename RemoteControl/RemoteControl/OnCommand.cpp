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
	if(device == 0)
	{
		std::string error = "Error in OnCommand::OnCommand: no valid pointer";
		throw (error); 
	}
	mDevice = device;
}
	
void OnCommand::Execute()
{
	mDevice->TurnOn();
}

void OnCommand::Undo()
{
	mDevice->UndoAction();
}