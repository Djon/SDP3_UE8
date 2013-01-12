///////////////////////////////////////////////////////////////////////////
// Workfile : CloseCommand.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Header of CloseCommand.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef CLOSECOMMAND_H
#define CLOSECOMMAND_H

#include "Object.h"
#include "ICommand.h"
#include "Stereo.h"

class CloseCommand :
	public Object,
	public ICommand
{
public:
	CloseCommand(Stereo* stereo);
	void Execute();
	void Undo();

private:
	Stereo* mStereo;
};

#endif