#include <iostream>
using namespace std;

bool factors( int );
void input (int array[] , int size ){
    cout << "Enter your array : \n";
    for (int i = 0 ; i < size ; i++) cin >>array[i];
}

int main(){
    int size;
    cout <<"How many numbers do you want to check\n";
    cin >> size;
    int array[size];
    input(array,size);
    for (int i = 0 ; i < size ; i++){
        if(factors(array[i])) cout <<"3 is a factor of "<<array[i]<<endl;
        else cout <<"3 is not a factor of "<<array[i]<<endl;
    }
   
}

bool factors(int a ){
        if (a % 3 != 0) return false;
        else return true;
}