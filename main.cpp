#include<iostream>
#include"BattlegroundOfBravery.h"
#include <cstdlib>
#include <ctime>
#include<fstream>
#include<string>
using namespace std;





int main() {
    srand(time(nullptr));
    int choice = -1;
    cout << "Enter 0 to initialize the game randomly or any other number to read from file\n";
    cin >> choice;
    int no = rand() % 7 + 1;
    if(choice){
        cout << "Enter the name of the file\n";
        string s;
        cin >> s;
        std::ifstream file(s);
        // Check if the file is opened successfully
        if (!file) {
            std::cerr << "Error: Unable to open file." << std::endl;
            return 1; // Exit with error
        }
        int number;
        // Read an integer from the file
        if(!(file >> no)){
            std::cerr << "Error: Unable to read an integer from the file." << std::endl;
            return 1; // Exit with error
        }
    }
    no = min(max(1, no), 7);
    BattlegroundOfBravery game(no);
    cout << "***E stands for enemy and P stands for Player\n***";
    game.playGame();
    return 0;
}
