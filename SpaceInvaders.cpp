#include <iostream>
#include <conio.h>
#include <windows.h>
#include "SpaceInvaders.h"

using namespace std;

SpaceInvaders::SpaceInvaders()
{
}

bool SpaceInvaders::play()
{
    const int width = 30;
    const int height = 15;

    // player
    int player_x = width / 2;

    // enemies
    const int enemy_cols = 5;
    const int enemy_rows = 2;
    int enemy_timer = 0;

    int enemy_x[enemy_rows][enemy_cols] =
    {
        { 5, 9, 13, 17, 21 },
        { 5, 9, 13, 17, 21 }
    };

    int enemy_y[enemy_rows] = { 3, 5 };
    bool enemy_alive[enemy_rows][enemy_cols];

    for (int r = 0; r < enemy_rows; r++)
    {
        for (int c = 0; c < enemy_cols; c++) {
            enemy_alive[r][c] = true;
        }
    }

    int enemy_dx = 1; // direction

    // bullet
    const int max_bullets = 5;

    bool bullet_active[max_bullets];
    int bullet_x[max_bullets];
    int bullet_y[max_bullets];

    for (int i = 0; i < max_bullets; i++)
    {
        bullet_active[i] = false;
    }



    while (true)
    {
        system("cls");

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                bool drawn = false;

                // player
                if (y == height - 1 && x == player_x)
                {
                    cout << "^";
                    drawn = true;
                }

                // enemies
                for (int r = 0; r < enemy_rows; r++)
                {
                    for (int c = 0; c < enemy_cols; c++)
                    {
                        if (enemy_alive[r][c] && x == enemy_x[r][c] && y == enemy_y[r])
                        {
                            cout << "W";
                            drawn = true;
                        }
                    }
                }

                // bullet
                for (int i = 0; i < max_bullets; i++)
                {
                    if (bullet_active[i] && x == bullet_x[i] && y == bullet_y[i])
                    {
                        cout << "|";
                        drawn = true;
                    }
                }


                if (!drawn)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }

        // input
        if (_kbhit())
        {
            char input = _getch();

            if (input == 'a' || input == 'A')
            {
                player_x--;
            }
            else if (input == 'd' || input == 'D')
            {
                player_x++;
            }
            else if (input == ' ')
            {
                for (int i = 0; i < max_bullets; i++)
                {
                    if (!bullet_active[i])
                    {
                        bullet_active[i] = true;
                        bullet_x[i] = player_x;
                        bullet_y[i] = height - 2;
                        break; // only fire one bullet per key press :D
                    }
                }
            }

            else if (input == 'q' || input == 'Q')
            {
                return false;
            }
        }

        // makes sure player cant go offscreen
        if (player_x < 0)
        {
            player_x = 0;
        }
        if (player_x >= width) {
            player_x = width - 1;
        }

        // bullets move
        for (int i = 0; i < max_bullets; i++)
        {
            if (bullet_active[i])
            {
                bullet_y[i]--;

                if (bullet_y[i] < 0)
                {
                    bullet_active[i] = false;
                }
            }
        }


        // bullet collision
        for (int r = 0; r < enemy_rows; r++)
        {
            for (int c = 0; c < enemy_cols; c++)
            {
                for (int i = 0; i < max_bullets; i++)
                {
                    if (enemy_alive[r][c] &&
                        bullet_active[i] &&
                        bullet_x[i] == enemy_x[r][c] &&
                        bullet_y[i] == enemy_y[r])
                    {
                        enemy_alive[r][c] = false;
                        bullet_active[i] = false;
                    }
                }

            }
        }

        // enemy movement
        bool hit_edge = false;

        enemy_timer++;

        if (enemy_timer >= 2) // higher makes it slower and easier
        {
            bool hit_edge = false;

            for (int r = 0; r < enemy_rows; r++)
            {
                for (int c = 0; c < enemy_cols; c++)
                {
                    if (enemy_alive[r][c])
                    {
                        if (enemy_x[r][c] <= 0 || enemy_x[r][c] >= width - 1)
                        {
                            hit_edge = true;
                        }
                    }
                }
            }

            if (hit_edge)
            {
                enemy_dx *= -1;
                for (int r = 0; r < enemy_rows; r++)
                {
                    enemy_y[r]++;
                }
            }

            for (int r = 0; r < enemy_rows; r++)
            {
                for (int c = 0; c < enemy_cols; c++)
                {
                    enemy_x[r][c] += enemy_dx;
                }
            }

            enemy_timer = 0;
        }


        if (hit_edge)
        {
            enemy_dx *= -1;
            for (int r = 0; r < enemy_rows; r++)
            {
                enemy_y[r]++;
            }
        }

        for (int r = 0; r < enemy_rows; r++)
        {
            for (int c = 0; c < enemy_cols; c++)
            {
                enemy_x[r][c] += enemy_dx;
            }
        }

        // enemies reaching pc = game over
        for (int r = 0; r < enemy_rows; r++)
        {
            if (enemy_y[r] >= height - 1)
            {
                system("cls");
                cout << "============================\n";
                cout << "          GAME OVER\n";
                cout << "   FEEL FREE TO TRY AGAIN!\n";
                cout << "============================\n";
                cin.get();
                return false;
            }
        }

        // win condition
        bool all_dead = true;
        for (int r = 0; r < enemy_rows; r++) {
            for (int c = 0; c < enemy_cols; c++) {
                if (enemy_alive[r][c]) {
                    all_dead = false;
                }
            }
        }

        if (all_dead)
        {
            system("cls");
            cout << "============================\n";
            cout << " YOU WON SPACE INVADERS!\n";
            cout << "   +100 ARCADE POINTS\n";
            cout << "============================\n";
            cin.get();
            return true;
        }

        Sleep(130);
    }
}
