#include <iostream>
#include <limits>
#include "Card.h"
#include "player.h"
using namespace std;

enum class bet {
    meet ,
    raise ,
    fold,
};

enum class hand {
    strong,
    weak,
    medium,
};


class playerBrain{
    public :
        hand analyseHand(Card array[]);  // Tell the basis on which initial bet is done checks the players hand before the flop
        bet bettingScale();
        int royalFlushProb(); // check the probability of royal flush
        int straightFlushProb(); // check the probability of straight flush
        int fourOfKindProb(); // check the probability of four of a kind
        int flushProb(); // check the probability of flush
        int fullHouseProb(); // check the probability of a full house 
        int straightProb(); // check the probability of straight
        int threeKindProb(); // check the probability of three of a kind
};



hand anaEngine::analyseHand(Card array[]){
    if (array[0] == array[1].getNumber() && array[0] > 5) return hand::strong;
    if (array[0] == array[1].getSuite()) return hand::medium;
    return hand::weak;
}