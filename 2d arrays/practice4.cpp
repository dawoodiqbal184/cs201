#include <iostream>
using namespace std;

void grow(char *&array , int &size);
void arrCpy(char *source , char *destination , int size);
void swap(char &a , char &b);
void reverse(char* &array , int start , int end);
void reverseOrder(char* &array , int size);
void spaceTeller(int &count , char* array , int size);
int spaceCounts(char *array , int size);
int main(){
    char *array = nullptr;
    int size = 0;
    char temp;
    cout << "Enter your sentence : ";
    while(true){
        cin.get(temp);
        if(temp == '\n') break;
        grow(array , size);
        array[size - 1] = temp;
    }
    grow(array , size);
        array[size - 1] = '\0';
    reverseOrder(array , size);
    cout << array;
}

void grow(char *&array , int &size){
    char *arr = new char[size+1];
    arrCpy(array , arr , size);
    size++;
    delete[]array;
    array = arr;
    arr = nullptr;
}

void arrCpy(char *source , char *destination , int size){
    for(int i = 0 ; i < size ; i++){
        destination[i] = source[i];
    }
}

void swap(char &a , char &b){
    char temp = a;
    a = b;
    b = temp;
}

void reverse(char* &array , int start , int end){
    while(start < end){
        swap(array[start] , array[end]);
        start++;
        end--;
    }
}

void reverseOrder(char* &array , int size){
    int start = 0 , end = size-2;
    reverse(array , start , end);
    int count = 0;
    int spaces = spaceCounts(array , size);
    end = 0;
    for ( int i = 0 ; i < spaces+1 ; i++){
        spaceTeller(end , array , size);
        reverse(array , start , (end -1));
        start = end + 1;
    }
}

void spaceTeller(int &count , char* array , int size){
    for (int i = count + 1 ; i < size ; i++){
        if (array[i] == ' ' || array[i] == '\0'){
            count = i;
            break;
        }
    }
}

int spaceCounts(char *array , int size){
    int count = 0;
    for (int i = count+1 ; i < size ; i++){
        if (array[i] == ' ') count += 1;
    }
 return count;
}