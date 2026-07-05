#include <iostream>
#include <limits>
#include "Card.h"
#include "player.h"
using namespace std;

enum class handRank {
    highHand , 
    onePair , 
    twoPairs , 
    threeOfKind , 
    straight , 
    flush , 
    fullHouse , 
    fourOfKind , 
    straightFlush , 
    royalFlush
};


class anaEngine{
    private :
        Card inHands[2];
        Card inCommunity[5];
        handRank hierarchy;
    public :
        handRank rank(); // Tells which rank of hand does user have. 
        int isPair(Card *, int nextCard); // check the cards of one pair
        bool is2pairs(Card inHand[] , Card community[] , int nextCard); // check the cards of two pairs
        bool is3ofKind(Card inHand[] , Card community[] , int nextCard); // check that whether a player has three of a kind or not.
        bool isStraight();
        bool isFlush(Card inHand[] , Card community[] , int nextCard);
        bool is_fullHouse();
        bool is4ofKind(Card inHand[] , Card community[] , int nextCard);
        bool is_straightFlush();
        bool is_royalFlush();
        anaEngine(){}
};

bool Card::operator == (const int &b){
    if (this->number == b) return true;
    return false;
}

bool Card::operator == (const string &b){
    return this-> suite == b;

    return false;
}

bool Card::operator > (const int &x){
    if (this->number >= x) return true;

    return false;
}

int occurence(Card community[], int targetNumber, int nextCard) {
    int occur = 0; 
    int max = 0 ;
    for (int i = 0; i < nextCard; i++) {
        if (community[i].getNumber() == targetNumber) occur++;
    }
    return occur;
}


int occurence(Card community[], string targetSuite, int nextCard) {
    int occur = 1; 
    for (int i = 0; i < nextCard; i++) {
        if (community[i].getSuite() == targetSuite) occur++;
    }
    return occur;
}
int occurence (Card hole[] , int nextCard , int targets){
    int freq = 0;
    for (int i = 0 ; i < nextCard ; i++){
        int a = hole[i].getNumber();
        freq = occurence(hole , a , nextCard);
        if(freq == targets) break;
    }
    return freq;
}



int anaEngine::isPair(Card hole[] , int nextCard){
    int a = occurence(hole , nextCard , 2);
    if(a == 2) return true; 
 return false;
}

bool anaEngine::is2pairs(Card inHand[] , Card community[] , int nextCard){
    bool pairs = false;
    bool pair1 = false;
    bool pair2 = false;
    int a = 0, b = 0;
    for (int i = 0 ; i < 2 ; i++){
        a = occurence(community , inHand[i].getNumber() , nextCard);
        if (i ==0 && a == 2) pair1 = true;
        if (i == 1 && a == 2 ) pair2 = true;
        a= 0;
    }
    if (pair1 && pair2) pairs = true;
    return pairs;
}

bool anaEngine::is3ofKind(Card inHand[] , Card community[] , int nextCard){
    int a = 0, b = 0;
    if (inHand[0].getNumber() == inHand[1].getNumber()){
        for (int i = 0 ; i < nextCard ; i++){
            if (inHand[0].getNumber() == community[i].getNumber()) return true;
        }
    }
    else {
        a = occurence(community , inHand[0].getNumber() , nextCard);
        b= occurence(community , inHand[1].getNumber() , nextCard);
        if (a == 3 || b == 3) return true;
    }
    
    return false;
}

bool anaEngine::is4ofKind(Card inHand[] , Card community[] , int nextCard){
    int a = 0, b = 0;
    if (inHand[0].getNumber() == inHand[1].getNumber()){
        if(occurence(community , inHand[0].getNumber() , nextCard) + 1 == 4)return true;
    }
    else {
        a = occurence(community , inHand[0].getNumber() , nextCard);
        b= occurence(community , inHand[1].getNumber() , nextCard);
        if (a == 4 || b == 4) return true;
    }
    
    return false;
}

bool anaEngine::isFlush(Card inHand[] , Card community[] , int nextCard){
    int a = 0, b = 0;
    if (inHand[0].getSuite() == inHand[1].getSuite()){
        if(occurence(community , inHand[0].getSuite() , nextCard) + 1 >= 5)return true;
    }
    else {
        a = occurence(community , inHand[0].getSuite() , nextCard);
        b= occurence(community , inHand[1].getSuite() , nextCard);
        if (a >= 5 || b >= 5) return true;
    }
    return false;
}