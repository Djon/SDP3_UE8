///////////////////////////////////////////////////////////////////////////
// Workfile : Stereo.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of Stereo.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef STEREO_H
#define STEREO_H

#include "BaseDevice.h"
#include "CDState.h"

class Stereo :
	public BaseDevice
{
public:
	void Info(std::ostream& stream);
	void OpenCD();
	void CloseCD();
	void UndoCD();
	
private:
	CDState mDriveState;
	CDState mLastDriveState;
};

#endif