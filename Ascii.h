#ifndef ASCII_H
#define ASCII_H

// intro
void showTitleScreen();
void showPrizeScreen();
void showMessageScreen(int time_limit);

// menu
int chooseDifficulty();
int showArcadeMenu(int points, int time_remaining);

#endif
