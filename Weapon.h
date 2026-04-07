#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<vector>
#include<math.h>
using namespace std;

class Weapon {
protected:
    int damageDice = 0, hitChance = 0, range = 0;
    int rollDice() const;
public:
    void increaseRange();
    void increaseHitChance();
    void decreaseRange();
    void decreaseHitChance();
    int damage();
    int getRange() const;
};


