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
            return;
        case '3':
            return;
        case '4':
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