#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Breakout.h"

using namespace std;

Breakout::Breakout() {}

bool Breakout::play()
{
    const int width = 30;
    const int height = 15;

    // paddle
    int paddle_x = width / 2;
    int paddle_width = 7;  

    // ball
    int ball_x = width / 2;
    int ball_y = height - 3;
    int ball_dx = 1;
    int ball_dy = -1;

    // bricks
    int brick_width = 5;
    const int brick_count = 6;
    int brick_x[brick_count] = { 4, 8, 12, 16, 20, 24 };
    int brick_y = 2;
    bool brick_alive[brick_count];

    for (int i = 0; i < brick_count; i++)
        brick_alive[i] = true;

    while (true)
    {
        system("cls");

        // drawing ;P
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                bool drawn = false;

                // paddle
                if (y == height - 1)
                {
                    for (int i = -paddle_width / 2; i <= paddle_width / 2; i++)
                    {
                        if (x == paddle_x + i)
                        {
                            cout << "=";
                            drawn = true;
                        }
                    }
                }



                // ball
                if (x == ball_x && y == ball_y)
                {
                    cout << "O";
                    drawn = true;
                }

                // bricks
                for (int i = 0; i < brick_count; i++)
                {
                    if (brick_alive[i] &&
                        y == brick_y &&
                        x >= brick_x[i] &&
                        x < brick_x[i] + brick_width)
                    {
                        cout << "#";
                        drawn = true;
                    }
                }

                if (!drawn)
                    cout << " ";
            }
            cout << endl;
        }

        // input
        if (_kbhit())
        {
            char input = _getch();

            if (input == 'a' || input == 'A')
                paddle_x--;
            else if (input == 'd' || input == 'D')
                paddle_x++;
            else if (input == 'q' || input == 'Q')
                return false;
        }

        // keep paddle in bounds
        if (paddle_x < paddle_width / 2)
            paddle_x = paddle_width / 2;

        if (paddle_x > width - 1 - paddle_width / 2)
            paddle_x = width - 1 - paddle_width / 2;


        // move ball
        ball_x += ball_dx;
        ball_y += ball_dy;

        // wall bounce
        if (ball_x <= 0 || ball_x >= width - 1)
            ball_dx *= -1;

        if (ball_y <= 0)
            ball_dy *= -1;

        // paddle bounce, accepts if the ball hits the corner of the paddle
        if (ball_y >= height - 2 && ball_x >= paddle_x - paddle_width / 2 && ball_x <= paddle_x + paddle_width / 2)
        {
            ball_dy = -1;
        }


        // brick collision
        for (int i = 0; i < brick_count; i++)
        {
            if (brick_alive[i] && ball_y == brick_y && ball_x >= brick_x[i] && ball_x < brick_x[i] + brick_width)
            {
                brick_alive[i] = false;
                ball_dy *= -1;
            }
        }

        // lose condition
        if (ball_y >= height - 1)
        {
            system("cls");
            cout << "============================\n";
            cout << "        GAME OVER\n";
            cout << "============================\n";
            cin.get();
            return false;
        }

        
        bool all_broken = true;
        for (int i = 0; i < brick_count; i++)
        {
            if (brick_alive[i])
                all_broken = false;
        }

        if (all_broken)
        {
            system("cls");
            cout << "============================\n";
            cout << "      YOU WON BREAKOUT!\n";
            cout << "     +100 ARCADE POINTS\n";
            cout << "============================\n";
            cin.get();
            return true;
        }

        Sleep(160);
    }
}
