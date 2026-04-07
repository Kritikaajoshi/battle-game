#include "Token.h"


Token::Token(){
    hp = 0, x = 0, y = 0, damageModifier = 0, movement = 0;
}
void Token::changeLocation(int x_, int y_){
    x = x_, y = y_;
}
void Token::changeHP(int change){
    hp -= change;
    if(hp > 100)
        hp = 100;
    else if(hp < 0)
        hp = 0;
}
bool Token::isDead() const{
    return !hp;
}
void Token::increaseMovement(){
    ++movement;
    if(movement > 4)
        movement = 4;
}
void Token::decreaseMovement(){
    --movement;
    if(movement <= 0)
        movement = 1;
}
void Token::decreaseDamageModifier(){
    --damageModifier;
}
void Token::increaseDamageModifier(){

    ++damageModifier;
}
int Token::distance(int x_, int y_) const{
    return abs(x-x_) + abs(y-y_);
}
vector<int> Token::getLocation() const {
    return {x, y};
}
int Token::getMovement() const{
    return movement;
}
