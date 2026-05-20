#include <iostream> 
using namespace std; 
void valuesArray(int array[] , int size){
    for (int i = 0 ; i < size ; i ++) cin >> array[i];
}  
void printArray(int array[], int size){
    for (int i = 0 ; i < size ; i ++) cout << array[i] <<", ";
}
void addArray(int array[] , int size){
    for (int i = 0 ; i < size ; i++) array[i] += 10;
}
int main (){
    int array[5];
    cout << "enter your array\n";
    valuesArray(array , 5);
    addArray(array , 5);
    cout << "{ ";
    printArray(array , 5);
    cout << "}";
}
