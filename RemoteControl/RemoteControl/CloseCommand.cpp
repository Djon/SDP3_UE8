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
	if(stereo == 0)
	{
		std::string error = "Error in CloseCommand::CloseCommand: no valid pointer";
		throw (error); 
	}
	mStereo = stereo;
}
	
void CloseCommand::Execute()
{
	mStereo->CloseCD();
}

void CloseCommand::Undo()
{
	mStereo->UndoCD();
}