#include "Axe.h"


Axe::Axe(){
    range = 1;
    hitChance = 90;
    damageDice = (rand() % 10 + 1) * 2;
}