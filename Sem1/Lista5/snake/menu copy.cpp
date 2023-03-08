#include <iostream>
#include <conio.h>
#include <string>

void start_menu()
{
    int w = 72;
    system("clear");
    for (int i = 0; i < 15; i++)
    {
        std::cout << std::endl;
    }
    std::cout.width(80);
    std::cout << "Guess the number game!" << std::endl;
    std::cout.width(w);
    std::cout << "(*) Start" << std::endl;
    std::cout.width(71);
    std::cout << "( ) Exit" << std::endl;
    for (int i = 0; i < 15; i++)
    {
        std::cout << std::endl;
    }
}

void exit_menu()
{
    int w = 72;
    system("clear");
    for (int i = 0; i < 15; i++)
    {
        std::cout << std::endl;
    }
    std::cout.width(80);
    std::cout << "Guess the number game!" << std::endl;
    std::cout.width(w);
    std::cout << "( ) Start" << std::endl;
    std::cout.width(71);
    std::cout << "(*) Exit" << std::endl;
    for (int i = 0; i < 15; i++)
    {
        std::cout << std::endl;
    }
}

void default_menu() {
    int w = 72;
    system("clear");
    for (int i = 0; i < 15; i++)
    {
        std::cout << std::endl;
    }
    std::cout.width(80);
    std::cout << "Guess the number game!" << std::endl;
    std::cout.width(w);
    std::cout << "( ) Start" << std::endl;
    std::cout.width(71);
    std::cout << "( ) Exit" << std::endl;
    for (int i = 0; i < 15; i++)
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