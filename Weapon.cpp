#include "Weapon.h"




int Weapon::rollDice() const{
    srand(time(nullptr));
    return rand() % damageDice + 1;
}
int Weapon::damage(){
    if((rand() % 100 + 1) > hitChance)
        return -1;
    return rollDice();
}
void Weapon::increaseRange() {
    ++range;
    if(range > 12)
        range = 12;
}
void Weapon::increaseHitChance() {
    hitChance += 5;
    if(hitChance > 100)
        hitChance = 100;
}
void Weapon::decreaseRange() {
    --range;
    if(range < 0)
        range = 0;
}
void Weapon::decreaseHitChance() {
    hitChance -= 5;
    if(hitChance < 0)
        hitChance = 0;
}
int Weapon::getRange() const{
    return range;
}
