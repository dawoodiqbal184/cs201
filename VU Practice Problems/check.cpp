#include<iostream>
using namespace std;
int main (){
    int array[10];
    for (int i = 0 ; i < 10 ; i++){
        cout << &array[i];
        cout << endl;
    }
}