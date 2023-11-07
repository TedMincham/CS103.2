#pragma once

#include <iostream>
#include <string>
#include "fileManagementFunctions.h"
#include "json.hpp"


bool validEmail()
{
	bool valid;
	valid = false;
	return valid;
}


bool validNumber(char one, char two, char userInput)
{
	bool valid = false;

	int userNum = (int)userInput - '0';
	int numOne = (int)one - '0';
	int numTwo = (int)two - '0';

	
	if (isdigit(userInput))
	{
		if (userNum >= numOne  && userNum  <= numTwo)
		{
			valid = true;
		}		
	}
	return valid;
}

bool validateLogin(std::string userName, std::string passWord)
{
	bool valid = false;

	bool validUser;

	nlohmann::json data = jsonDataFile();
	validUser = data.contains(userName);

	if (validUser)
	{
		if (data[userName]["password"] == passWord)
		{
			std::cout << "Login sucessful" << std::endl;
			valid = true;
		}
	}
	else
	{
		std::cout << "This user does not exist" << std::endl;
		valid = false;
	}
		
	return valid;
}