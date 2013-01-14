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
	if(stream == 0)
	{
		std::string error = "Error in Stereo::Info: no valid stream";
		throw (error); 
	}
	if(mState == eOn)
	{
		if(mDriveState == eOpened)
		{
			stream << "Stereo is On" << " " << "CD is opened" <<  std::endl;
		}
		else
		{
			stream << "Stereo is On" << " " << "CD is closed" <<  std::endl;
		}
	}
	else 
	{
		if(mDriveState == eOpened)
		{
			stream << "Stereo is Off" << " " << "CD is opened" <<  std::endl;
		}
		else
		{
			stream << "Stereo is Off" << " " << "CD is closed" <<  std::endl;
		}
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