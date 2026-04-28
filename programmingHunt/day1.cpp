/*Write a C++ program that reads passwords.txt and filters the data into two new files based on security rules.
The Rules:
1) Read each password safely using getline. Assume no password is longer than 50 characters.
2) Use the strlen function (from <cstring>) to check the length of the password.
3) If the password is less than 8 characters, write it to a new file called weak.txt.
4) If the password is 8 characters or more, write it to a new file called strong.txt.
5) Close all three files when finished.*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

void weak(char array[] , ofstream &);
void strong(char array[] , ofstream &);

int main(){
    ifstream input("passwords.txt" , ios::in);
    ofstream strongP("strong.txt" , ios::out);
    ofstream weakP("weak.txt" , ios::out);
    char ch[20];
    if(!input){
        cerr << "File could not be opened\n";
        exit(EXIT_FAILURE);
    }
    while(!input.eof()){
       
        input.getline( ch , 20 , '\n');
        int x = strlen(ch);
        if( x >= 8) {
            strong(ch , strongP);
        }
        else if (x < 8 ){
            weak(ch , weakP);
        }
    }
    input.close();
    strongP.close();
    weakP.close();
    return 0;
}


void weak(char array[], ofstream &output){
    output << array<<'\n';
}


void strong(char array[] , ofstream &output){
    output << array << '\n';
}