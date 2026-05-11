// spades = \u2660
// clubs = \u2663
// hearts = \u2665
// diamonds = \u2666
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

struct card{
    string suite ;
    int number;
};
void createCards(card deck[]);
void shuffle(card deck[]);
void swap(card *ptr , card *ptr1);
void output(card array[] , int size);
void deal(card p1, card p2 , card p3 , card p4);



ostream& operator<<(ostream& os , const card x){
    os << x.suite<<x.number<<" ";
    return os;
}
int main(){
    srand(time(0));
    card deck[52];
    createCards(deck);
    output(deck , 52);
    cout << endl<<endl;
    shuffle(deck);
    output(deck , 52);
}

void createCards(card deck[]){
    int counter = 2;
    for (int i = 0 ; i < 52 ; i++){
        if (i >= 0 && i <= 12) deck[i].suite = "\u2660";
        else if (i >= 13 && i <= 25) deck[i].suite = "\u2663";
        else if (i >= 26 && i <= 38 ) deck[i].suite = "\u2665";
        else deck[i].suite = "\u2666";
        deck[i].number = counter++;
        if (counter > 14 ) counter = 2;
    }
}

void shuffle(card deck[]){
    int counter = 0;
    for (int i = 51 ; i >= 0 ; i--){
        int x = rand()% (i + 1);
        swap(&deck[i] , &deck[x]);
    }
}

void swap(card *ptr , card *ptr1){
    card temp = *ptr;
    *ptr = *ptr1;
    *ptr1 = temp;
}

void output(card array[] , int size){
    int counter = 0;
    for (int i = 1 ; i <= 4 ; i++) {
        int end = 13;
        for ( ; counter < end*i; counter++)
        {
            cout << array[counter];
        }
        cout <<endl;
        counter = end*i;
    }
}

void deal(card p1, card p2 , card p3 , card p4){
    for (int i = 0 ; i < 52 ; i++){
        
    }
}
