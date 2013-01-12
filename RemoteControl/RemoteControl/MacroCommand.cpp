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
	try
	{
		if(command == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		mCommands.push_back(command);
	}
	catch (std::string const& error)
	{
		std::cout << "Error in MacroCommand::Add: " << error << std::endl;
	}
}

void MacroCommand::Remove(ICommand* command)
{
	try
	{
		if(command == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		mCommands.remove(command);
	}
	catch (std::string const& error)
	{
		std::cout << "Error in MacroCommand::Remove: " << error << std::endl;
	}
}