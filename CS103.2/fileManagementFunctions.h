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
	nlohmann::json userDataJson = nlohmann::json::parse(f);
    f.close();
	return userDataJson;
}

void addNewUser(userData newUser)
{
    nlohmann::json newUserJson = jsonDataFile();

    newUserJson[newUser.userName]["password"] = newUser.password;
    newUserJson[newUser.userName]["userName"] = newUser.userName;
    newUserJson[newUser.userName]["firstName"] = newUser.firstName;
    newUserJson[newUser.userName]["lastName"] = newUser.lastName;
    newUserJson[newUser.userName]["DOB"] = newUser.DOB;
    newUserJson[newUser.userName]["contactNumber"] = newUser.contactNumber;
    newUserJson[newUser.userName]["gender"] = newUser.gender;
    newUserJson[newUser.userName]["email"] = newUser.email;
    newUserJson[newUser.userName]["address"] = newUser.address;
    newUserJson[newUser.userName]["vehicleRego"] = newUser.vehicleRego;
    newUserJson[newUser.userName]["isAdmin"] = newUser.isAdmin;

    std::fstream f("./Customer_registration.json",std::ios::out);
    f << std::setw(4) << newUserJson;
    f.close();
}

