/*The Payload: In main(), create a char array holding a secret message: char message[] = "Mission Accomplished";
The Cryptographer: Create a void function named encryptDecrypt. It must accept a pointer to a char: void encryptDecrypt(char* ptr)
The Pointer Walk: Inside the function, use a while loop to walk the pointer forward until it hits the null character \0 (the end of the string).
The Bitwise Shift: Inside the loop, use the XOR operator ^ to modify the value the pointer is looking at using a secret integer key (e.g., key = 5).
The Test: In main(), call the function on your message and print it. 
It should look like absolute garbage. 
Then, call the function again on the same message and print it. It should read perfectly clear again.*/

#include <iostream>
using namespace std;

void encrypt(char *ptr);
void decrypt(char *ptr);

int main(){
    char array[] = "Mission Acomplished";
    char *ptr = array;
    cout << "The encrypted message is : ";
    encrypt(ptr);
    cout << "The decrypted message is : ";
    decrypt(ptr);
    return 0;
}

void encrypt(char *ptr){
    for (int i = 0 ; ptr[i] != '\0' ; i++){
        ptr[i] = (ptr[i] ^ 5);
        cout << ptr[i];
    }
    cout << endl;
}

void decrypt(char *ptr){
    for (int i = 0 ; ptr[i] != '\0' ; i++){
        ptr[i] = ((ptr[i] ^ 5));
        cout <<ptr[i];
    }
    cout << endl;
}