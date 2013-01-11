///////////////////////////////////////////////////////////////////////////
// Workfile : Stereo.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementaion of class Stereo
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Stereo.h"

void Stereo::Info(std::ostream& stream)
{
	try
	{
		if(stream == 0)
		{
			std::string error = "no valid stream";
			throw (error); 
		}
		if(mState == eOn)
		{
			stream << "Stereo is On" << std::endl;
		}
		else 
		{
			stream << "Stereo is Off" << std::endl;
		}
	}
	catch (std::string const& error)
	{
		std::cout << "Error in Stereo::Info: " << error << std::endl;
	}
}

void Stereo::OpenCD()
{
	mLastDriveState = mDriveState;
	mDriveState = eOpened;
}

void Stereo::CloseCD()
{
	mLastDriveState = mDriveState;
	mDriveState = eClosed;
}

void Stereo::UndoCD()
{
	mDriveState = mLastDriveState;
}