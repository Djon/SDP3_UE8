///////////////////////////////////////////////////////////////////////////
// Workfile : RemoteControl.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of RemoteControl.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <vector>
#include "Object.h"
#include "Slot.h"

typedef std::vector<Slot*> TSlots;
size_t const MaxSlots = 6;

class RemoteControl :
	public Object
{
public:
	//CTor
	RemoteControl();

	//DTor
	~RemoteControl();

	void OnButtonPressed(size_t SlotNumber);
	void OffButtonPressed(size_t SlotNumber);
	void ProgramSlot(size_t SlotNumber, ICommand* OnCommand, ICommand* OffCommand);
	void UndoButtonPressed();

private:
	ICommand* mLastCommand;
	TSlots mSlots;
};

#endif