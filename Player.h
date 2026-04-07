#pragma once
#include<iostream>
#include"Sword.h" // 1
#include"Crossbow.h" // 2
#include"Spear.h" // 3
#include"Axe.h" // 4
#include"Javelin.h" // 5
#include"Token.h"
using namespace std;

class Player : public Token{
private:
    Weapon *weapon;
public:
    Player(int x_, int y_);
    ~Player();
    int attack() const;
    void increaseWeaponRange();
    void increaseWeaponHitChance();
    void decreaseWeaponRange();
    void decreaseWeaponHitChance();
    void changeWeapon();
    int getWeaponRange() const;
};
