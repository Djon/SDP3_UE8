///////////////////////////////////////////////////////////////////////////
// Workfile : MacroCommand.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementation of class MacroCommand
///////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <algorithm>
#include "MacroCommand.h"

void MacroCommand::Execute()
{
	std::for_each(mCommands.begin(), mCommands.end(), [&](ICommand* command)
	{
		command->Execute();
	});
}

void MacroCommand::Undo()
{
	std::for_each(mCommands.begin(), mCommands.end(), [&](ICommand* command)
	{
		command->Undo();
	});
}

void MacroCommand::Add(ICommand* command)
{
	if(command == 0)
	{
		std::string error = "Error in MacroCommand::Add: no valid pointer";
		throw (error); 
	}
	if(mCommands.size() >= 2)
	{
		std::string error = "Error in MacroCommand::Add: only two entries are allowed";
		throw (error); 
	}
	mCommands.push_back(command);
}

void MacroCommand::Remove(ICommand* command)
{
	if(command == 0)
	{
		std::string error = "Error in MacroCommand::Remove: no valid pointer";
		throw (error); 
	}
	mCommands.remove(command);
}