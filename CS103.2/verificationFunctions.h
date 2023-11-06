#pragma once

#include <iostream>
#include <string>


bool validEmail()
{
	bool valid;
	valid = false;
	return valid;
}

bool validNumber(int one, int two, int userInput)
{
	bool valid;

	if (isdigit(userInput))
	{
		if (userInput <= two && userInput > one)
		{
			valid = true;
		}
		else
		{
			valid = false;
			std::cout << "This is not a valid input" << std::endl;
		}
	}
	else
	{
		userInput = 100;
		valid = false;
	}



	return valid;
}