#include<iostream>
using namespace std;


void swap(int array[], int minIndex, int start){
    int temp = array[minIndex];
    array[minIndex] = array[start];
    array[start] = temp;
}


int minIndex(int array[], int start , int size){
    int min = start;
    for (int i = start+1 ; i < size ; i++){
        if (array[i] < array[min]){
            min = i;
        }
    }
    return min;
}

void input(int array[] , int size){
    cout << "Enter your array :\n";
    for (int i = 0 ; i < size ; i++){
        cin >> array[i];
    }
}


void output(int array[] , int size){
    cout << "Your array is : { ";
    for (int i = 0 ; i < size ; i++){
        if (i < size -1) cout << array[i]<<", ";
        else cout << array[i];
    }
    cout << "}"<<endl;
}


int main(){
    int start = 0;
    int size;
    cout << "Enter the size of un-sorted array : ";
    cin >> size;
    int array[size];
    input(array , size);
    for (int i = 0 ; i < size ; i++){
        output(array , size);
        int min = minIndex(array , start , size);
        swap(array , min , start);
        start++;
    }
    return 0;
}