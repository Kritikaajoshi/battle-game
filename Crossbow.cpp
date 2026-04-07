#include "Crossbow.h"

Crossbow::Crossbow(){
    range = 4;
    hitChance = 60;
    damageDice = (rand() % 10 + 1) * 2;
}