#include <iostream>
#include <ctime>
#include "Card.h"
#include "player.h"
#include "Dealer.h"
using namespace std;

void Dealer::createCards(){
    int counter = 2;
	string s;
    for (int i = 0 ; i < 52 ; i++){
        if (i >= 0 && i <= 12) s = "\u2660";
        else if (i >= 13 && i <= 25) s = "\u2663";
        else if (i >= 26 && i <= 38 ) s = "\u2665";
        else s = "\u2666";
        deck[i] = Card(s , counter);
        counter++;
        if (counter > 14 ) counter = 2;
    }
}

void Dealer::shuffle(){
    srand(time(0));
    int counter = 0;
    for (int i = 51 ; i >= 0 ; i--){
        int x = rand()% (i + 1);
        swap(&deck[i] , &deck[x]);
    }
}

void Dealer::swap(Card *ptr , Card *ptr1){
    Card temp = *ptr;
    *ptr = *ptr1;
    *ptr1 = temp;
}

Card Dealer::deal(){
    Card nextCard = deck[topCard];
    topCard++;
    return nextCard;
}

void Dealer::output(int size){
    for (int i = 0 ; i < size ; i++){
        cout <<deck[i];
    }
}

ostream& operator << (ostream& os , const Card& x){
         if(x.number == 11) os << x.suite << "J ";
    else if(x.number == 12) os << x.suite << "Q ";
    else if(x.number == 13) os << x.suite << "K ";
    else if(x.number == 14) os << x.suite << "A ";
    else os << x.suite <<" "<< x.number <<" ,";
    return os;
}