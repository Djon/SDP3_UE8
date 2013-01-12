///////////////////////////////////////////////////////////////////////////
// Workfile : CloseCommand.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementation of class CloseCommand
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "CloseCommand.h"

CloseCommand::CloseCommand(Stereo* stereo)
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
	
void CloseCommand::Execute()
{
	mStereo->CloseCD();
}

void CloseCommand::Undo()
{
	mStereo->UndoCD();
}