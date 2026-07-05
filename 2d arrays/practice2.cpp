/*The Mission: Write a complete C++ program that dynamically allocates a 1D array of 5 integers, 
fills it with numbers (e.g., 1, 2, 3, 4, 5), and passes it to a function that reverses the array in-place. 
Finally, print the reversed array and safely delete it.
CHALLENGES : 
Inside your reversal function, you are strictly forbidden from doing the following:
You cannot use array brackets [] (e.g., array[i] is illegal).
You cannot use a standard for(int i = 0...) index loop.
*/
#include <iostream>
using namespace std;

void reverse(int *start , int * end);
void swap(int *a , int *b);
void input(int *array , int size);
void output(int *array , int size);

int main(){
    int size = 5;
    int *array = new int[size];
    int *start = array;
    int *end = (array+(size - 1));
    input(array , size);
    reverse(start , end);
    output(array , size);
 return 0;
}

void reverse(int *start , int * end){
    if (start == nullptr || end == nullptr) return;
    else{
        while (start < end){
            swap(start , end);
            start++;
            end--;
        }
    }
}

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
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