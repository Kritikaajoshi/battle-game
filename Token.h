#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<vector>
#include<math.h>
using namespace std;
class Token {
protected:
    int hp;
    int x, y;
    int movement;
    int damageModifier;
public:
    Token();
    void changeHP(int change);
    bool isDead() const;
    void increaseMovement();
    void decreaseMovement();
    void decreaseDamageModifier();
    void increaseDamageModifier();
    void changeLocation(int x_, int y_);
    vector<int> getLocation() const;
    int distance(int x_, int y_) const;
    int getMovement() const;
};