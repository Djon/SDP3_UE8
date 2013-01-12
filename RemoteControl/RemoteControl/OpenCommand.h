///////////////////////////////////////////////////////////////////////////
// Workfile : OpenCommand.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of OpenCommand.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef OPENCOMMAND_H
#define OPENCOMMAND_H

#include "Object.h"
#include "ICommand.h"
#include "Stereo.h"

class OpenCommand :
	public Object,
	public ICommand
{
public:
	OpenCommand(Stereo* stereo);
	void Execute();
	void Undo();

private:
	Stereo* mStereo;
};

#endif