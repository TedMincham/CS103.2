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
void customerScreen();

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

    std::cout << "Enter your email" << std::endl;
    std::getline(std::cin, userInput);
    if (validEmail(userInput))
    {
        newuser.email = userInput;
    }
    else
    {
        std::cout << "Thie is not a valid email" << std::endl;
        
        // need to turn this code into a dowhile loop? Maybe

    }
    

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

void customerScreen()
{
    nlohmann::json userInfo = jsonDataFile();
    char userInput;

    std::cout << "Welcome " << userInfo[currentUser]["userName"] << std::endl;
    std::cout << "1. Policy and Insurance Application" << std::endl;
    std::cout << "2. Make a Claim" << std::endl;
    std::cout << "3. Renewal" << std::endl;
    std::cout << "4. Benefits of NZ insurance" << std::endl;
    std::cout << "5. Sign Out" << std::endl;
    if (userInfo[currentUser]["isAdmin"] == true)
    {
        std::cout << "6. Admin Menu" << std::endl;
    }
    
    std::cin >> userInput;

    if (validNumber('1', '6', userInput))
    {
        switch (userInput) {
        case '1':
            return;
        case '2':
            return;
        case '3':
            return;
        case '4':
            return;
        case '5':
            std::cout << "Signing out....." << std::endl;
            Sleep(500);
            system("cls");
            mainMenu();
            return;
        case '6':
            if (userInfo[currentUser]["isAdmin"] == true)
            {

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