#pragma once
#include<iostream>
#include"Token.h"
using namespace std;

class Enemy : public Token{
private:
public:
    Enemy(int x_, int y_);
    int damage() const;
};