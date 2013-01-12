///////////////////////////////////////////////////////////////////////////
// Workfile : MacroCommand.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of MacroCommand.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include <list>
#include "Object.h"
#include "ICommand.h"

typedef std::list<ICommand*> TCommands;

class MacroCommand :
	public Object,
	public ICommand
{
public:
	void Execute();
	void Undo();
	void Add(ICommand* command);
	void Remove(ICommand* command);
private:
	TCommands mCommands;
};

#endif