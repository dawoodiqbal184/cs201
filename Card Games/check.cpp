// spades = \u2660
// clubs = \u2663
// hearts = \u2665
// diamonds = \u2666
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct card{
    string suite ;
    int number;
};
void createCards(card deck[]);
void shuffle(card deck[]);
void swap(card *ptr , card *ptr1);
void outputDeck(card array[] , int size);
void deal(card deck[] , card p1[] , card p2[] , card p3[] , card p4[]);
void output(card array[], int size);
void distribute(card p1[],card p2[] , card p3[] , card p4[]);



ostream& operator<<(ostream& os , const card x){
    os << x.suite<<x.number<<" ";
    return os;
}
int main(){
    srand(time(0));
    card deck[52] , p1[13] , p2[13], p3[13] , p4[13];
    createCards(deck);
    outputDeck(deck , 52);
    cout << endl<<endl;
    shuffle(deck);
    outputDeck(deck , 52);
    cout << endl<<endl;
    deal(deck , p1 , p2 , p3 , p4);
    distribute(p1,p2,p3,p4);
    
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

void outputDeck(card array[] , int size){
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

void deal(card deck[] , card p1 , card p2 , card p3 , card p4){
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

void deal(card deck[] , card p1[] , card p2[] , card p3[] , card p4[]){
    int counter = 0;
   for (int i = 0 ; i < 13 ; i++){
        p1[i] = deck[counter++];
        p2[i] = deck[counter++];
        p3[i] = deck[counter++];
        p4[i] = deck[counter++];
   }

}

void output(card array[], int size){
    for (int i = 0 ; i < size ; i++){
        cout <<array[i];
    }
}

void distribute(card p1[],card p2[] , card p3[] , card p4[]){
    output(p1 , 13);
    cout << endl<<endl;
    output(p2 , 13);
    cout << endl<<endl;
    output(p3,13);
    cout << endl<<endl;
    output(p4, 13);
}