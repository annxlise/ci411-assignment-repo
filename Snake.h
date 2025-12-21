#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "Minigame.h"

class Snake : public Minigame
{
private:
    int x;
    int y;
    bool game_over;

public:
    bool play();
};

#endif
