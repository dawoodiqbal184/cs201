#include<iostream>
using namespace std;

int* converter(int* ptr , int array[]){
    ptr = &array[0];
}
int main (){
    int array[10];
    for (int i = 0 ; i < 10 ; i++){
        cout << &array[i];
        cout << endl;
    }
}