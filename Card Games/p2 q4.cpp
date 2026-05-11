#include <iostream>
#include <iomanip> // Needed for setw() to align the columns perfectly
using namespace std;

// Function prototype
void printMultiplicationGrid(int size);

int main() {
    int size = 4;
    printMultiplicationGrid(size);
    
    return 0;
}

void printMultiplicationGrid(int size) {
    // The outer loop runs once for each row
    for (int i = 1; i <= size; i++) {
        
        // The inner loop runs completely from 1 to 'size' for every single row
        for (int j = 1; j <= size; j++) {
            
            // Multiply the row number by the column number
            // setw(3) ensures every number takes up exactly 3 spaces so the grid aligns
            cout << setw(3) << (i * j); 
        }
        
        // After the inner loop finishes a row, print a newline to start the next row
        cout << endl; 
    }
}