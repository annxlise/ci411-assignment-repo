#include <iostream>
#include "Pong.h"

using namespace std;

bool Pong::play()
{
    cout << "\n--- PONG ---\n";
    cout << "You hit the ball back and forth...\n";
    cout << "You win!\n";
    cin.get();

    return true;
}
