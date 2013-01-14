///////////////////////////////////////////////////////////////////////////
// Workfile : RemoteControl.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implemantation of class RemoteControl
///////////////////////////////////////////////////////////////////////////

#include "RemoteControl.h"
#include "NoCommand.h"

RemoteControl::RemoteControl()
	: mLastCommand(0)
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

void RemoteControl::OnButtonPressed(size_t SlotNumber)
{
	if (SlotNumber == 0 || SlotNumber > MaxSlots) 
	{
		throw("RemoteControl::OnButtonPressed: SlotNumber out of range");
	}

	mSlots[SlotNumber-1]->ClickedOn();
	mLastCommand = mSlots[SlotNumber-1]->GetOnCommand();
}

void RemoteControl::OffButtonPressed(size_t SlotNumber)
{
	if (SlotNumber == 0 || SlotNumber > MaxSlots) 
	{
		throw("RemoteControl::OffButtonPressed: SlotNumber out of range");
	}

	mSlots[SlotNumber-1]->ClickedOff();
	mLastCommand = mSlots[SlotNumber-1]->GetOffCommand();
}

void RemoteControl::ProgramSlot(size_t SlotNumber, ICommand* OnCommand, ICommand* OffCommand)
{
	(SlotNumber == 0 || SlotNumber > MaxSlots) ? throw("RemoteControl::ProgramSlot: SlotNumber out of range") 
		: OnCommand == 0 ? throw("RemoteControl::ProgramSlot: OnCommand is a null pointer")
		: OffCommand == 0 ? throw("RemoteControl::ProgramSlot: OffCommand is a null pointer")
		: mSlots[SlotNumber-1]->SetCommands(OnCommand,OffCommand);
}

void RemoteControl::UndoButtonPressed()
{
	if (mLastCommand == 0) 
	{
		throw("RemoteControl::UndoButtonPressed: No command to undo");
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