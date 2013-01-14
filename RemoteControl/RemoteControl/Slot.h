///////////////////////////////////////////////////////////////////////////
// Workfile : Slot.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of Slot.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef SLOT_H
#define SLOT_H

#include "Object.h"
#include "ICommand.h"

class Slot :
	public Object
{
public:
	//Default CTor for baseclass
	Slot();

	//DTor
	~Slot();

	void ClickedOff();
	void ClickedOn();
	void SetCommands(ICommand* OnCommand, ICommand* OffCommand);
	
	ICommand* GetOnCommand() const;
	ICommand* GetOffCommand() const;

private:
	ICommand* mOnCommand;
	ICommand* mOffCommand;
};

#endif