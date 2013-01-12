///////////////////////////////////////////////////////////////////////////
// Workfile : ICommand.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Interface for Commands
///////////////////////////////////////////////////////////////////////////

#ifndef COMMAND_H
#define COMMAND_H

class ICommand
{
public:
	virtual ~ICommand(){};
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

#endif