//------A C++ Program that will play ludo from all four sides and tell winner and looser------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
using namespace std;
int dice(){
    int num = 1 + rand()%6;
    if (num == 6){
        int num1 = 1 + rand()%6;
        if (num1 == 6){
            int num2 = 1 + rand ()%6;
            if (num2 == 6) {
                cout << "Oops! You got three sixes and count is zero\n";
                return 0;
            }
            else  {
                cout << "Dice rolled and got two 6 with "<<num2<<endl;
                return 12+num2;
            }
        }
        else {
            cout << "Dice rolled and got 6 with "<<num1<<endl;
            return num1 + 6;
        }
    }
    else {
        cout << "Dice rolled and got "<<num<<endl;
        return num;
    }
}
int position(int colour[][2]){
    int sum = 0;
    for (int i = 0 ; i < 4 ; i++){
        if (colour[i][1] > 0){
            sum += colour[i][1];
        }
    }
 return sum;
}
void peiceUnlocker(int colour[][2] , string peiceNames[] , bool start[]){
    for (int i = 0 ; i < 4 ; i ++){
        if (start[i] == false){
            start[i] = true;
            colour[i][1] += 6;
            cout << peiceNames[i][1] << " is now unlocked\n";
            break;
        }
    }
}
int peiceDecider(int colour [][2], bool start[]){
    int indexMove;
    for (int i = 0 ; i < 4 ; i++){
        if (start[i] == true && colour[i][0] == 0) indexMove = i;
    }
    return indexMove;
}
int unlockCheck(bool start[]){
    int indexUnlocked = 0;
    for (int i = 0 ; i < 4 ; i++){
        if (start[i] == true){
            indexUnlocked += 1;
        }
    }
    return indexUnlocked;
}
void move_6(int colour[][2] , string peiceName[] , bool start[]){
    int indexMove = peiceDecider(colour , start);
    int number = dice();
    colour[indexMove][1] += number;
    colour[indexMove][0] = 1;
    cout << peiceName[indexMove][1] <<" is moved to "<<colour[indexMove][1];
}
void move_12(bool start[], int colour[][2] , string peiceNames[]){
    int indexUnlocked = unlockCheck(start);
    int sum = 0;
    if (indexUnlocked < 4) peiceUnlocker(colour , peiceNames , start);
    else if(indexUnlocked == 4) move_6(colour , dice() , peiceNames , start);
}
int move_18(int colour[][2] , string peiceNames[] , bool start[]){
    int index = unlockCheck(start);
    int sum = position(colour);
    switch (index){
    case 1:
    case 2:
        unlocked(colour , peiceNames , start);
        unlocked(colour , peiceNames , start);
        move_6(colour , dice() , peiceNames , start);
        break;
    case 3:
        unlocked(colour , peiceNames , start);
        move_6(colour , dice() , peiceNames , start);
        break;
    case 4:
        move_6(colour , dice() , peiceNames , start);
    }
 return sum;
}
void checker(int colour[][2]){
    int size = 4;
    colour[size][2];
    for (int i = 0 ; i < 4 ; i++){
        if (colour[i][1] >= 56){
            for (int j = i ; j <(4-i) ; j++) colour[j][1] = colour[j+1][1];
            size--;
        }
    }
}
int play(int number , int colour[][2]){
    int number = dice();
    if (number >= 0 && number < 6){
        move_6(colour , )
    }
}
int pla(int current_position , bool* start , string player , bool* Player , int colour[][2] ,bool start[] , string peiceNames[] ){
    if (current_position < 56){ // already won check
        int num = rand()% 6 + 1;
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
    string Red[4] = {"Red 1" , "Red 2" , "Red 3" , "Red 4"};
    string Green[4] = {"Green 1" , "Green 2" , "Green 3" , "Green 4"};
    string Yellow[4] = {"Yellow 1" , "Yellow 2", "Yellow 3" , "Yellow 4"};
    string Blue[4] = {"Blue 1" , "Blue 2" , "Blue 3", "Blue 4"};
    int rowRed = 4 , rowGreen = 4 , rowBlue = 4 , rowYellow = 4;
    int col = 2;
    int red[rowRed][col] , green[rowGreen][col] , blue[rowBlue][col] , yellow[rowYellow][col];
    int turn = 1;
    int red = -6, yellow = -6, blue = -6, green = -6;
    bool redPeices[rowRed] , greenPeices[rowGreen] , bluePeices[rowBlue] , yellowPeices[rowYellow];
    for (int i = 0 ; i < 4 ; i++){
        yellowPeices[i] = false;
        greenPeices[i] = false;
        redPeices[i] = false;
        bluePeices[i] = false;
        yellow[i][1] = -6;
        green[i][1] = -6;
        red[i][1] = -6;
        blue[i][1] = -6;
        yellow[i][0] = 0;
        green[i][0] = 0;
        red[i][0] = 0;
        blue[i][0] = 0;
    }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
return 0;
}