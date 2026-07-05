/*The Mission: Create a 4x4 matrix of numbers. Write a function that finds the transpose of matrix by flipping the actual positions of values. 
*/

#include <iostream>
using namespace std;


void transpose(int **&array , int rows , int cols);
void swap(int &a , int &b);
int **declareArray(int rows , int cols);
void input(int ** array , int rows , int cols);
void output(int ** array , int rows , int cols );


int main(){
    int cols = 3;
    int rows = 3;
    int **array = declareArray(rows , cols);
    input(array , rows , cols);
    transpose(array , rows , cols);
    //output(array , rows , cols);
}
void transpose(int **&array , int rows , int cols){
    for (int i = 0 ; i < rows ; i++){
        for (int j = i ; j < cols ; j++){
            if (i == j) continue;
            else swap(array[i][j] , array[j][i]);
        }
    }
    output(array , rows , cols);
}


void swap(int &a , int &b){
    int temp = a;
    a = b;
    b = temp;
}


void output(int ** array , int rows , int cols ){
    if(rows < 0 || cols < 0) return;
    cout << "Your matrix was : \n";
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++) cout << array[i][j]<<"\t";
        cout <<endl;
    }
    
}

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