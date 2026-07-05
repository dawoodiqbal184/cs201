// Write a C++ program that creates a 2d array fills it displays it and finally deletes it

#include <iostream>
using namespace std;

int **declareArray(int rows , int cols){
    if(rows < 0 || cols < 0) return nullptr;
    int **array = new int* [rows];
    int n = 0;
    for(int i = 0 ; i < rows ; i++) array[i] = new int [cols];
 return array;
}

void input(int ** array , int rows , int cols){
    if(rows < 0 || cols < 0) return;
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            cout << "Enter the value for row # "<<i+1<<" and column # "<<j+1<< " : ";
            cin >> array[i][j];
        }
    }
}

void output(int ** array , int rows , int cols ){
    if(rows < 0 || cols < 0) return;
    cout << "Your matrix was : \n";
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++) cout << array[i][j]<<"\t";
        cout <<endl;
    }
}

void deleteArray(int ** &array , int rows){
    if (array == nullptr) return;
    else {
        for(int i = 0 ; i < rows ; i++){
            delete[] array[i];
        }
        delete [] array;
    }
    array = nullptr;
}
int main(){
    int rows = 2;
    int cols = 5;
    int **array = declareArray(rows , cols);
    input(array , rows , cols);
    output(array , rows , cols);
    deleteArray(array , rows);
    return 0;
}