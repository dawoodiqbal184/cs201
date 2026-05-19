#include "Dealer.h"
#include "player.h"

int main(){
    Dealer tableDealer;
    Player dawood("Dawood" , 5000);
    Player opponent("Opponent" , 5000);
    tableDealer.shuffle();
    for (int i = 0 ; i < 4 ; i++){
        dawood.receiveCards(tableDealer.deal());
        opponent.receiveCards(tableDealer.deal());
    }
    dawood.showCards();
    opponent.showCards();
    return 0;
}