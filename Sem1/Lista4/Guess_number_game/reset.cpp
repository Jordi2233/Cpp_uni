#include <iostream>
#include <conio.h>
#include <string>

int rReset = 60, rExit = 59, rWelcome = 70, rHeight = 10;
std::string header = "Your score was: ";


void reset_menu(int points)
{
    system("clear");
    for (int i = 0; i < rHeight; i++)
    {
        std::cout << std::endl;
    }
    std::cout.width(rWelcome);
    std::cout << header << points << std::endl;
    std::cout.width(rReset);
    std::cout << "(*) Reset" << std::endl;
    std::cout.width(rExit);
    std::cout << "( ) Exit" << std::endl;
    for (int i = 0; i < rHeight; i++)
    {
        std::cout << std::endl;
    }
}

void exit_reset_menu(int points)
{
    system("clear");
    for (int i = 0; i < rHeight; i++)
    {
        std::cout << std::endl;
    }
    std::cout.width(rWelcome);
    std::cout << header << points << std::endl;
    std::cout.width(rReset);
    std::cout << "( ) Reset" << std::endl;
    std::cout.width(rExit);
    std::cout << "(*) Exit" << std::endl;
    for (int i = 0; i < rHeight; i++)
    {
        std::cout << std::endl;
    }
}

void default_reset_menu(int points) {
    system("clear");
    for (int i = 0; i < rHeight; i++)
    {
        std::cout << std::endl;
    }
    std::cout.width(rWelcome);
    std::cout << header << points << std::endl;
    std::cout.width(rReset);
    std::cout << "( ) Next lvl" << std::endl;
    std::cout.width(rExit);
    std::cout << "( ) Exit" << std::endl;
    for (int i = 0; i < rHeight; i++)
    {
        std::cout << std::endl;
    }
}

void reset(int points)
{
    default_reset_menu(points);
    int x = 0;
    int mode = 0;
    while (mode != 69)
    {
        _kbhit();

        x = _getche();
        if (x == 119)
        {
            reset_menu(points);
            mode = 1;
        }
        else if (x == 115)
        {
            exit_reset_menu(points);
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