#ifndef Player_H
#define Player_H

#pragma once
#include "Card.h"
#include <iostream>
#include <string>

class Player {
    private :
    Card hand[13];
    bool hasFolded;
    int chips;
    std::string name;
    int nextCard;
    public : 
    void showCards();
    void bet(int amount);
    void meetBet(int amount);
    void raiseBet(int amount);
    void receiveCards(Card incomingCard);
    Player operator - (int bet){
        this->chips -= bet;
        return *this;
    }
    Player(){}
    Player( std::string name  , int chips = 500){
        this->name = name;
        this->chips = chips;
        this->nextCard = 0;
        this->hasFolded = false;
    }
    ~Player(){
        this->name = "";
        this->chips = 0;
    }
};

#endif