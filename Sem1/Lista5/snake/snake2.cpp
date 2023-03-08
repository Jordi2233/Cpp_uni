#include <iostream>
#include <chrono>
#include <thread>   //dwie biblioteki do dluzszego sleepa
#include <unistd.h> //<stdio.h>
#include <conio.h>  //console input output
#include <vector>
#include "menu.cpp"
#include "reset.cpp"

// using namespace std;
bool endgame;
const int width = 20;
const int height = 20;
int x, y, ox, oy, points;
std::vector<int> tailX(100), tailY(100);
int No;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
} dir;

void setup()
{
    endgame = false;
    x = width / 2;
    y = height / 2;
    ox = rand() % width;
    oy = rand() % height;
    points = 0;
}
void draw()
{
    system("clear");
    // set width of cout

    std::cout.width(47);
    for (int i = 0; i < width + 1 + 1; i++)
        std::cout << "=";
    std::cout << std::endl;

    for (int i = 0; i < height; i++)
    {
        std::cout.width(47);
        for (int j = 0; j < height; j++)
        {
            if (j == 0)
                std::cout << "|";
            if (i == y && j == x)
                std::cout << "\x1b[102;90m%\x1b[0m";
            else if (i == oy && j == ox)
                std::cout << "\x1B[101m$\x1b[0m";

            else
            {
                bool print = false;
                for (int k = 0; k < No; k++)
                {

                    if (tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "\x1b[102;90mo\x1b[0m";
                        print = true;
                    }
                }
                if (!print)
                    std::cout << "\x1b[107m \x1b[0m";
            }
            if (j == width - 1)
                std::cout << "|";
        }
        std::cout << std::endl;
    }
    std::cout.width(47);
    for (int i = 0; i < width + 2; i++)
        std::cout << "=";
    std::cout << std::endl;
    std::cout.width(67);
    std::cout << "Your actual score is: " << points << std::endl;
}
void input()
{
    if (_kbhit())
    {
        switch (_getche())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            endgame = true;
            break;
        }
    }
}
void logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < No; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case UP:
        y--;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x > (width - 1) || x < 0 || y > (height - 1) || y < 0) // sprawdza czy nie uderzyłeś w ścianę
        endgame = true;
    for (int i = 0; i < No; i++) // sprawdza czy nie uderzyłeś w siebie
        if (tailX[i] == x && tailY[i] == y)
            endgame = true;

    if (x == ox && y == oy)
    {

        points += 10;
        ox = rand() % width;
        oy = rand() % height;
        No++;
    }
}
int main()
{
    menu();
    while (true)
    {
        system("clear");
        setup();
        std::chrono::milliseconds timespan(200);
        std::this_thread::sleep_for(timespan);
        while (!endgame)
        {
            draw();
            input();
            logic();
            std::chrono::milliseconds timespan(90);
            std::this_thread::sleep_for(timespan);
        }
        reset(points);
        points = 0;

        No = 0;
    }

    return 0;
}
