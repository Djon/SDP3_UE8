///////////////////////////////////////////////////////////////////////////
// Workfile : Heating.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of Heating.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef HEATING_H
#define HEATING_H

#include "BaseDevice.h"

class Heating :
	public BaseDevice
{
public:
	void Info(std::ostream& stream);
	std::string GetName() const;
};

#endif