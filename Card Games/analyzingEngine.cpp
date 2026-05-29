#include <iostream>
#include <limits>
#include "Card.h"
#include "player.h"
#include "Dealer.h"
#include "Table.h"
using namespace std;

enum class hand {
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

enum class bet {
    meet ,
    raise ,
    fold,
};

class anaEngine{
    private :
        Card inHands[2];
        Card inCommunity[5];
        hand rank;
    public :
        void anaHand();  // Tell the basis on which initial bet is done checks the players hand before the flop
        int getProbability(); // Get the probabilities of all hand ranks from below function 
        int pairProb(); // check the probability of one pair
        int pairs2Prob(); // check the probability of two pairs
        int threeKindProb(); // check the probability of three of a kind
        int straightProb(); // check the probability of straight
        int flushProb(); // check the probability of flush
        int fullHouseProb(); // check the probability of a full house 
        int fourOfKindProb(); // check the probability of four of a kind
        int straightFlushProb(); // check the probability of straight flush
        int royalFlushProb(); // check the probability of royal flush
        bet bettingScale();
        

        anaEngine(){}
};

bool Card::operator == (const Card &b){
    if (this->number == b.number) return true;

    return false;
}

int occurence(Card community[] , Card hand , int nextCard){
    int occur = 0;
    for (int i = 0 ; i < nextCard , i++){
        if (hand == community[i])
    }
}
