#include "game.cpp"
#include "menu.cpp"
#include "reset.cpp"

int y = 3;

int main()
{

    menu();
    system("clear");
    game(2, 1);
    while (y != 2000)
    {
        reset();
        game(y - 1, y);
        y++;
    }


    return 0;
}