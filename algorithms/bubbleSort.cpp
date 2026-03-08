#include<iostream>
using namespace std;
int main (){
    int array[9];
    cout << "enter array\n";
    for (int i = 0 ; i < 9 ; i++){
        cin >> array[i];
    }
    for (int i = 0 ; i < 8 ; i++){
        for (int j = 1 ; j < (9-i); j++){
            if (array[j]> array[j + 1]){
                int temp = array[j];
                array[j]=array[j+1];
                array[j+1]= temp;
            }
        }
        cout << array[0]<<" "<<array[1]<< " "<<array[2]<<" "<<array[3]<< " "<<array[4]<<" "<<array[5]<<" "<<array[6]<<" "<<array[7]<<" "<<array[8]<<endl;
    }
}