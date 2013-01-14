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

#include "Client.h"

#include <vld.h>

using namespace std;


void EmptyTestcase()
{
	try
	{
	cout << "Testcase0: Empty testcase with NULL pointer." << endl;

	Client c;
	string s(" ");

	cout << "Print Interface:" << endl;
	c.PrintInterface();

	cout << "Add Device:" << endl;
	c.AddDevice(0,0,0,0);

	cout << "Print Device Info:" << endl;
	c.PrintDeviceInfo(cout);

	cout << "Process";
	c.Process(s);

	cout << endl << endl;
	}
	catch(std::bad_alloc& ex)
	{
		cout << ex.what() << endl;
	}
	catch(std::string const& ex)
	{
		cout << ex << endl;
	}
	catch(...)
	{
		cout << "Unhandled exception occured";
	}
}

int main()
{
	EmptyTestcase();

	/*//statische Variante
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
	stereo.Info(cout);*/

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