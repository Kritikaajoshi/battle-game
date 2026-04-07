#include "Sword.h"


Sword::Sword() {
    range = 1;
    hitChance = 90;
    damageDice = (rand() % 10 + 1) * 2;
}