#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "fileManagementFunctions.h"
#include "verificationFunctions.h"

void mainMenu();
void login();
void signUp();

void login()
{

    std::string userName,passWord;
    int loginAttempts = 3;

    std::cout << "Enter your username" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, userName);
    
    std::cout << "Enter your password" << std::endl;
    std::getline(std::cin, passWord);

    if (validateLogin(userName,passWord))
    {
        std::cout << "Sign in sucessful" << std::endl;
        Sleep(1000);
    }
    else if (loginAttempts == 0)
    {
        std::cout << "Failed to login too many times, please try again later";
        Sleep(2000);
        exit(0);
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

    std::cout << "Enter your email" << std::endl;
    std::getline(std::cin, userInput);
    newuser.email = userInput;

    std::cout << "Enter your address" << std::endl;
    std::getline(std::cin, userInput);
    newuser.address = userInput;

    std::cout << "Enter your vehicle registration number" << std::endl;
    std::getline(std::cin, userInput);
    newuser.vehicleRego = userInput;

    newuser.isAdmin = 0;

    std::cout << "Sign up successful" << std::endl;
    addNewUser(newuser);
    //createData();
}

void mainMenu()
{

    char userInput;

    std::cout << "*Insert Company Name*" << std::endl << std::endl;
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
        else
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