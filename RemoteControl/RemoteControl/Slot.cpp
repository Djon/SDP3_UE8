///////////////////////////////////////////////////////////////////////////
// Workfile : Slot.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implemantation of class Slot
///////////////////////////////////////////////////////////////////////////

#include <string>
#include "Slot.h"

Slot::Slot()
	: mOnCommand(0), mOffCommand(0)
{}

void Slot::ClickedOff()
{
	mOffCommand == 0 ? throw std::string("Slot::ClickedOff: mOffCommand is a null pointer") : mOffCommand->Execute();
}

void Slot::ClickedOn()
{
	mOnCommand == 0 ? throw std::string("Slot::ClickedOn: mOnCommand is a null pointer") : mOnCommand->Execute();
}

void Slot::SetCommands(ICommand* OnCommand, ICommand* OffCommand)
{
	mOnCommand = OnCommand;
	mOffCommand = OffCommand;
}

ICommand* Slot::GetOnCommand() const
{
	return mOnCommand;
}

ICommand* Slot::GetOffCommand() const
{
	return mOffCommand;
}

Slot::~Slot()
{
	delete mOnCommand;
	delete mOffCommand;
}