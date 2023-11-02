#pragma once

#include <iostream>
#include <fstream>
#include "json.hpp"

struct userData
{
	std::string password, userName, firstName, lastName, DOB, contactNumber, gender, email, address, vehicleRego;
	bool isAdmin;
};

nlohmann::json jsonDataFile()
{
	std::ifstream f("./Customer_registration.json");
	nlohmann::json userDataJson = nlohmann::json::parse(f)["userData"];
	return userDataJson;
}

void createData()
{
	nlohmann::json data = jsonDataFile();
}

