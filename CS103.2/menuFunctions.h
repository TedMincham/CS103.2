#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "fileManagementFunctions.h"

void login()
{

}

void signUp()
{
    userData newuser;
    std::string password, userName, firstName, lastName, DOB, contactNumber, gender, email, address, vehicleRego;

    std::cout << "Enter your desired username" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, userName);
    newuser.userName = userName;

    std::cout << "Enter your desired password" << std::endl;
    std::getline(std::cin, password);
    newuser.password = password;

    std::cout << "Enter your first name" << std::endl;
    std::getline(std::cin, firstName);
    newuser.firstName = firstName;

    std::cout << "Enter your last name" << std::endl;
    std::getline(std::cin, lastName);
    newuser.lastName = lastName;

    std::cout << "Enter your date of birth" << std::endl;
    std::getline(std::cin, DOB);
    newuser.DOB = DOB;

    std::cout << "Enter your contact number" << std::endl;
    std::getline(std::cin, contactNumber);
    newuser.contactNumber = contactNumber;

    std::cout << "Enter your gender" << std::endl;
    std::cout << "Press 1 for Male, 2 for Female" << std::endl;
    std::getline(std::cin, gender);
    if (gender == "1")
    {
        gender = "Male";
    }
    else if (gender == "2")
    {
        gender = "Female";
    }
    newuser.gender = gender;

    std::cout << "Enter your email" << std::endl;
    std::getline(std::cin, email);
    newuser.email = email;

    std::cout << "Enter your address" << std::endl;
    std::getline(std::cin, address);
    newuser.address = address;

    std::cout << "Enter your vehicle registration number" << std::endl;
    std::getline(std::cin, vehicleRego);
    newuser.vehicleRego = vehicleRego;

    newuser.isAdmin = 0;

    std::cout << "Sign up successful" << std::endl;
    addNewUser(newuser);
}

void mainMenu()
{

    int userInput;

    std::cout << "*Insert Company Name*" << std::endl << std::endl;
    std::cout << std::setw(14) << "1. Login" << std::endl;
    std::cout << std::setw(15) << "2. Signup" << std::endl;
    std::cout << std::setw(13) << "3. Exit" << std::endl;

    std::cin >> userInput;

    if (userInput == 1)
    {
        system("cls");
        login();
    }
    else if (userInput == 2)
    {
        system("cls");
        signUp();
    }
    else
    {
        exit(0);
    }
}