///////////////////////////////////////////////////////////////////////////
// Workfile : TV.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of TV.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef TV_H
#define TV_H

#include "BaseDevice.h"

class TV :
	public BaseDevice
{
public:
	void Info(std::ostream& stream);
};

#endif