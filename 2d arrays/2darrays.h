#ifndef arrays2d_H
#define arrays2d_H
#include<iostream>
using namespace std;
void input_xBy3(int array[][3] , int maxRows){
    array[maxRows][3];
    for (int row = 0 ; row < maxRows ; row++){
        for (int cols = 0 ; cols < 3 ; cols++){
            cout << "Enter value for row # "<< row+1 << " column # "<< cols+1 <<endl;
            cin >> array[row][cols];
        }
    }
}
void output_xBy3(int array[][3] , int maxRows){
    array[maxRows][3];
    for (int row = 0 ; row < maxRows ; row++){
        for (int cols = 0 ; cols < 3 ; cols++){
            cout << array[row][cols] << "\t";
        }
        cout <<endl;
    }
}
void output_xBy4(int array[][3] , int maxRows){
    array[maxRows][3];
    for (int row = 0 ; row < maxRows ; row++){
        for (int cols = 0 ; cols < 4 ; cols++){
            cout << array[row][cols] << "\t";
        }
        cout <<endl;
    }
}
int* arrayExt_3(int array[][3] , int maxRows){
    int newArray[maxRows+1][4];
    for (int i = 0 ; i < maxRows ; i++){
        for (int j = 0 ; j < 4 ; j++){
            newArray[maxRows][j] = array[maxRows][j];
        }
    }
    return *newArray;
}
#endif