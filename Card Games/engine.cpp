#include <iostream>
#include <limits>
#include "Card.h"
#include "player.h"
#include "Dealer.h"
#include "Table.h"
using namespace std;

class bettingEngine{
    private :
        texasTable table;
        int pot;
        int highestBet;
    public :
        void startGame();
        void meetBet();
        void raiseBet();
        void fold();
        void call();
        void startBetting();

        bettingEngine(){
            startGame();
        }
};


void bettingEngine::startGame(){
    this-> table = texasTable();
    table.startGame();
}


