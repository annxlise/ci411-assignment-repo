#include <iostream>
#include "Ascii.h"
#include "Arcade.h"
#include <ctime>
#include <cstdlib>

int main()
{
    srand((unsigned int)time(0));

    Arcade arcade;
    arcade.run();
    return 0;
}

