#include "BattlegroundOfBravery.h"


BattlegroundOfBravery::BattlegroundOfBravery(int noOfPlayers_){
    noOfPlayers = noOfPlayers_;
    battleground.resize(7, vector<int>(7));
    for(int i = 0; i < 7; ++i)
        for(int j = 0; j < 7; ++j)
            battleground[i][j] = rand() % 12;
    free.resize(7, vector<int>(7)); // -1 == enemy, 0 == free, 1 == player
    int points = noOfPlayers * 5;
    int elites = (rand() % ((points / 3)+1));
    points -= 3 * elites;
    int normals = (rand() % ((points / 2)+1));
    points -= 2 * normals;
    int minions = points;
    while(noOfPlayers_){
        int x = rand() % 7, y = rand() % 7;
        if(free[x][y])
            continue;
        --noOfPlayers_;
        players.push_back(new Player(x, y));
        free[x][y] = 1;
    }
    while(elites){
        int x = rand() % 7, y = rand() % 7;
        if(free[x][y])
            continue;
        enemies.push_back(new Elite(x, y));
        free[x][y] = -1;
        --elites;
    }
    while(normals){
        int x = rand() % 7, y = rand() % 7;
        if(free[x][y])
            continue;
        enemies.push_back(new Normal(x, y));
        free[x][y] = -1;
        --normals;
    }
    while(minions){
        int x = rand() % 7, y = rand() % 7;
        if(free[x][y])
            continue;
        enemies.push_back(new Minion(x, y));
        free[x][y] = -1;
        --minions;
    }
}
void BattlegroundOfBravery::displayGround() {
    for(int i = 0; i < 7; ++i){
        for(int j = 0; j < 7; ++j){
            if(free[i][j] == 1)
                cout << "P ";
            else if(free[i][j] == -1)
                cout << "E ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}
void BattlegroundOfBravery::playGame(){
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    bool turn = true;
    while(!players.empty() && !enemies.empty()){
        cout << "Enter any number other than 0 to continue the game\n";
        int n;
        cin >> n;
        if(!n)
            break;
        displayGround();
        cout << endl;
        if(turn){
            int attackOrMove = 1;
            vector<Player *> playerAttack;
            vector<Enemy *> enemyAttack;
            for(int i = 0; i < (int)players.size(); ++i)
                for(int j = 0; j < (int)enemies.size(); ++j)
                    if(players[i]->distance(enemies[j]->getLocation()[0], enemies[j]->getLocation()[1]) <= players[i]->getWeaponRange())
                        playerAttack.push_back(players[i]), enemyAttack.push_back(enemies[j]);
            if(!playerAttack.empty()){
                cout << "Enter 1 to move or any other number to attack\n";
                cin >> attackOrMove;
            }
            if(attackOrMove == 1){
                vector<Player *> mv;
                vector<int> x, y;
                for(int i = 0; i < (int)players.size(); ++i){
                    int currX = players[i]->getLocation()[0], currY = players[i]->getLocation()[1];
                    for(int l = currX-1; l >= 0 && players[i]->distance(l, currY) <= players[i]->getMovement(); --l)
                        mv.push_back(players[i]), x.push_back(l), y.push_back(currY);
                    for(int l = currX+1; l < 7 && players[i]->distance(l, currY) <= players[i]->getMovement(); ++l)
                        mv.push_back(players[i]), x.push_back(l), y.push_back(currY);

                    for(int l = currY-1; l >= 0 && players[i]->distance(currX, l) <= players[i]->getMovement(); --l)
                        mv.push_back(players[i]), x.push_back(currX), y.push_back(l);
                    for(int l = currY+1; l < 7 && players[i]->distance(currX, l) <= players[i]->getMovement(); ++l)
                        mv.push_back(players[i]), x.push_back(currX), y.push_back(l);
                }
                int idx = 0;
                for(int i = 0; i < (int)mv.size(); ++i){
                    cout << i << ": player at (" << mv[i]->getLocation()[0] << ", " << mv[i]->getLocation()[1];
                    cout << ") can move at (" << x[i] << ", " << y[i] << ")\n";
                }
                cout << "Enter the index of the move\n";
                cin >> idx;
                idx = min(max(0,idx), (int)mv.size()-1);
                free[mv[idx]->getLocation()[0]][mv[idx]->getLocation()[1]] = 0;
                mv[idx]->changeLocation(x[idx], y[idx]);
                free[x[idx]][y[idx]] = 1;
                int r = x[idx], c = y[idx];
                switch(battleground[r][c]){
                    case 1:
                        mv[idx]->changeHP(-5);
                        break;
                    case 2:
                        mv[idx]->increaseDamageModifier();
                        break;
                    case 3:
                        mv[idx]->increaseWeaponRange();
                        break;
                    case 4:
                        mv[idx]->increaseWeaponHitChance();
                        break;
                    case 5:
                        mv[idx]->increaseMovement();
                        break;
                    case 6:
                        mv[idx]->changeWeapon();
                        break;
                    case 7:
                        mv[idx]->decreaseDamageModifier();
                        break;
                    case 8:
                        mv[idx]->decreaseWeaponRange();
                        break;
                    case 10:
                        mv[idx]->decreaseMovement();
                        break;
                }
            }
            else{
                int idx = 0;
                for(int i = 0; i < (int)playerAttack.size(); ++i){
                    cout << i << ": Player at (" << playerAttack[i]->getLocation()[0] << ", " << playerAttack[i]->getLocation()[1];
                    cout << ") enemy at (" << enemyAttack[i]->getLocation()[0] << ", " << enemyAttack[i]->getLocation()[1] << ")"<< endl;
                }
                cout << endl << "Enter index of the attack \n" << endl;
                cin >> idx;
                idx = min(max(0,idx), (int)playerAttack.size()-1);
                enemyAttack[idx]->changeHP(playerAttack[idx]->attack());
                if(enemyAttack[idx]->isDead()){
                    free[enemyAttack[idx]->getLocation()[0]][enemyAttack[idx]->getLocation()[1]] = 0;
                    enemies.erase(find(enemies.begin(), enemies.end(), enemyAttack[idx]));
                }
            }
        }
        else{
            cout << "Enemy's turn\n";
            int mini = 1<<28;
            Player *p = nullptr;
            Enemy *e = nullptr;
            for(int i = 0; i < (int)enemies.size(); ++i)
                for(int j = 0; j < (int)players.size(); ++j){
                    int curr = enemies[i]->distance(players[j]->getLocation()[0], players[j]->getLocation()[1]);
                    if(curr < mini)
                        mini = curr, p = players[j], e = enemies[i];
                }
            if(mini == 1){
                p->changeHP(e->damage());
                if(p->isDead())
                    free[p->getLocation()[0]][p->getLocation()[1]] = 0, players.erase(find(players.begin(), players.end(), p));
            }
            else{
                mini = 1<<28;
                int idx = 0;
                for(int i = 0; i < 4; ++i){
                    int r = e->getLocation()[0]+dx[i], c = e->getLocation()[1]+dy[i];
                    if(r >= 0 && r < 7 && c >= 0 && c < 7 && p->distance(r, c) < mini && !free[r][c])
                        mini = p->distance(r, c), idx = i;
                }
                free[e->getLocation()[0]][e->getLocation()[1]] = 0;
                e->changeLocation(e->getLocation()[0]+dx[idx], e->getLocation()[1]+dy[idx]);
                free[e->getLocation()[0]][e->getLocation()[1]] = 1;
            }
        }
        turn = !turn;
    }
}
BattlegroundOfBravery::~BattlegroundOfBravery() {
    for(int i = 0; i < (int)players.size(); ++i)
        if(players[i])
            delete players[i];
    for(int i = 0; i < (int)enemies.size(); ++i)
        if(enemies[i])
            delete enemies[i];
}