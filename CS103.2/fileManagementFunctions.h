#pragma once

#include <iostream>
#include <fstream>
#include "json.hpp"


extern struct userData
{
	std::string password, userName, firstName, lastName, DOB, contactNumber, gender, email, address, vehicleRego;
	bool isAdmin;
};

nlohmann::json jsonDataFile()
{
	std::ifstream f("./Customer_registration.json");
	nlohmann::json userDataJson = nlohmann::json::parse(f)["userData"];
	std::cout << userDataJson;
	return userDataJson;
}

void createData()
{
	nlohmann::json data = jsonDataFile();
}

