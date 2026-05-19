#ifndef Dealer_H
#define Dealer_H
#pragma once 

#include <iostream>
#include "Card.h"
#include "player.h"

class Dealer{
    private : 
        Card deck[52];
        int topCard;
    public : 
        void shuffle();
        void swap(Card *ptr , Card *ptr1);
        void createCards();
        Card deal();
		void output(int size);
        Dealer(){
            Dealer::createCards();
            topCard = 0;
        }
        ~Dealer(){}
};

#endif