#include "Player.h"


Player::Player(int x_, int y_) : Token(){
    int curr = (rand() % 5 + 1);
    if(curr == 1)
        weapon = new Sword();
    else if(curr == 2)
        weapon = new Crossbow();
    else if(curr == 3)
        weapon = new Spear();
    else if(curr == 4)
        weapon = new Axe();
    else
        weapon = new Javelin();
    damageModifier = (rand() % 11);
    hp = 100;
    movement = 1;
    x = x_, y = y_;
}
int Player::attack() const{
    return weapon->damage() + damageModifier;
}
void Player::increaseWeaponRange() {
    weapon->increaseRange();
}
void Player::increaseWeaponHitChance() {
    weapon->increaseHitChance();
}
void Player::decreaseWeaponRange() {
    weapon->decreaseRange();
}
void Player::decreaseWeaponHitChance() {
    weapon->decreaseHitChance();
}
void Player::changeWeapon(){
    delete weapon;
    weapon = nullptr;
    int curr = (rand() % 5 + 1);
    if(curr == 1)
        weapon = new Sword();
    else if(curr == 2)
        weapon = new Crossbow();
    else if(curr == 3)
        weapon = new Spear();
    else if(curr == 4)
        weapon = new Axe();
    else
        weapon = new Javelin();
}
int Player::getWeaponRange() const{
    return weapon->getRange();
}

Player::~Player(){
    if(weapon)
        delete weapon;
}
