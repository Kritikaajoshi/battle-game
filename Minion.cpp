#include "Minion.h"


Minion::Minion(int x_, int y_) : Enemy(x_, y_){
    hp = 50, movement = 1, damageModifier = 5;
}