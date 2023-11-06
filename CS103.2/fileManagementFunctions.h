#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include "json.hpp"

extern struct userData
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

void addNewUser(const userData& newUser)
{
    nlohmann::json data = jsonDataFile();

    nlohmann::json newUserJson;
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

    data.push_back(newUserJson);

    std::ofstream outFile("./Customer_registration.json");
    outFile << std::setw(4) << data;
    outFile.close();
}

std::map<std::string,userData> createData()
{
	nlohmann::json data = jsonDataFile();
    std::map<std::string,userData> usersData;

    for (const auto& userDataJson : data)
    {     
        userData user;
        user.password = userDataJson["password"];
        user.userName = userDataJson["userName"];
        user.firstName = userDataJson["firstName"];
        user.lastName = userDataJson["lastName"];
        user.DOB = userDataJson["DOB"];
        user.contactNumber = userDataJson["contactNumber"];
        user.gender = userDataJson["gender"];
        user.email = userDataJson["email"];
        user.address = userDataJson["address"];
        user.vehicleRego = userDataJson["vehicleRego"];
        user.isAdmin = userDataJson["isAdmin"];
        /*std::cout << "User Data:" << std::endl;
        std::cout << "Password: " << user.password << std::endl;
        std::cout << "User Name: " << user.userName << std::endl;
        std::cout << "First Name: " << user.firstName << std::endl;
        std::cout << "Last Name: " << user.lastName << std::endl;
        std::cout << "DOB: " << user.DOB << std::endl;
        std::cout << "Contact Number: " << user.contactNumber << std::endl;
        std::cout << "Gender: " << user.gender << std::endl;
        std::cout << "Email: " << user.email << std::endl;
        std::cout << "Address: " << user.address << std::endl;
        std::cout << "Vehicle Registration: " << user.vehicleRego << std::endl;
        std::cout << "Is Admin: " << user.isAdmin << std::endl;
        std::cout << std::endl;*/
    }
    return usersData;
}

