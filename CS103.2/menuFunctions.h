#pragma once

#include <climits>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "fileManagementFunctions.h"
#include "verificationFunctions.h"
#include "adminFunctions.h"

void mainMenu();
void login();
void signUp();
void customerScreen();
void registerPolicy();

std::string currentUser;

int loginAttempts = 3;

void login()
{

    std::string userName,passWord;
    

    std::cout << "Enter your username" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, userName);
    
    std::cout << "Enter your password" << std::endl;
    std::getline(std::cin, passWord);

    if (validateLogin(userName,passWord))
    {
        std::cout << "Sign in sucessful" << std::endl;
        currentUser = userName;
        Sleep(1000);
        system("cls");
        customerScreen();
    }
    else if (loginAttempts == 0)
    {
        std::cout << "Failed to login too many times, please try again later";
        Sleep(2000);
        system("cls");
        loginAttempts = 3;
        mainMenu();
    }
    else
    {
        loginAttempts--;
        std::cout << "Invalid login, try again" << std::endl;
        Sleep(1000);
        system("cls");
        mainMenu();
    }
}

void signUp()
{
    userData newuser;
    std::string userInput;

    std::cout << "Enter your desired username" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, userInput);
    newuser.userName = userInput;

    std::cout << "Enter your desired password" << std::endl;
    std::getline(std::cin, userInput);
    newuser.password = userInput;

    std::cout << "Enter your first name" << std::endl;
    std::getline(std::cin, userInput);
    newuser.firstName = userInput;

    std::cout << "Enter your last name" << std::endl;
    std::getline(std::cin, userInput);
    newuser.lastName = userInput;

    std::cout << "Enter your date of birth" << std::endl;
    std::getline(std::cin, userInput);
    newuser.DOB = userInput;

    std::cout << "Enter your contact number" << std::endl;
    std::getline(std::cin, userInput);
    newuser.contactNumber = userInput;

    std::cout << "Enter your gender" << std::endl;
    std::cout << "Press 1 for Male, 2 for Female" << std::endl;
    std::getline(std::cin, userInput);
    if (userInput == "1")
    {
        userInput = "Male";
    }
    else if (userInput == "2")
    {
        userInput = "Female";
    }
    newuser.gender = userInput;

    do
    {
        std::cout << "Enter your email" << std::endl;
        std::getline(std::cin, userInput);
        if (validEmail(userInput))
        {
            newuser.email = userInput;
        }
        else
        {
            std::cout << "Thie is not a valid email" << std::endl;
            Sleep(1000);
            system("cls");

        }
    } while (!validEmail(userInput));
    
    

    std::cout << "Enter your address" << std::endl;
    std::getline(std::cin, userInput);
    newuser.address = userInput;

    std::cout << "Enter your vehicle registration number" << std::endl;
    std::getline(std::cin, userInput);
    newuser.vehicleRego = userInput;

    newuser.isAdmin = 0;

    std::cout << "Sign up successful" << std::endl;
    addNewUser(newuser);
    mainMenu();   
}

void insurancePolicy()
{
    char userInput;

    std::cout << "Here are the avaliable Policy Types" << std::endl << std::endl;

    std::cout << "Third Party" << std::endl;
    std::cout << "  " << "Third-party insurance covers an individual or firm against a loss caused by some third party" << std::endl;
    std::cout << "  " << "Car fixed rate 200$" << "   " << "Motorcycle fixed rate 90$" << std::endl << std::endl;

    std::cout << "Fire and Theft" << std::endl;
    std::cout << "  " << "Fire and Theft insurance covers an indivdual or firm again a loss caused by fire or theft" << std::endl;
    std::cout << "  " << "Car fixed rate 150$" << "   " << "Motorcycle fixed rate 75$" << std::endl << std::endl;

    std::cout << "Comprehensive" << std::endl << std::endl;
    std::cout << "  " << "Comprehensive insurances covers and idividual or firm against a loss caused by accidental damage or from another \n  individual" << std::endl;
    std::cout << "  " << "Car fixed rate 250$" << "   " << "Motorcycle fixed rate 105$" << std::endl << std::endl << std::endl;

    std::cout << "Press 1. to register a new Policy" << std::endl;
    std::cout << "Press 2. to return to the menu" << std::endl;

    std::cin >> userInput;

    if (validNumber('1', '2', userInput))
    {
        switch (userInput)
        {
        case '1':
            Sleep(500);
            system("cls");
            registerPolicy();
            return;
        case '2':
            Sleep(500);
            system("cls");
            customerScreen();
            return;
        }
    }

}

