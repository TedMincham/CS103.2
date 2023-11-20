#pragma once

#include <iostream>
#include <fstream>
#include "json.hpp"

struct userData
{
	std::string password, userName, firstName, lastName, DOB, contactNumber, gender, email, address, vehicleRego;
	bool isAdmin;
};

struct discountData
{
    int newSignUp, renewal, multiPolicy, friendsFamily;
};

struct policyData
{
    int policyNumber;
    std::string vehicleRego, vehicleName, vehicleModel,currentUser,insuranceType;
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

    newUserJson["user"][newUser.userName]["password"] = newUser.password;
    newUserJson["user"][newUser.userName]["userName"] = newUser.userName;
    newUserJson["user"][newUser.userName]["firstName"] = newUser.firstName;
    newUserJson["user"][newUser.userName]["lastName"] = newUser.lastName;
    newUserJson["user"][newUser.userName]["DOB"] = newUser.DOB;
    newUserJson["user"][newUser.userName]["contactNumber"] = newUser.contactNumber;
    newUserJson["user"][newUser.userName]["gender"] = newUser.gender;
    newUserJson["user"][newUser.userName]["email"] = newUser.email;
    newUserJson["user"][newUser.userName]["address"] = newUser.address;
    newUserJson["user"][newUser.userName]["vehicleRego"] = newUser.vehicleRego;
    newUserJson["user"][newUser.userName]["isAdmin"] = newUser.isAdmin;

    std::fstream f("./Customer_registration.json",std::ios::out);
    f << std::setw(4) << newUserJson;
    f.close();
}

void adminDiscountUpdate(discountData update)
{
    nlohmann::json newDiscountJson = jsonDataFile();

    newDiscountJson["discount"]["FriendsAndFamily"] = update.friendsFamily;
    newDiscountJson["discount"]["MultiPolicy"] = update.multiPolicy;
    newDiscountJson["discount"]["NewSignUp"] = update.newSignUp;
    newDiscountJson["discount"]["Renewal"] = update.renewal;

    std::fstream f("./Customer_registration.json", std::ios::out);
    f << std::setw(4) << newDiscountJson;
    f.close();
}

void newPolicy(policyData newPolicy)
{
    nlohmann::json newPolicyJson = jsonDataFile();

    newPolicyJson["policy"][newPolicy.currentUser][newPolicy.policyNumber]["PolicyNum"] = newPolicy.policyNumber;
    newPolicyJson["policy"][newPolicy.currentUser][newPolicy.policyNumber]["VehicleModel"] = newPolicy.vehicleModel;
    newPolicyJson["policy"][newPolicy.currentUser][newPolicy.policyNumber]["VehicleName"] = newPolicy.vehicleName;
    newPolicyJson["policy"][newPolicy.currentUser][newPolicy.policyNumber]["VehicleRego"] = newPolicy.vehicleRego;
    newPolicyJson["policy"][newPolicy.currentUser][newPolicy.policyNumber]["InsuranceType"] = newPolicy.insuranceType;

    std::fstream f("./Customer_registration.json", std::ios::out);
    f << std::setw(4) << newPolicyJson;
    f.close();
}