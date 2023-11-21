#pragma once

#include <iostream>
#include <fstream>
#include "json.hpp"

struct RenewalData
{
    int policyNumber;
    std::string fullName;
    std::string newPolicyName;
    std::string contactNumber;
    std::string visaCardNumber;
    std::string currentUser;
};

struct ClaimData {
    int policyNumber;
    std::string fullName;
    std::string date;
    std::string time;
    std::string incidentDescription;
    std::string complaintDetails;
    std::string contactDetails;
    std::string currentUser;
};

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

    if (!f.is_open())
    {
        std::cerr << "Error opening Customer_registration.json. Returning an empty JSON object." << std::endl;
        return {};
    }

    nlohmann::json userDataJson;

    try
    {
        userDataJson = nlohmann::json::parse(f);
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cerr << "Error parsing JSON: " << e.what() << ". Returning an empty JSON object." << std::endl;
    }

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

    // Check if the user already exists in the JSON
    if (newPolicyJson["user"].contains(newPolicy.currentUser)) {
        // Check if the user has a "policies" array
        if (!newPolicyJson["user"][newPolicy.currentUser].contains("policies")) {
            newPolicyJson["user"][newPolicy.currentUser]["policies"] = {}; // Initialize the "policies" array
        }

        // Create a JSON object for the new policy
        nlohmann::json policyEntry = {
            {"PolicyNum", newPolicy.policyNumber},
            {"VehicleModel", newPolicy.vehicleModel},
            {"VehicleName", newPolicy.vehicleName},
            {"VehicleRego", newPolicy.vehicleRego},
            {"InsuranceType", newPolicy.insuranceType}
        };

        // Add the policy entry to the "policies" array
        newPolicyJson["user"][newPolicy.currentUser]["policies"].push_back(policyEntry);
    }
    else {
        std::cout << "User not found in JSON. Unable to add policy." << std::endl;
    }

    // Write the modified JSON back to the file
    std::fstream f("./Customer_registration.json", std::ios::out);
    f << std::setw(4) << newPolicyJson;
    f.close();
}

void saveClaimData(const ClaimData& claim)
{
    nlohmann::json claimJson = jsonDataFile();

    if (claimJson["user"].contains(claim.currentUser)) {
        if (!claimJson["user"][claim.currentUser].contains("claims")) {
            claimJson["user"][claim.currentUser]["claims"] = nlohmann::json::array(); // Initialize the "claims" array
        }

        nlohmann::json claimEntry = {
            {"PolicyNum", claim.policyNumber},
            {"FullName", claim.fullName},
            {"Date", claim.date},
            {"Time", claim.time},
            {"IncidentDescription", claim.incidentDescription},
            {"ComplaintDetails", claim.complaintDetails},
            {"ContactDetails", claim.contactDetails}
        };

        claimJson["user"][claim.currentUser]["claims"].push_back(claimEntry);
    }
    else {
        std::cout << "User not found in JSON. Unable to add claim." << std::endl;
    }

    std::fstream f("./Customer_registration.json", std::ios::out);
    f << std::setw(4) << claimJson;
    f.close();
}

void saveRenewalData(const RenewalData& renewalData)
{
    nlohmann::json renewalJson = jsonDataFile();

    if (renewalJson["user"].contains(renewalData.currentUser)) {
        if (!renewalJson["user"][renewalData.currentUser].contains("renewals")) {
            renewalJson["user"][renewalData.currentUser]["renewals"] = nlohmann::json::array(); // Initialize the "renewals" array
        }

        nlohmann::json renewalEntry = {
            {"PolicyNum", renewalData.policyNumber},
            {"FullName", renewalData.fullName},
            {"NewPolicyName", renewalData.newPolicyName},
            {"ContactNumber", renewalData.contactNumber},
            {"VisaCardNumber", renewalData.visaCardNumber}
        };

        renewalJson["user"][renewalData.currentUser]["renewals"].push_back(renewalEntry);
    }
    else {
        std::cout << "User not found in JSON. Unable to add renewal." << std::endl;
    }

    std::fstream f("./Customer_registration.json", std::ios::out);
    f << std::setw(4) << renewalJson;
    f.close();
}