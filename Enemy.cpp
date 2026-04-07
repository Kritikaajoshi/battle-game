#include "Enemy.h"


Enemy::Enemy(int x_, int y_){
    hp = 0, x = x_, y = y_, movement = 0, damageModifier = 0;
}
int Enemy::damage() const {
    return damageModifier;
}
