#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Snake.h"
#include <conio.h> // for making it so that you dont have to press enter key each time :D
#include <windows.h>

using namespace std;

Snake::Snake()
{
    x = 5;
    y = 5;
    game_over = false;
}

bool Snake::play()
{
    srand((unsigned int)time(NULL));

    const int width = 20;
    const int height = 10;

    const int win_length = 15;

    int snake_x[100];
    int snake_y[100];

    int snake_length = 1;

    // starting position !
    snake_x[0] = 5;
    snake_y[0] = 5;

    char direction = 'd';
    bool running = true;

    int food_x = rand() % 8 + 1;
    int food_y = rand() % 8 + 1;

    while (running)
    {
        system("cls");

        // board
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                bool is_snake = false;

                for (int i = 0; i < snake_length; i++)
                {
                    if (snake_x[i] == x && snake_y[i] == y) // using arrays to add to snake length; everytime snake eats, body grows by 1
                    {
                        is_snake = true;
                        break;
                    }
                }

                if (is_snake)
                    cout << "O";
                else if (x == food_x && y == food_y)
                    cout << "*";
                else
                    cout << ".";
            }
            cout << endl;
        }


        // makes it so that you dont have to press enter to move!
        if (_kbhit())
        {
            char input = _getch();

            if (input == 'w' || input == 'W')
                direction = 'w';
            else if (input == 's' || input == 'S')
                direction = 's';
            else if (input == 'a' || input == 'A')
                direction = 'a';
            else if (input == 'd' || input == 'D')
                direction = 'd';
            else if (input == 'q' || input == 'Q')
                return false;
        }

        // moving body
        for (int i = snake_length - 1; i > 0; i--)
        {
            snake_x[i] = snake_x[i - 1];
            snake_y[i] = snake_y[i - 1];
        }


        // moving head
        if (direction == 'w')
        {
            snake_y[0]--;
        }
        else if (direction == 's')
        {
            snake_y[0]++;
        }
        else if (direction == 'a')
        {
            snake_x[0]--;
        }
        else if (direction == 'd') {
            snake_x[0]++;
        }


        // wall collision (game over)
        if (snake_x[0] < 0 || snake_x[0] >= width || snake_y[0] < 0 || snake_y[0] >= height)
        {
            cout << "==============================\n";
            cout << "           YOU LOST!\n";
            cout << "    FEEL FREE TO TRY AGAIN\n";
            cout << "==============================\n";
            cin.get();

            return false;
        }

        // collision with snake body
        for (int i = 1; i < snake_length; i++)
        {
            if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
            {
                cout << "==============================\n";
                cout << "           YOU LOST!\n";
                cout << "    FEEL FREE TO TRY AGAIN\n";
                cout << "==============================\n";
                cin.get();

                return false;
            }
        }

        // collision with food = snake grows
        if (snake_x[0] == food_x && snake_y[0] == food_y)
        {
            snake_length++;

            if (snake_length >= win_length)
            {
                system("cls");
                cout << "==============================\n";
                cout << "        YOU WON SNAKE!\n";
                cout << "      +100 ARCADE POINTS\n";
                cout << "==============================\n";
                cin.get();
                return true;
            }

            food_x = rand() % 8 + 1;
            food_y = rand() % 8 + 1;
        }

        cout << "\nLENGTH: " << snake_length << " / " << win_length << endl;




        Sleep(500);
    }

    return true;
}

