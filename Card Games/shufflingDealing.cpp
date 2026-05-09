// spades = \u2660
// clubs = \u2663
// hearts = \u2665
// diamonds = \u2666
#include <iostream>
#include <string>
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

ostream& operator<<(ostream& os , const card x){
    os << x.suite<<x.number<<" ,";
    return os;
}
int main(){
    card deck[52];
    create(deck);
    for (int i = 0 ; i < 52 ; i++){
        cout << deck[i];
        if(i != 0 && i % 12 == 0) cout<<endl;
    }
}

void create(card deck[]){
    card temp[13];
    int counter = 0;
    for (int i = 0 ; i < 52 ; i++){
        if (counter == 13) counter = 0;
        if (i >= 0 && i <= 12){
            createSpades(temp);
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
