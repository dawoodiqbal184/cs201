#include <iostream>
#include "Card.h"
#include "player.h"
using namespace std;

void Player::receiveCards(Card incomingCard){
    hand[nextCard] = incomingCard;
    nextCard++;
}

void Player::showCards(){
    cout << name<<"'s Hand : ";
    for (int i = 0 ; i < nextCard ; i++){
        cout << hand[i]<<" ";
    }
    cout <<endl<<"Chips : "<<chips<<endl;
}