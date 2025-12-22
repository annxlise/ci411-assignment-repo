#include <iostream>
#include "ascii.h"

using namespace std;

// start screen
void showTitleScreen()
{
    cout << "==============================================================================\n";
    cout << "||                                                                          ||\n";
    cout << "||    _______     _______     _______     _______     _______               ||\n";
    cout << "||   |       |   |       |   |       |   |       |   |       |              ||\n";
    cout << "||   |  ___  |   |  ___  |   |  ___  |   |  ___  |   |  ___  |              ||\n";
    cout << "||   | |   | |   | |   | |   | |   | |   | |   | |   | |   | |              ||\n";
    cout << "||   | |___| |   | |___| |   | |___| |   | |___| |   | |___| |              ||\n";
    cout << "||   |_______|   |_______|   |_______|   |_______|   |_______|              ||\n";
    cout << "||                                                                          ||\n";
    cout << "||                        RETRO CONSOLE ARCADE                              ||\n";
    cout << "||                                                                          ||\n";
    cout << "||                    INSERT COIN AND PRESS ENTER                           ||\n";
    cout << "||                                                                          ||\n";
    cout << "==============================================================================\n";
    cin.get(); // NOTE: .get means it waits for enter key :D
}

// prize counter
void showPrizeScreen()
{
    cout << "+----------------------------------------------------------------------------+\n";
    cout << "|                            !! PRIZE COUNTER !!                             |\n";
    cout << "|                                                                            |\n";
    cout << "|                               RABBIT PLUSH                                 |\n";
    cout << "|                                                                            |\n";
    cout << "|                                 (\\   /)                                    |\n";
    cout << "|                                 ( o o )                                    |\n";
    cout << "|                                c(  _  )_                                   |\n";
    cout << "|                                                                            |\n";
    cout << "|                             COST: 500 POINTS                               |\n";
    cout << "|                                                                            |\n";
    cout << "+----------------------------------------------------------------------------+\n";
    cin.get();
}

// text message
void showMessageScreen(int time_limit)
{
    cout << "------------------------------------------------------------------------------\n";
    cout << "INCOMING MESSAGE FROM MUM...\n\n";
    cout << "\"HEY!\n";
    cout << "I'M GIVING YOU " << time_limit << " MINUTES.\n";
    cout << "GET YOUR PRIZE AND COME HOME STRAIGHT AFTER!\n";
    cout << "DON'T PUSH YOUR LUCK.\"\n\n";
    cout << "NOT MUCH TIME LEFT...\n";
    cout << "------------------------------------------------------------------------------\n";
    cin.get();
}


// overall game difficulty
int chooseDifficulty()
{
    int choice;

    cout << "------------------------------------------------------------------------------\n";
    cout << "SELECT DIFFICULTY\n\n";
    cout << "1. EASY    - PLENTY OF TIME\n";
    cout << "2. NORMAL  - SOME PRESSURE\n";
    cout << "3. HARD    - VERY LITTLE TIME\n\n";
    cout << "ENTER CHOICE: \n";
    cout << "------------------------------------------------------------------------------\n";

    cin >> choice;
    cin.ignore();

    return choice;
}


// game menu
int showArcadeMenu(int points, int time_remaining)
{
    int choice;

    cout << "+----------------------------------------------------------------------------+\n";
    cout << "|                                                                            |\n";
    cout << "|  1. SPACE INVADERS                                                         |\n";
    cout << "|  2. PONG                                                                   |\n";
    cout << "|  3. MINESWEEPER                                                            |\n";
    cout << "|  4. SNAKE                                                                  |\n";
    cout << "|  5. BREAKOUT                                                               |\n";
    cout << "|                                                                            |\n";
    cout << "|  POINTS: " << points << " / 500                                                         |\n";
    cout << "|  TIME LEFT: " << time_remaining << "                                                             |\n";
    cout << "|                                                                            |\n";
    cout << "+----------------------------------------------------------------------------+\n";
    cout << "ENTER GAME CHOICE: ";

    cin >> choice;
    cin.ignore();

    return choice;
}
