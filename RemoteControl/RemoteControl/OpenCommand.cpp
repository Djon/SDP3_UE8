///////////////////////////////////////////////////////////////////////////
// Workfile : OpenCommand.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementation of class OpenCommand
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "OpenCommand.h"

OpenCommand::OpenCommand(Stereo* stereo)
{
	if(stereo == 0)
	{
		std::string error = "Error in OpenCommand::OpenCommand: no valid pointer";
		throw (error); 
	}
	mStereo = stereo;
}
	
void OpenCommand::Execute()
{
	mStereo->OpenCD();
}

void OpenCommand::Undo()
{
	mStereo->UndoCD();
}