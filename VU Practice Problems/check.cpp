#include<iostream>
using namespace std;
int main (){
    int *ptr ;
    int array[2];
    for (int i = 0 ; i < 2 ; i++){
        cin >> array[i];
        cout << endl;
    }
    ptr = array;
    cout <<*ptr;
}