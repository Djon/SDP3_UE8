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

class Client :
	public Object
{
public:
	//CTor
	Client();

	void AddDevice(IDevice* Device, size_t SlotNumber, ICommand* OnCommand, ICommand* OffCommand);
	void PrintDeviceInfo(std::ostream& stream);
	void PrintInterface();
	void Process(std::string& Input);
private:
	TDevices mDevices;
	RemoteControl* mRemote;
};

#endif