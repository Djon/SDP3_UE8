///////////////////////////////////////////////////////////////////////////
// Workfile : RemoteControl.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implemantation of class RemoteControl
///////////////////////////////////////////////////////////////////////////

#include <string>
#include "RemoteControl.h"
#include "NoCommand.h"

RemoteControl::RemoteControl()
	: mLastCommand(0)
{
	try
	{
		for(int i=0; i<MaxSlots; ++i)
		{
			Slot* DefaultSlot = new Slot;
			ICommand* DefaultOnCommand = new NoCommand;
			ICommand* DefaultOffCommand = new NoCommand;

			DefaultSlot->SetCommands(DefaultOnCommand,DefaultOffCommand);
			mSlots.push_back(DefaultSlot);
		}
	}
	catch(std::bad_alloc& ex)
	{
		throw(ex);
	}
}

void RemoteControl::OnButtonPressed(size_t SlotNumber)
{
	try
	{
		if (SlotNumber == 0 || SlotNumber > MaxSlots) 
		{
			throw std::string("RemoteControl::OnButtonPressed: SlotNumber out of range");
		}

		mSlots[SlotNumber-1]->ClickedOn();
		mLastCommand = mSlots[SlotNumber-1]->GetOnCommand();
	}
	catch(std::string const& ex)
	{
		throw(ex);
	}
}

void RemoteControl::OffButtonPressed(size_t SlotNumber)
{
	try
	{
		if (SlotNumber == 0 || SlotNumber > MaxSlots) 
		{
			throw std::string("RemoteControl::OffButtonPressed: SlotNumber out of range");
		}

		mSlots[SlotNumber-1]->ClickedOff();
		mLastCommand = mSlots[SlotNumber-1]->GetOffCommand();
	}
	catch(std::string const& ex)
	{
		throw(ex);
	}
}

void RemoteControl::ProgramSlot(size_t SlotNumber, ICommand* OnCommand, ICommand* OffCommand)
{
	try 
	{
		(SlotNumber == 0 || SlotNumber > MaxSlots) ? throw std::string("RemoteControl::ProgramSlot: SlotNumber out of range") 
			: OnCommand == 0 ? throw std::string("RemoteControl::ProgramSlot: OnCommand is a null pointer")
			: OffCommand == 0 ? throw std::string("RemoteControl::ProgramSlot: OffCommand is a null pointer")
			: mSlots[SlotNumber-1]->SetCommands(OnCommand,OffCommand);
	}
	catch(std::string const& ex)
	{
		throw(ex);
	}
}

void RemoteControl::UndoButtonPressed()
{
	if (mLastCommand == 0) 
	{
		throw std::string("RemoteControl::UndoButtonPressed: No command to undo");
	}

	mLastCommand->Undo(); 
	mLastCommand = 0;
}

RemoteControl::~RemoteControl()
{
	for(int i=0; i<MaxSlots; ++i)
	{
		delete mSlots[i];
	}
}