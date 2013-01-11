///////////////////////////////////////////////////////////////////////////
// Workfile : IDevice.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Interface vor Devices
///////////////////////////////////////////////////////////////////////////

#ifndef IDEVICE_H
#define IDEVICE_H

#include <fstream>

class IDevice
{
public:
	virtual ~IDevice(){};
	virtual void Info(std::ostream& stream) = 0;
};

#endif