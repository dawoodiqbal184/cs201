#include<iostream>
#include<cmath>
using namespace std;

void output(int array[] , int size);
int *split(int array[] , int size , int *counter);
int *merge(int *ptr , int *ptr1 , int *ptr2 , int sizePtr);


int main(){
    int size;
    
    int array[8] = {1,2,3,4,5,6,7,8};
    int *ptr1;
    int *ptr2;
    for (int i = 0 ; i < 2 ; i++){
        if (i == 0) ptr1 = split(array , 8 , &i);
        else ptr2 = split(array , 8 , &i);
    }
    output(ptr1 , 4);
    output(ptr2 , 4);
    delete[]ptr1;
    delete[]ptr2;
}


void output(int array[] , int size){
    cout << "Your array is : {";
    for (int i = 0 ; i < size ; i++){
        if (i < size-1) cout << array[i]<<", ";
        else cout << array[i];
    }
    cout <<"}\n";
}

int *split(int array[] , int size , int *counter){
    int half = size / 2;
    int *ptr = new int[half];
    int j = 0;
    if(*counter % 2 == 0){
        for (int i = 0 ; i < size/2 ; i++){
            ptr[i] = array[i];
        }
    }
    else if(*counter % 2 != 0){
        for(int i = size / 2 ; i < size ; i++ && j++){
            ptr[j] = array[i];
        }
    }
    else ptr = nullptr;
    return ptr;
}


int *merge(int *ptr , int *ptr1 , int *ptr2 , int sizePtr){
    int pos = 0, pos1 = 0;
    for (int i = 0 ; i < sizePtr ; i++){
        if (ptr1[pos] > ptr2[pos1]) {
            ptr2[i] = ptr1[pos1];
            pos1++;
        }
        else {
            ptr2[i] = ptr[pos];
            pos++;
        }
    }
    return ptr;
}