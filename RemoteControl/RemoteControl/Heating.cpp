///////////////////////////////////////////////////////////////////////////
// Workfile : Heating.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementation of class Heating
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Heating.h"

void Heating::Info(std::ostream& stream)
{
	try
	{
		if(stream == 0)
		{
			std::string error = "no valid stream";
			throw (error); 
		}
		if(mState == eOn)
		{
			stream << "Heating is On" << std::endl;
		}
		else 
		{
			stream << "Heating is Off" << std::endl;
		}
	}
	catch (std::string const& error)
	{
		std::cout << "Error in Heating::Info: " << error << std::endl;
	}
}