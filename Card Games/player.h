#pragma once
#include "Card.h"
#include <iostream>
#include <string>

class Player {
    private :
    Card hand[13];
    int chips;
    std::string name;
    int nextCard;
    public : 
    void showCards();
    void bet(int amount);
    void meetBet(int amount);
    void raiseBet(int amount);
    void receiveCards(Card incomingCard);
    Player(){}
    Player( std::string name  , int chips){
        this->name = name;
        this->chips = chips;
        this->nextCard = 0;
    }
    ~Player(){
        this->name = "";
        this->chips = 0;
    }
};