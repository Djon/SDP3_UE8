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
	try
	{
		if(stereo == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		mStereo = stereo;
	}
	catch (std::string const& error)
	{
		std::cout << "Error in CloseCommand::CloseCommand: " << error << std::endl;
	}
}
	
void OpenCommand::Execute()
{
	mStereo->OpenCD();
}

void OpenCommand::Undo()
{
	mStereo->UndoCD();
}