#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Pong.h"

using namespace std;

Pong::Pong()
{
}

bool Pong::play()
{
    const int width = 40;
    const int height = 15;

    int player_y = height / 2;
    int npc_y = height / 2;

    int ball_x = width / 2;
    int ball_y = height / 2;

    int ball_dx = -1;
    int ball_dy = 1;

    int player_score = 0;
    int npc_score = 0;

    int chance = rand() % 3;
    int npc_delay = 0;



    while (true)
    {
        system("cls");

        cout << "PLAYER: " << player_score << "   NPC: " << npc_score << endl;
        cout << "W/S to move   Q to quit" << endl << endl;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                // player
                if (x == 1 && (y == player_y || y == player_y - 1 || y == player_y + 1)) {
                    cout << "|";
                }

                // npc
                else if (x == width - 2 && (y == npc_y || y == npc_y - 1 || y == npc_y + 1)) {
                    cout << "|";
                }

                // ball
                else if (x == ball_x && y == ball_y) {
                    cout << "O";
                }

                else {
                    cout << " ";
                }
            }
            cout << endl;
        }



        // input
        if (_kbhit())
        {
            char input = _getch();

            if (input == 'w' || input == 'W')
                player_y--;
            else if (input == 's' || input == 'S')
                player_y++;
            else if (input == 'q' || input == 'Q')
                return false;
        }

        // makes sure paddle can't go off screen
        if (player_y < 1)
            player_y = 1;
        if (player_y > height - 2)
            player_y = height - 2;

        // npc follows the ball w/ a variable for it to delay & not move
        npc_delay++;

        if (npc_delay >= 4) // bigger number makesi t easier
        {
            if (ball_y < npc_y)
                npc_y--;
            else if (ball_y > npc_y)
                npc_y++;

            npc_delay = 0;
        }


        // move ball
        ball_x += ball_dx;
        ball_y += ball_dy;

        // y axis bounce
        if (ball_y <= 0 || ball_y >= height - 1)
            ball_dy *= -1;

        // player bounce
        if (ball_x == 2 &&
            (ball_y == player_y || ball_y == player_y - 1 || ball_y == player_y + 1))
        {
            ball_dx = 1;
        }

        // npc bounce
        if (ball_x == width - 3 &&
            (ball_y == npc_y || ball_y == npc_y - 1 || ball_y == npc_y + 1))
        {
            ball_dx = -1;
        }

        // scoring
        if (ball_x <= 0)
        {
            npc_score++;
            ball_x = width / 2;
            ball_y = height / 2;
            ball_dx = 1;
        }

        if (ball_x >= width - 1)
        {
            player_score++;
            ball_x = width / 2;
            ball_y = height / 2;
            ball_dx = -1;
        }

        // win condition
        if (player_score == 5)
        {
            system("cls");
            cout << "==============================\n";
            cout << "        YOU WON PONG!\n";
            cout << "      +100 ARCADE POINTS\n";
            cout << "==============================\n";
            cin.get();
            return true;
        }

        if (npc_score == 5)
        {
            system("cls");
            cout << "==============================\n";
            cout << "           GAME OVER!\n";
            cout << "    FEEL FREE TO TRY AGAIN\n";
            cout << "==============================\n";
            cin.get();
            return false;
        }

        Sleep(80);
    }
}
