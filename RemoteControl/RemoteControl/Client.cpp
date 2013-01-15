///////////////////////////////////////////////////////////////////////////
// Workfile : Client.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implemantation of class Client
///////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include "Client.h"

void Client::AddDevice(IDevice* Device, size_t SlotNumber, ICommand* OnCommand, ICommand* OffCommand)
{
	try
	{
		if (Device == 0) 
		{
			throw std::string("Client::AddDevice: Device is a null pointer");
		}
		if (SlotNumber == 0 || SlotNumber > MaxSlots) 
		{
			throw std::string("Client::AddDevice: SlotNumber out of range");
		}
		if (OnCommand == 0) 
		{
			throw std::string("Client::AddDevice: OnCommand is a null pointer");
		}
		if (OffCommand == 0) 
		{
			throw std::string("Client::AddDevice: OffCommand is a null pointer");
		}

		mDevices.push_back(Device);
		mRemote.ProgramSlot(SlotNumber,OnCommand,OffCommand);
	}
	catch(std::string const& ex)
	{
		throw(ex);
	}
}

void Client::PrintDeviceInfo(std::ostream& stream)
{
	try
	{
		if (stream == 0) 
		{
			throw std::string("Client::PrintDeviceInfo: stream is null");
		}

		stream << "Devices:" << std::endl;
		stream << DivLine << std::endl;

		std::for_each(mDevices.begin(),mDevices.end(),[&](IDevice* d)
		{
			d->Info(stream);
		});
	}
	catch(std::string const& ex)
	{
		throw(ex);
	}
}

void Client::PrintInterface()
{
	std::cout << "Remote control:" << std::endl;
	std::cout << DivLine << std::endl;
	std::cout << "1...TV" << std::endl;
	std::cout << "2...Heating" << std::endl;
	std::cout << "3...empty" << std::endl;
	std::cout << "4...Stereo" << std::endl;
	std::cout << "5...empty" << std::endl;
	std::cout << "6...empty" << std::endl;
	std::cout << "u...undo" << std::endl;
	std::cout << "i...output device info" << std::endl;
	std::cout << DivLine << std::endl;
	std::cout << "input slot number and on('o') or off('f'):" << std::endl;
}

void Client::Process(std::string& Input, std::ostream& stream)
{
	try
	{
		if (Input.empty())
		{
			throw std::string("Client::Process: Input is null");
		}
		if (Input[0] == 'u')
		{
			mRemote.UndoButtonPressed();
		} 
		else if (Input[0] == 'i')
		{
			PrintDeviceInfo(stream);
		} 
		else if (Input.size() >= 2)
		{
			for (int i=0; i<MaxSlots; ++i)
			{
				if (Input[0] == (char)(i+1))
				{
					if (Input[1] == 'o')
					{
						mRemote.OnButtonPressed(i+1);
					}
					else if (Input[1] == 'f')
					{
						mRemote.OffButtonPressed(i+1);
					}
					else
					{
						throw std::string("Client::Process: Input is not valid");
					}
				}
				else
				{
					throw std::string("Client::Process: Input is not valid");
				}
			}
		} 
		else
		{
			throw std::string("Client::Process: Input is not valid");
		}
	}
	catch(std::string const& ex)
	{
		throw(ex);
	}
}