#include<iostream>
#include <fstream>
using namespace std;


int main(){
    ofstream file("variables.txt" , ios::out);
    ifstream input("varibles.txt" , ios:: out);
    int x = 0;
    cout << "Enter the value for x\n";
    while (x >= 0){
        cin >> x;
        file << x<<" ,";
    }
    file.close();
}