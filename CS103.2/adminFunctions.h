#pragma once

#include <iostream>
#include <Windows.h>
#include "json.hpp"
#include "fileManagementFunctions.h"
#include "menuFunctions.h"

void adminMenu();
void customerScreen();

void adminCustomerReport()
{
    nlohmann::json userInfo = jsonDataFile();

    std::cout << "Customer Report Screen" << std::endl << std::endl;

    std::cout << "Number of registed users: " << userInfo["user"].size() << std::endl << std::endl;
    std::cout << "Registered Users:" << std::endl;


    for (const auto& item : userInfo["user"].items()) {

        const auto& val = item.value();
        std::cout << std::endl;
        std::cout << val["userName"] << std::endl;
        std::cout << "  " << "Password" << ": " << val["password"] << std::endl;
        std::cout << "  " << "Username" << ": " << val["userName"] << std::endl;
        std::cout << "  " << "First Name" << ": " << val["firstName"] << std::endl;
        std::cout << "  " << "Last Name" << ": " << val["lastName"] << std::endl;
        std::cout << "  " << "Date of Birth" << ": " << val["DOB"] << std::endl;
        std::cout << "  " << "Contact Number" << ": " << val["contactNumber"] << std::endl;
        std::cout << "  " << "Gender" << ": " << val["gender"] << std::endl;
        std::cout << "  " << "Email" << ": " << val["email"] << std::endl;
        std::cout << "  " << "Address" << ": " << val["address"] << std::endl;
        std::cout << "  " << "Vehicle Registration" << ": " << val["vehicleRego"] << std::endl;
    }

    system("pause");
    system("cls");
    adminMenu();
}

void updateDiscounts()
{
    int userInput;
    discountData newDiscounts;

    std::cout << "Enter the new value for the Friends and Family discount." << std::endl;
    std::cin >> userInput;
    newDiscounts.friendsFamily = userInput;

    std::cout << "Enter the new value for the Multi Policy discount" << std::endl;
    std::cin >> userInput;
    newDiscounts.multiPolicy = userInput;

    std::cout << "Enter the value for the New Signup discount" << std::endl;
    std::cin >> userInput;
    newDiscounts.newSignUp = userInput;

    std::cout << "Enter the value for the Renewal discount" << std::endl;
    std::cin >> userInput;
    newDiscounts.renewal = userInput;

    adminDiscountUpdate(newDiscounts);
    system("pause");
    system("cls");
    adminMenu();
}

#include <iostream>
#include <iomanip>
#include "json.hpp"

void printAllClaims()
{
    nlohmann::json jsonData = jsonDataFile();

    if (jsonData.contains("user")) {
        for (const auto& user : jsonData["user"].items()) {
            if (user.value().contains("claims")) {
                std::cout << "User: " << user.key() << std::endl;
                for (const auto& claim : user.value()["claims"]) {
                    std::cout << "Policy Number: " << claim["PolicyNum"] << std::endl;
                    std::cout << "Full Name: " << claim["FullName"] << std::endl;
                    std::cout << "Date: " << claim["Date"] << std::endl;
                    std::cout << "Time: " << claim["Time"] << std::endl;
                    std::cout << "Incident Description: " << claim["IncidentDescription"] << std::endl;
                    std::cout << "Complaint Details: " << claim["ComplaintDetails"] << std::endl;
                    std::cout << "Contact Details: " << claim["ContactDetails"] << std::endl;
                    std::cout << std::string(50, '-') << std::endl;
                }
            }
        }
    }
    else {
        std::cout << "No claims found in the JSON." << std::endl;
    }
    system("pause");
    system("cls");
    adminMenu();
}

void printAllRenewals()
{
    nlohmann::json jsonData = jsonDataFile();

    if (jsonData.contains("user")) {
        for (const auto& user : jsonData["user"].items()) {
            if (user.value().contains("renewals")) {
                std::cout << "User: " << user.key() << std::endl;
                for (const auto& renewal : user.value()["renewals"]) {
                    std::cout << "Policy Number: " << renewal["PolicyNum"] << std::endl;
                    std::cout << "Full Name: " << renewal["FullName"] << std::endl;
                    std::cout << "New Policy Name: " << renewal["NewPolicyName"] << std::endl;
                    std::cout << "Contact Number: " << renewal["ContactNumber"] << std::endl;
                    std::cout << "Visa Card Number: " << renewal["VisaCardNumber"] << std::endl;
                    std::cout << std::string(50, '-') << std::endl;
                }
            }
        }
    }
    else {
        std::cout << "No renewals found in the JSON." << std::endl;
    }
    system("pause");
    system("cls");
    adminMenu();
}


void adminMenu()
{
    char userInput;

    std::cout << "Admin Menu" << std::endl << std::endl;
    std::cout << "1. Customer Report" << std::endl;
    std::cout << "2. Weekly Claim Report" << std::endl;
    std::cout << "3. Weekly Renewal Report" << std::endl;
    std::cout << "4. Weekly New Registration Report" << std::endl;
    std::cout << "5. Update Policy Info / Publish Special Discounts" << std::endl;
    std::cout << "6. Return to Menu" << std::endl;

    std::cin >> userInput;

    if (validNumber('1', '6', userInput))
    {
        switch (userInput)
        {
        case '1':
            Sleep(500);
            system("cls");
            adminCustomerReport();
            return;
        case '2':
            Sleep(500);
            system("cls");
            printAllClaims();
            return;
        case '3':
            Sleep(500);
            system("cls");
            printAllRenewals();
            return;
        case '4':
            Sleep(500);
            system("cls");
            adminCustomerReport();
            return;
        case '5':
            Sleep(500);
            system("cls");
            updateDiscounts();
            return;
        case '6':
            Sleep(500);
            system("cls");
            customerScreen();
            return;
        }
    }
    else
    {
        std::cout << "Incorrect input...." << std::endl;
        Sleep(500);
        system("cls");
        adminMenu();
    }
}