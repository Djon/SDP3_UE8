#include <iostream>

#include "ICommand.h"
#include "NoCommand.h"
#include "MacroCommand.h"
#include "OnCommand.h"
#include "OffCommand.h"
#include "OpenCommand.h"
#include "CloseCommand.h"

#include "IDevice.h"
#include "BaseDevice.h"
#include "Heating.h"
#include "TV.h"
#include "Stereo.h"

#include <vld.h>

using namespace std;

int main()
{
	//statische Variante
	Stereo stereo;
	
	OnCommand	 onCommandStereo(&stereo);
	OpenCommand  openCommandStereo(&stereo);
	OffCommand	 offCommandStereo(&stereo);
	CloseCommand closeCommandStereo(&stereo);

	MacroCommand macroCommandStereoOnOpen;
	macroCommandStereoOnOpen.Add(&onCommandStereo);
	macroCommandStereoOnOpen.Add(&openCommandStereo);

	MacroCommand macroCommandStereoOffClose;
	macroCommandStereoOffClose.Add(&offCommandStereo);
	macroCommandStereoOffClose.Add(&closeCommandStereo);

	stereo.Info(cout);
	macroCommandStereoOnOpen.Execute();
	stereo.Info(cout);
	macroCommandStereoOnOpen.Undo();
	stereo.Info(cout);
	macroCommandStereoOnOpen.Execute();
	stereo.Info(cout);
	macroCommandStereoOffClose.Execute();
	stereo.Info(cout);
	macroCommandStereoOffClose.Undo();
	stereo.Info(cout);

	/*
	andere Variante: dynamisch

	Stereo*     stereo2 = new Stereo;	//kein BaseDevice*
	BaseDevice* stereo1 = stereo2;		//braucht man später (vl.)


	ICommand* onCommandStereo	 = new OnCommand(stereo1);
	ICommand* offCommandStereo	 = new OffCommand(stereo1);
	ICommand* openCommandStereo	 = new OpenCommand(stereo2);
	ICommand* closeCommandStereo = new CloseCommand(stereo2);
	
	MacroCommand* macroCommandOnOpen  = new MacroCommand;	//kein ICommand*
	ICommand*	  iMacroCommandOnOpen =	macroCommandOnOpen;	//braucht man später (vl.)
	macroCommandOnOpen->Add(onCommandStereo);
	macroCommandOnOpen->Add(openCommandStereo);

	macroCommandOnOpen->Execute();
	macroCommandOnOpen->Undo();



	delete heating;
	delete tv;
	delete stereo1;
	delete stereo2;

	delete onCommandStereo;
	delete offCommandStereo;
	delete openCommandStereo;
	delete closeCommandStereo;
	
	delete macroCommandOnOpen;
	*/

	return 0;
}