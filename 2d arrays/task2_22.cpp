#include <iostream>
#include <fstream>
using namespace std;

void output(char array[][5] , int rows = 5 , int cols = 5);
void fillMatrix(char array[][5] , int rows = 5); 
void spaceFiller(char array[][5]);
int main(){
    char array[5][5];
    spaceFiller(array);
    fillMatrix(array);
    output(array);
}

void output(char array[][5] , int rows , int cols ){
    if(rows < 0 || cols < 0) return;
    cout << "Your matrix was : \n";
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++) cout << array[i][j]<<"\t";
        cout <<endl;
    }
}

void fillMatrix(char array[][5] , int rows){
    ifstream input("matrix.txt");
    int a , b;
    char c;
    while(!input.eof()){
        input >> a;
        input.ignore(1 , ',');
        input>> b ;
        input.ignore(1 , ',');
        input >> c;
        array[a][b] = c;
    }
}

void spaceFiller(char array[][5]){
    for (int i = 0 ; i < 5 ; i ++){
        for (int j = 0 ; j < 5 ; j++){
            array[i][j] = '.';
        }
    }
}