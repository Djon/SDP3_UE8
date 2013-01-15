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
	if(stream == 0)
	{
		std::string error = "Error in TV::Info: no valid stream";
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

std::string TV::GetName() const
{
	return "TV";
}