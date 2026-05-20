#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
int main(){
    char word[5] = "Code";
    char dust[5];
    word[4] = '!';
    strcpy(dust , word);
    cout << dust;
}