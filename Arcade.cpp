#include <iostream>
#include <cstdlib>
#include "Arcade.h"
#include "ascii.h"
#include "Pong.h"
#include "Snake.h"
#include "Minesweeper.h"
#include "SpaceInvaders.h"
#include "Breakout.h"




using namespace std;



Arcade::Arcade()
{
    points = 0;
    time_remaining = 0;

    for (int i = 0; i < 5; i++)
    {
        game_completed[i] = false;
    }
}

void Arcade::run()
{
    system("cls");
    showTitleScreen();
    showPrizeScreen();

    int difficulty = chooseDifficulty();

    if (difficulty == 1)
        time_remaining = 60;
    else if (difficulty == 2)
        time_remaining = 30;
    else
        time_remaining = 15;

    system("cls");
    showMessageScreen(time_remaining);

    while (points < 500 && time_remaining > 0)
    {
        int choice = showArcadeMenu(points, time_remaining);

        Minigame* game = nullptr;

        if (choice == 1)
            game = new SpaceInvaders();
        else if (choice == 2)
            game = new Pong();
        else if (choice == 3)
            game = new Minesweeper();
        else if (choice == 4)
            game = new Snake();
        else if (choice == 5)
            game = new Breakout();

        if (game != nullptr)
        {
            system("cls");          
            bool won = game->play(); 
            system("cls");           

            if (won)
            {
                points += 100;
                game_completed[choice - 1] = true;
            }

            time_remaining -= 30;
            delete game;
        }

    }

    if (points >= 500)
        cout << "\nYOU WON THE RABBIT PLUSH!\n";
    else
        cout << "\nTIME'S UP! YOU GO HOME EMPTY-HANDED.\n";
    system("cls"); // clears the console !! makes it so that it refreshes instead of having one big thing
}
