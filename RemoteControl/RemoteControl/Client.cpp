///////////////////////////////////////////////////////////////////////////
// Workfile : Client.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implemantation of class Client
///////////////////////////////////////////////////////////////////////////

#include "Client.h"

Client::Client()
{
	//Remote anlegen
}

void Client::AddDevice(IDevice* Device, size_t SlotNumber, ICommand* OnCommand, ICommand* OffCommand)
{
	if (Device == 0)
	{
		throw("Client::AddDevice: Device is a null pointer");
	}
}

void Client::PrintDeviceInfo(std::ostream& stream)
{

}

void Client::PrintInterface()
{

}

void Client::Process(std::string& Input)
{

}