void registerPolicy()
{
    policyData newuser;
    char userInput;
    std::string userInputS;

    do {
        std::cout << "Thanks for choosing NZ Insurance for your new policy" << std::endl;
        std::cout << "Press 1. to register Third Party insurance" << std::endl;
        std::cout << "Press 2. to register Fire and Theft insurance" << std::endl;
        std::cout << "Press 3. to register Comprehensive insurance" << std::endl;
        std::cout << "Press 4. to return to the customer screen" << std::endl;

        std::cin >> userInput;

        switch (userInput)
        {
        case '1':
            newuser.insuranceType = "Third Party";
            std::cout << "Your chosen policy is: Third Party" << std::endl;
            break;
        case '2':
            newuser.insuranceType = "Fire and Theft";
            std::cout << "Your chosen policy is: Fire and Theft" << std::endl;
            break;
        case '3':
            newuser.insuranceType = "Comprehensive";
            std::cout << "Your chosen policy is: Comprehensive" << std::endl;
            break;
        case '4':
            Sleep(500);
            system("cls");
            customerScreen();
            break;
        default:
            std::cout << "Invalid input. Please try again." << std::endl;
            continue;
        }

        std::cin.ignore(INT_MAX, '\n');

        int policyNum = randomPolicyNumber();
        std::cout << "Your policy number is: " << policyNum << std::endl;
        newuser.policyNumber = policyNum;

        std::cout << "Enter your vehicle registration number" << std::endl;
        std::getline(std::cin, userInputS);
        newuser.vehicleRego = userInputS;

        std::cout << "Enter your Vehicles Model" << std::endl;
        std::getline(std::cin, userInputS);
        newuser.vehicleModel = userInputS;

        std::cout << "Enter your Vehicles Name" << std::endl;
        std::getline(std::cin, userInputS);
        newuser.vehicleName = userInputS;

        newuser.currentUser = currentUser;
        break;  // Exit the loop after processing the user's choice
    } while (true);

    std::cout << "Thanks for Signing up for your new insurane policy " << currentUser << std::endl;
    newPolicy(newuser);
    Sleep(1000);
    system("cls");
    customerScreen();
}

void mainMenu()
{

    char userInput;

    std::cout << "NZ Insurance" << std::endl << std::endl;
    std::cout << std::setw(14) << "1. Login" << std::endl;
    std::cout << std::setw(15) << "2. Signup" << std::endl;
    std::cout << std::setw(13) << "3. Exit" << std::endl;

    std::cin >> userInput;

    if (validNumber('1', '3', userInput))
    {
        if (userInput == '1')
        {
            system("cls");
            login();
        }
        else if (userInput == '2')
        {
            system("cls");
            signUp();
        }
        else if (userInput == '3')
        {
            exit(0);
        }
    }
    else
    {
        std::cout << "Incorrect input..." << std::endl;
        Sleep(500);
        system("cls");
        mainMenu();
    }
}


void benefitsMenu()
{
    nlohmann::json userInfo = jsonDataFile();

    std::cout << "Here is a list of Benefits for using NZ Insurance" << std::endl << std::endl;
    std::cout << "The Family and Friends discount of " << userInfo["discount"]["FriendsAndFamily"] << "%" << std::endl;
    std::cout << "The Multi Policy discount of " << userInfo["discount"]["MultiPolicy"] << "%" << std::endl;
    std::cout << "The New Signup discount of " << userInfo["discount"]["NewSignUp"] << "%" << std::endl;
    std::cout << "The Renewal discount of " << userInfo["discount"]["Renewal"] << "%" << std::endl;

    system("pause");
    system("cls");
    customerScreen();

}


