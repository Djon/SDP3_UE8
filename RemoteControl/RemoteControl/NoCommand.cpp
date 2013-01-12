///////////////////////////////////////////////////////////////////////////
// Workfile : NoCommand.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementation of class NoCommand
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "NoCommand.h"

void NoCommand::Execute()
{
	std::cout << "Can not execute: No Command" << std::endl;
}

void NoCommand::Undo()
{
	std::cout << "Can not undo: No Command" << std::endl;
}