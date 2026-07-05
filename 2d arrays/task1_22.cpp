#include <iostream>
using namespace std;

int *declareArray(int size);
int evenCount(int *array , int size);
void input(int *array , int size);
void output(int *array , int size);
void traverse(int *array1 , int *array2 , int* &array3 , int size1 , int size2);


int main(){
    int size1 , size2;
    cout << "Enter the sizes of arrays : ";
    cin >> size1 >> size2;
    int *array1 = declareArray(size1);
    int * array2 = declareArray(size2);
    input(array1 , size1);
    input(array2 , size2);
    int size3 = 0;
    size3 += evenCount(array1 , size1);
    size3 += evenCount(array2 , size2);
    int *array3 = declareArray(size3);
    traverse(array1 , array2 , array3 , size1 , size2);
    output(array3 , size3);
    delete[]array1;
    array1 = nullptr;
    delete[] array2;
    array2 = nullptr;
    delete[]array3;
    array3 = nullptr;
    return 0;

}

 int *declareArray(int size){
    if(size <= 0) return nullptr;
    int *array = new int[size];
    return array;
 }

 int evenCount(int *array , int size){
    int count = 0;
    for (int i = 0 ; i < size ; i++){
        if (array[i] % 2 == 0 ) count +=1;
    }
    return count;
 }

 void input(int *array , int size){
    cout << "Enter your array : ";
    for (int i = 0 ; i < size ; i++) cin >> *(array+i);
}

void output(int *array , int size){
    cout << "Your array was : ";
    for (int i = 0 ; i < size ; i++){
        cout << *(array + i);
    }
}

void traverse(int *array1 , int *array2 , int* &array3 , int size1 , int size2){
    int n = 0;
    for (int i = 0 ; i < size1 ; i++){
        if(array1[i] % 2 == 0){
            array3[n] = array1[i];
            n++;
        }
    }
    for (int i = 0 ; i < size2 ; i++){
        if(array2[i] % 2 == 0){
            array3[n] = array2[i];
            n++;
        }
    }
}