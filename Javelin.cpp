#include "Javelin.h"

Javelin::Javelin() {
    range = 3;
    hitChance = 60;
    damageDice = (rand() % 10 + 1) * 2;
}