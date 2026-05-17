#include <iostream>
#include <string>

using namespace std;

class Test {
public:
    Test() { cout << "Object Created!" << endl; }
};

int main() {
    cout << "--- START OF PROGRAM ---" << endl;
    
    Test myObj; // Your class test
    
    cout << "--- END OF PROGRAM ---" << endl;
    cout << "Press ENTER to close this window..." << endl;
    
    cin.get(); // This is the most important line
    return 0;
}