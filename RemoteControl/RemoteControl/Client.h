///////////////////////////////////////////////////////////////////////////
// Workfile : Client.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of Client.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef CLIENT_H
#define CLIENT_H

#include <list>
#include <iostream>
#include <string>
#include "Object.h"
#include "RemoteControl.h"
#include "IDevice.h"

typedef std::list<IDevice*> TDevices;

std::string const DivLine("-----------------------");

class Client :
	public Object
{
public:
	void AddDevice(IDevice* Device, size_t SlotNumber, ICommand* OnCommand, ICommand* OffCommand);
	void PrintDeviceInfo(std::ostream& stream);
	void PrintInterface();
	void Process(std::string& Input, std::ostream& stream = std::cout);
private:
	TDevices mDevices;
	RemoteControl mRemote;
};

#endif