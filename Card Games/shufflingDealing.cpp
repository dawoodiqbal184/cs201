// spades = \u2660
// clubs = \u2663
// hearts = \u2665
// diamonds = \u2666
// need to shift the create logic by passing two pointers starting from one and ending at another one;
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
void create(card deck[]);
void createSpades(card spades[]);
void createClubs(card clubs[]);
void createHearts(card hearts[]);
void createDiamonds(card diamonds[]);
void shuffle(card deck[]);
void swap(card *ptr , card *ptr1);
void output(card array[] , int size);



ostream& operator<<(ostream& os , const card x){
    os << x.suite<<x.number<<" ";
    return os;
}
int main(){
    srand(time(0));
    card deck[52];
    create(deck);
    output(deck , 52);
    cout << endl<<endl;
    shuffle(deck);
    output(deck , 52);
}

void create(card deck[]){// need to update the logic
    card temp[13];
    int counter = 0;
    createSpades(temp);
    for (int i = 0 ; i < 52 ; i++){
        if (counter == 13) counter = 0;
        if (i >= 0 && i <= 12){
            
            deck[i] = temp[i];
        }
        else if (i >= 13 && i <= 25){
            createClubs(temp);
            deck[i] = temp[counter];
            counter++; 
        }
        else if (i >= 26 && i <= 38 ){
            createHearts(temp);
            deck[i] = temp[counter];
            counter++;
        }
        else if (i >= 39 && i < 52 ){
            createDiamonds(temp);
            deck[i] = temp[counter];
            counter++;
        }
    }

}

void createSpades(card spades[]){
    int counter = 2;
    for (int i = 0 ; i < 13 ; i++){
        spades[i].suite = "\u2660";
        spades[i].number = counter++;
    }
}

void createClubs(card clubs[]){
    int counter = 2;
    for (int i = 0 ; i < 13 ; i++){
        clubs[i].suite = "\u2663";
        clubs[i].number = counter++;
    }
}

void createHearts(card hearts[]){
    int counter = 2;
    for (int i = 0 ; i < 13 ; i++){
        hearts[i].suite = "\u2665";
        hearts[i].number = counter++;
    }
}

void createDiamonds(card diamonds[]){
    int counter = 2;
    for (int i = 0 ; i < 13 ; i++){
        diamonds[i].suite = "\u2666";
        diamonds[i].number = counter++;
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
    for (int i = 0 ; i < size ; i++) cout << array[i];
}
