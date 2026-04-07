#include "Spear.h"

Spear::Spear(){
    range = 2;
    hitChance = 70;
    damageDice = (rand() % 10 + 1) * 2;
}