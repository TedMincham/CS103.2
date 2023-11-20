#pragma once

#include <iostream>
#include <string>
#include "fileManagementFunctions.h"
#include "json.hpp"

int randomPolicyNumber()
{
	srand((unsigned)time(NULL));

	int num = 1000 + (rand() % 50000);

	return num;
}


bool validEmail(std::string userEmail)
{
	bool valid;

	if (userEmail.find('@') != std::string::npos)
	{
		valid = true;
	}
	else
	{
		valid = false;
	}
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
	validUser = data["user"].contains(userName);

	if (validUser)
	{
		if (data["user"][userName]["password"] == passWord)
		{
			valid = true;
		}
	}
	else
	{
		std::cout << "Invalid Username or Password" << std::endl;
		valid = false;
	}
		
	return valid;
}