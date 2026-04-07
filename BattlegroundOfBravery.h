#pragma once
#include"Normal.h"
#include"Minion.h"
#include"Elite.h"
#include"Player.h"
#include<vector>

class BattlegroundOfBravery {
private:
    vector<Player *> players;
    vector<Enemy *> enemies;
    vector<vector<int>> battleground;
    int noOfPlayers;
    vector<vector<int>> free;
public:
    BattlegroundOfBravery(int noOfPlayers_);
    ~BattlegroundOfBravery();
    void playGame();
    void displayGround();
};