void registerClaim()
{
    ClaimData newClaim;

    newClaim.currentUser = currentUser;
    // Prompt the user for claim information
    std::cout << "Enter your policy number: ";
    std::cin >> newClaim.policyNumber;

    // Add additional prompts for other claim information (full name, date, time, etc.)
    std::cin.ignore(); // Clear the newline character from the buffer
    std::cout << "Enter your full name: ";
    std::getline(std::cin, newClaim.fullName);

    std::cout << "Enter the date of the incident: ";
    std::getline(std::cin, newClaim.date);

    std::cout << "Enter the time of the incident: ";
    std::getline(std::cin, newClaim.time);

    std::cout << "Enter a description of the incident: ";
    std::getline(std::cin, newClaim.incidentDescription);

    std::cout << "Enter complaint details: ";
    std::getline(std::cin, newClaim.complaintDetails);

    std::cout << "Enter your contact details: ";
    std::getline(std::cin, newClaim.contactDetails);

    // Save the claim data to a file
    saveClaimData(newClaim);

    std::cout << "Claim successfully registered!" << std::endl;
    Sleep(1000);
    system("cls");
    customerScreen();
}

void renewalScreen()
{
    std::cout << "Renewal Process Description:\n";
    std::cout << "Thank you for choosing to renew your policy with NZ Insurance.\n";
    std::cout << "Please provide the following information for the renewal:\n";

    RenewalData renewalData;
    renewalData.currentUser = currentUser;

    std::cout << "Enter your policy number: ";
    std::cin >> renewalData.policyNumber;

    std::cout << "Enter your full name: ";
    std::cin.ignore();
    std::getline(std::cin, renewalData.fullName);

    std::cout << "Enter the new policy name: ";
    std::getline(std::cin, renewalData.newPolicyName);

    std::cout << "Enter your contact number: ";
    std::getline(std::cin, renewalData.contactNumber);

    std::cout << "Enter your Visa card number: ";
    std::getline(std::cin, renewalData.visaCardNumber);

    saveRenewalData(renewalData);

    std::cout << "Renewal information successfully submitted!\n";
    Sleep(1000);
    system("cls");
    customerScreen();
}

void customerScreen()
{
    nlohmann::json userInfo = jsonDataFile();
    char userInput;
    std::string activeUser = userInfo["user"][currentUser]["userName"];

    std::cout << "Welcome " << activeUser << std::endl;
    std::cout << "1. Policy and Insurance Application" << std::endl;
    std::cout << "2. Make a Claim" << std::endl;
    std::cout << "3. Renewal" << std::endl;
    std::cout << "4. Benefits of NZ insurance" << std::endl;
    std::cout << "5. Sign Out" << std::endl;
    if (userInfo["user"][currentUser]["isAdmin"] == true)
    {
        std::cout << "6. Admin Menu" << std::endl;
    }
    
    std::cin >> userInput;

    if (validNumber('1', '6', userInput))
    {
        switch (userInput) {
        case '1':
            Sleep(500);
            system("cls");
            insurancePolicy();
            return;
        case '2':
            Sleep(500);
            system("cls");
            registerClaim();
            return;
        case '3':
            Sleep(500);
            system("cls");
            renewalScreen();
            return;
        case '4':
            Sleep(500);
            system("cls");
            benefitsMenu();
            return;
        case '5':
            std::cout << "Signing out....." << std::endl;
            Sleep(500);
            system("cls");
            mainMenu();
            return;
        case '6':
            if (userInfo["user"][currentUser]["isAdmin"] == true)
            {
                Sleep(500);
                system("cls");
                adminMenu();
            }
            else
            {
                std::cout << "Incorrect input...." << std::endl;
                Sleep(500);
                system("cls");
                customerScreen();
            }
        }
        
    }
    else
    {
        std::cout << "Incorrect input...." << std::endl;
        Sleep(500);
        system("cls");
        customerScreen();
    }

} 