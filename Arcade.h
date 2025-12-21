#pragma once
#ifndef ARCADE_H
#define ARCADE_H

class Arcade
{
private:
    int points;
    int time_remaining;
    bool game_completed[5];

public:
    Arcade();
    void run();
};

#endif
