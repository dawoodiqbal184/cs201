#include <iostream>
#include <limits>
#include "Card.h"
#include "player.h"
using namespace std;




int occurence (int hole[] , int nextCard){
    int freq = 1;
    for (int i = 0 ; i < nextCard ; i++){
        for (int j = i+1 ; j < nextCard ; j++){
            if(hole[i].getNumber() == hole[j].getNumber()) freq+= 1;
        }
    }
    return freq;
}

bool isPair(int hole[] , int nextCard){
    bool b = false;
    int a = occurence(hole , nextCard);
    if(a == 2) return true; 
 return false;
}

int main(){
    int array[7] = {1, 3 , 5 , 6, 1 , 2 , 4 };
    if(isPair(array , 7)) cout << "Good";
}