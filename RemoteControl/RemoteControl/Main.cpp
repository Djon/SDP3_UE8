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

using namespace std;


void EmptyTestcase()
{
	try
	{
		cout << "Testcase0: Empty testcase with NULL pointer." << endl;

		Client c;

		cout << "Print Interface:" << endl;
		c.PrintInterface();

		cout << "Add Device:" << endl;
		c.AddDevice(0,0,0,0);
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

void EmptyProcessInfo()
{
	try
	{
		Client c;

		cout << "Print Device Info:" << endl;
		c.PrintDeviceInfo(cout);
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

void EmptyProcess()
{
	try
	{
		Client c;
		string s(" ");

		cout << "Process";
		c.Process(s);
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

void NormalTestcase()
{
	try
	{
		cout << "Testcase1: Normal testcase." << endl;

		Client c;
		string Input("i");

		cout << "Creating Devices:" << endl;
		Stereo stereo;
		Heating heater;
		TV tv;

		cout << "Creating Commands:" << endl;
		ICommand* onCommandStereo = new OnCommand(&stereo);
		ICommand* openCommandStereo = new OpenCommand(&stereo);
		ICommand* offCommandStereo = new OffCommand(&stereo);
		ICommand* closeCommandStereo = new CloseCommand(&stereo);

		MacroCommand* macroCommandStereoOnOpen = new MacroCommand;
		macroCommandStereoOnOpen->Add(onCommandStereo);
		macroCommandStereoOnOpen->Add(openCommandStereo);

		MacroCommand* macroCommandStereoOffClose = new MacroCommand;
		macroCommandStereoOffClose->Add(offCommandStereo);
		macroCommandStereoOffClose->Add(closeCommandStereo);

		ICommand* onCommandHeater = new OnCommand(&heater);
		ICommand* ofCommandHeater = new OffCommand(&heater);

		ICommand* onCommandTV = new OnCommand(&tv);
		ICommand* ofCommandTV = new OffCommand(&tv);

		cout << "Adding devices to client:" << endl;
		c.AddDevice(&stereo,4,macroCommandStereoOnOpen,macroCommandStereoOffClose);
		c.AddDevice(&heater,2,onCommandHeater,ofCommandHeater);
		c.AddDevice(&tv,1,onCommandTV,ofCommandTV);

		cout << "Print Interface:" << endl;
		c.PrintInterface();

		cout << "Process:" << endl;
		cout << Input << endl;
		c.Process(Input);

		Input = "1o";
		cout << Input << endl;
		c.Process(Input);

		Input = "2o";
		cout << Input << endl;
		c.Process(Input);

		Input = "6o";
		cout << Input << endl;
		c.Process(Input);

		Input = "4o";
		cout << Input << endl;
		c.Process(Input);	

		Input = "i";
		cout << Input << endl;
		c.Process(Input);

		Input = "u";
		cout << Input << endl;
		c.Process(Input);

		Input = "i";
		cout << Input << endl;
		c.Process(Input);

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
	EmptyProcessInfo();
	EmptyProcess();
	cout << endl << endl;

	NormalTestcase();

	return 0;
}