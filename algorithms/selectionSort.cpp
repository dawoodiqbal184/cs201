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
    int array[5] = {5 , 7 , 8 , 11 , 2};
    for (int i = 0 ; i < 5 ; i++){
        output(array , 5);
        int min = minIndex(array , start , 5);
        swap(array , min , start);
        start++;
    }
    return 0;
}