#include <iostream>
using namespace std;

/*int calSum(int **array , int cols , int rows){
    int sum = 0;
    for(int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            if(i == 0 || i == (rows-1)) sum += array[i][j];
            else if(j == 0 || j == (cols-1)) sum += array[i][j];
            
    }
 return sum;
}
}

void checker(int array[][3] , int rows){
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < 3 ; j++){
            if (array[i][j] % 2 == 0) array[i][j] = 0;
            else array[i][j] = 1;
        }
    }
}

int sumPrimary(int array[][3] , int rows){
    int sum = 0 ;
    for (int i = 0 ; i < rows ; i++){
        sum += array[i][i];
    }
    return sum;
}
*/
int maxNum(int *array , int size){
    int max = 0 ; 
    for (int i = 0 ; i < size ; i++){
        if (array[i] > max)max = i;
    }
 return array[max];
}

bool max_inCol(int  array[][3] , int selectedRow ,  int num){
    for(int i = 0 ; i < 3 ; i++){
        if(array[i][selectedRow] > num) return false;
    }
 return true;
}

int minIndex(int *array , int size){
    int min = array[0];
    for (int i = 0 ; i < size ; i++){
        if(array[i] > min )min = i;
    }
 return min;
}

int minNum(int *array , int size){
    int min = array[0] ; 
    for (int i = 0 ; i < size ; i++){
        if (array[i] < min)min = i;
    }
 return array[min];
}


void printSaddle(int array[][3] , int rows){
    int minInd;
    int min;
    int max;
    for(int i = 0 ; i < rows ; i++){
        minInd = minIndex(array[i] , rows);
        min = array[i][minInd];
        if (max_inCol(array , minInd , min )) cout << "Saddle point found on row # "<<i+1<<" and it is : "<< min<<endl;
    }
}
int main(){
    int array[3][3] = {20 , 31 , 7 , 2 , 1 , 6 , 2 , 2, 5};
    printSaddle(array , 3);
}