/*Your Objectives:
The Setup: Create a new C++ file. Include <fstream>.
Write the Data: Open a file named data.txt in output mode (ios::out) and write exactly this string into it: "Virtual University CS201". Close the file.
The Precision Jump: Open the same file in input mode (ios::in).
The Target: Use the seekg() function to jump your reading cursor past the words "Virtual University " so it lands exactly at the start of "CS201".
The Extraction: Read that specific word into a character array or string, and print it to your terminal to prove you successfully sniped it out of the file.*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int target(char array[]){
    int count = 0;
    for (int i = 0 ; array[i] != '\0' ; i++) count ++;
    return count;
}

void print(fstream &myFile){
    char array[150];
    cout << "Enter the file content before the target string :\n";
    cin.getline(array , 150);
    int x = target(array);

    myFile.seekg(x , ios::beg);
    myFile.getline(array , 150 , myFile.eof());
    cout << array<<endl;
}

int main(){
    fstream myFile("sample.txt" , ios::in | ios::ate);
    print(myFile);
    return 0;
}