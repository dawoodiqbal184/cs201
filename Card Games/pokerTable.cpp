#include "Dealer.h"
#include "Card.h"
#include "player.h"
#include <iostream>
#include <string>

std::string names[4] = {"John" , "Thomas" , "Nick" , "Abraham"};
class texasTable{
    private:
        int players;
        int cards = 2;
    public:
        Dealer summonDealer();
        Player* addPlayers();

        texasTable(){
            summonDealer();
            std::cout << "How many real players are there : ";
            std::cin >> players;
            addPlayers();
        }
};

int main(){
    texasTable table;
    Dealer tableDealer = table.summonDealer();
    Player* array = table.addPlayers();
    tableDealer.shuffle();
    for (int j = 0 ; j < 2 ; j++){
        for (int i = 1 ; i <= 4 ; i++){
            array[i%4].receiveCards(tableDealer.deal());
        }
    }
    for (int j = 0 ; j < 2 ; j++){
        for (int i = 1 ; i <= 4 ; i++){
            array[i%4].showCards();
        }
    }
    

}

Dealer texasTable::summonDealer(){
    Dealer pokerDealer;
    return pokerDealer;
}

Player* texasTable::addPlayers(){
    Player* ptr;
    if (players > 0){
        if (players < 4){
            ptr = new Player[4];
            for (int i = 0 ; i < players ; i++){
                std::string name;
                std::cin.ignore();
                std::cout << "Enter the name of player # "<<i<<" : ";
                getline(std::cin , name);
                ptr[i] = Player(name);
            }
            for (int i = players ; i < 4 ; i++){
                std::string name;
                name = names[rand()% 4 + 1];
                ptr[i] = Player(name);
            }
        }
        else{
            ptr = new Player [players];
            for (int i = 0 ; i < players ; i++){
                std::string name;
                std::cin.ignore();
                std::cout << "Enter the name of player # "<<i<<" : ";
                getline(std::cin , name);
                ptr[i] = Player(name);
            }
        } 
    }
    else return nullptr;
    return ptr;
}

