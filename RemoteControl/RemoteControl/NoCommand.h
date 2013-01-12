///////////////////////////////////////////////////////////////////////////
// Workfile : NoCommand.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of NoCommand.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef NOCOMMAND_H
#define NOCOMMAND_H

#include "Object.h"
#include "ICommand.h"

class NoCommand :
	public Object,
	public ICommand
{
public:
	void Execute();
	void Undo();
};

#endif