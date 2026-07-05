#ifndef TEXASTABLE_H
#define TEXASTABLE_H


#pragma once
#include <iostream>
#include "Dealer.h"
#include "player.h"
#include "Card.h"

class texasTable{
    private:
        int players;
        int cards = 2;
        Player array[4];
        Dealer dealer;
        Card community[5];
        static int communityCards;
    public:
        void addPlayers();
        void startGame();
        void dealCards();
        void dealFlop();
        void dealTurn();
        void dealRiver();
        void showdown();
        static int get_communityStatus();
        

        texasTable(){
            std::cout << "How many real players are there : ";
            std::cin >> players;
            std::cin.ignore();
            addPlayers();
        }
};
#endif