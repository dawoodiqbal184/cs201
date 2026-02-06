//------A C++ Program that will play ludo from all four sides and tell winner and looser------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
using namespace std;
int peice(int color1, int color2, int color3, int color4){
    int turn = 1;
    

}
int play(int current_position , bool* start , string player , bool* Player){
    if (current_position < 56){ // already won check
        int num = rand()% 6 + 1;
        if (num == 6)  *start = true; // feature added start after 1st six
        else if (*start == false){ // feature added if not six before start show number
            cout << "Dice rolled by "<< num <<" so "<<player<< " is unable to move!"<< endl;
        }
        if (*start == true && num == 6){ // feature added for 2  and 3 sixes
            int num1 = rand()% 6 + 1;
            if (current_position + num1 + 6 <= 56){
                if (num1 == 6 ){
                    int num2 = rand()% 6 + 1;
                    if (num2 == 6){
                        if (current_position < 0 ){
                            *start = false;
                            cout << "Over goodluck is bad also, You got three sixes so count to zero\nAnd "<<player << " is at home still\n";
                        } 
                        else{
                            cout << "Over goodluck is bad also, You got three sixes so count to zero\n";
                            cout <<player<<" : "<< current_position <<endl;
                        }
                    }
                    else if (num2 != 6){
                        current_position += num2;
                        current_position += 12;
                        cout << "Dice rolled "<< player << " moved by 6 then 6 again and then by "<< num2 << endl;
                        cout <<player<<" : "<< current_position <<endl;
                    }
                }
                else if (num1 != 6){
                    current_position += num1;
                    current_position += 6;
                    cout << "Dice rolled "<< player << " moved by 6 and then "<< num1 << endl;
                    cout <<player<<" : "<< current_position <<endl;
                }
            }
            else cout << player << " : "<<current_position<<endl;
            if (current_position == 56) *Player = true; 
        }
        else if (*start == true){ // normal play part
            if (current_position + num <= 56){
                current_position += num;
                cout << "Dice rolled "<< player << " moved by "<< num << endl;
                cout <<player<<" : "<< current_position <<endl;
            }
            else cout << player << " : "<<current_position<<endl;
            if (current_position == 56) *Player = true;
        }
    }
    else if (*Player) cout << player << " already won!\n";
    return current_position;
}
void winner(string Player ,string Player2 , string Player3 , string Player4 , bool *player1 ,bool *player2 , bool *player3, bool *player4){
    if (*player1 && !*player2 && !*player3 && !*player4){
        for(int i = 0 ; i < 30 ; i++) cout << "*";
        cout << endl;
        cout << Player << " is 1st\n";
        for(int i = 0 ; i < 30 ; i++) cout << "*";
        cout << endl;
    } 
    else if (!*player1 && *player2 && !*player3 && !*player4){
        for(int i = 0 ; i < 30 ; i++) cout << "*";
        cout << endl;
        cout << Player2 << " is 1st\n";
        for(int i = 0 ; i < 30 ; i++) cout << "*";
        cout << endl;
    } 
    else if (!*player1 && !*player2 && *player3 && !*player4){
        for(int i = 0 ; i < 30 ; i++) cout << "*";
        cout << endl;
        cout << Player3 << " is 1st\n";
        for(int i = 0 ; i < 30 ; i++) cout << "*";
        cout << endl;
    } 
    else if (!*player1 && !*player2 && !*player3 && *player4){
        for(int i = 0 ; i < 30 ; i++) cout << "*";
        
        cout << endl;
        cout << Player4 << " is 1st\n";
        for(int i = 0 ; i < 30 ; i++) cout << "*";
        cout << endl;
    } 
}
void looser(string Player, bool *player1, bool *player2, bool* player3, bool *player4){
    if (*player1 && *player2 , *player3 , !player4){
        for(int i = 0 ; i < 30 ; i++) cout << "*";

        cout << endl;
        cout << Player << " is looser\n";
        for(int i = 0 ; i < 30 ; i++) cout << "*";
        cout << endl;
        
    }
}
int main(){
    srand(time(0));
    string Red = "Red" , Green = "Green" , Yellow = "Yellow" , Blue = "Blue";
    int turn = 1;
    int red = -6, yellow = -6, blue = -6, green = -6;
    bool winnerRed = false , winnerGreen = false , winnerBlue = false , winnerYellow = false;
    bool startGreen = false , startRed = false , startYellow = false , startBlue = false;
    while ( red < 56 || green < 56 || blue < 56 || yellow < 56){
        cout << "Turn Number : "<< turn<<endl<<endl;
        red = play(red, &startRed , Red , &winnerRed);
        cout <<endl;
        green = play(green, &startGreen , Green , &winnerGreen);
        cout <<endl;
        yellow = play(yellow , &startYellow , Yellow , &winnerYellow);
        cout <<endl;
        blue = play(blue , &startBlue , Blue , &winnerBlue);
        cout <<endl;
        winner(Red ,Green , Blue , Yellow ,  &winnerRed , &winnerGreen , &winnerBlue , &winnerYellow);
        turn++;
        cout << "----------------------------------------\n";
        cout << "Press enter to continue\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }
return 0;
}