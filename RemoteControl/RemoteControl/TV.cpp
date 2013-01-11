///////////////////////////////////////////////////////////////////////////
// Workfile : TV.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 11.01.2012
// Description : Implementaion of class TV
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "TV.h"

void TV::Info(std::ostream& stream)
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
			stream << "TV is On" << std::endl;
		}
		else 
		{
			stream << "TV is Off" << std::endl;
		}
	}
	catch (std::string const& error)
	{
		std::cout << "Error in TV::Info: " << error << std::endl;
	}
}