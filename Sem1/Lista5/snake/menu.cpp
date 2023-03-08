#include <iostream>
#include <conio.h>
#include <string>

int mStart = 60, mExit = 59, mWelcome = 70, mHeight = 10;
std::string welcome = "Welcome in the snake game!";

void start_menu()
{
    system("clear");
    for (int i = 0; i < mHeight; i++)
    {
        std::cout << std::endl;
    }
    std::cout.width(mWelcome);
    std::cout << welcome << std::endl;
    std::cout.width(mStart);
    std::cout << "(*) Start" << std::endl;
    std::cout.width(mExit);
    std::cout << "( ) Exit" << std::endl;
    for (int i = 0; i < mHeight; i++)
    {
        std::cout << std::endl;
    }
}

void exit_menu()
{
    system("clear");
    for (int i = 0; i < mHeight; i++)
    {
        std::cout << std::endl;
    }
    std::cout.width(mWelcome);
    std::cout << welcome << std::endl;
    std::cout.width(mStart);
    std::cout << "( ) Start" << std::endl;
    std::cout.width(mExit);
    std::cout << "(*) Exit" << std::endl;
    for (int i = 0; i < mHeight; i++)
    {
        std::cout << std::endl;
    }
}

void default_menu()
{
    system("clear");
    for (int i = 0; i < mHeight; i++)
    {
        std::cout << std::endl;
    }
    std::cout.width(mWelcome);
    std::cout << welcome << std::endl;
    std::cout.width(mStart);
    std::cout << "( ) Start" << std::endl;
    std::cout.width(mExit);
    std::cout << "( ) Exit" << std::endl;
    for (int i = 0; i < mHeight; i++)
    {
        std::cout << std::endl;
    }
}

void menu()
{
    default_menu();
    int x = 0;
    int mode = 0;
    while (mode != 69)
    {
        _kbhit();

        x = _getche();
        if (x == 119)
        {
            start_menu();
            mode = 1;
        }
        else if (x == 115)
        {
            exit_menu();
            mode = -1;
        }
        else if (x == 10)
        {
            if (mode == 1)
            {
                system("clear");
                mode = 69;
            }
            else if (mode == -1)
            {
                exit(0);
            }
        }
    }
}