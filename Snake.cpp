#include <iostream>
#include <cstdlib>
#include "Snake.h"

using namespace std;

Snake::Snake()
{
    x = 5;
    y = 5;
    game_over = false;
}

bool Snake::play()
{
    char input;

    while (!game_over)
    {
        system("cls");

        // board creation
        for (int row = 0; row < 10; row++)
        {
            for (int col = 0; col < 10; col++)
            {
                if (row == y && col == x)
                    cout << "O ";
                else
                    cout << ". ";
            }
            cout << endl;
        }

        cout << "\nWASD to move, Q to quit\n";
        cin >> input;

        if (input == 'w') y--;
        else if (input == 's') y++;
        else if (input == 'a') x--;
        else if (input == 'd') x++;
        else if (input == 'q') game_over = true;

        // wall collision
        if (x < 0 || x >= 10 || y < 0 || y >= 10)
            game_over = true;
    }

    return true;
}
