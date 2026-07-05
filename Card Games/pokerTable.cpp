#include "Dealer.h"
#include "Card.h"
#include "player.h"
#include "Table.h"
#include <iostream>
#include <string>
using namespace std;

std::string names[4] = {"John" , "Thomas" , "Nick" , "Abraham"};
int texasTable::communityCards = 0;

int main(){
    texasTable table;
    table.startGame();
    table.dealCards();
    table.dealFlop();
    table.dealTurn();
    table.dealRiver();
    table.showdown();
    

}

void texasTable::addPlayers(){
    if (players > 0){
        if (players < 4){
            for (int i = 0 ; i < players ; i++){
                int chips;
                std::string name;
                std::cout << "Enter the name of player # "<<i+1<<" : ";
                getline(std::cin , name);
                cout << "Enter the amount of chips of player # "<<i+1<<" : ";
                cin >> chips;
                std::cin.ignore();
                array[i] = Player(name , chips);
            }
            for (int i = players ; i < 4 ; i++){
                std::string name;
                name = names[rand()% 4];
                array[i] = Player(name);
            }
        }
        else{
            for (int i = 0 ; i < players ; i++){
                std::string name;
                int chips;
                std::cout << "Enter the name of player # "<<i<<" : ";
                getline(std::cin , name);
                cout << "Enter the amount of chips of player # "<<i<<" : ";
                cin >> chips;
                std::cin.ignore();
                array[i] = Player(name , chips);
            }
        } 
    }
    else {
        cout << "Number of players can't be smaller than zero!\n";
        return;
    }
   
}


void texasTable::startGame(){
    cout << "Dealer is shuffling the cards\n";
    dealer.shuffle();
}


void texasTable::dealCards(){
    cout << "Dealer is dealing cards\n";
    for (int j = 0 ; j < cards ; j++){
        for (int i = 0 ; i < 4 ; i++){
            array[i%4].receiveCards(dealer.deal());
        }
    }
}
        

void texasTable::dealFlop(){
    for (int i = 0 ; i < 3 ; i++){
        community[i] = dealer.deal();
        cout << community[i]<< " ";
    }
    texasTable::communityCards = 3;
}
        

void texasTable::dealTurn(){
    community[3] = dealer.deal();
    cout << community[3]<<" ";
    texasTable::communityCards = 4;
}
        

void texasTable::dealRiver(){
    community[4] = dealer.deal();
    cout << community[4]<<" \n";
    texasTable::communityCards = 5;
}


void texasTable::showdown(){
    for (int i = 0 ; i < 4 ; i++){
        array[i].showCards();
    }
}


int texasTable::get_communityStatus(){
    return communityCards;
}
