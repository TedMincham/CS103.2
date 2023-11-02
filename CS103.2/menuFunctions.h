#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>

void login()
{

}

void signUp()
{

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