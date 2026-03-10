#include<iostream>
using namespace std;

void output(int array[] , int size){
    cout << "Your array is : {";
    for (int i = 0 ; i < size ; i++){
        if (i == size -1) cout << array[i];
        else cout << array[i]<<" ,";
    }
    cout <<"}"<<endl;
}

void insertionSort(int array[] , int size){
    int pos , val , count;
    for (count = 1 ; count < size ; count++){
        val = array[count];
        for (pos = count - 1 ; pos >= 0 ; pos--){
            if (array[pos] > val) array[pos+1] = array[pos];
            else break;
        }
        array[pos+1] = val;
        output(array , size);
    }
}

void input(int array[] , int size){
    cout << "Enter the unsorted array\n";
    for (int i = 0 ; i < size ; i++) cin >> array[i];
}


int main(){
    int size;
    cout << "Enter size of unsorted array : ";
    cin >> size;
    int array[size];
    input(array , size);
    insertionSort(array , size);
    return 0;
}