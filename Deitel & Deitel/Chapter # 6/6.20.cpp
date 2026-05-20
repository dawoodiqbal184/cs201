#include <iostream>
using namespace std;

bool factors(int , int);

int main(){
    int a, b;
    cout << "Enter two numbers :\n";
    cin >> a >> b;
    if(bool isfactor = factors(a,b)) cout << a<<" is a factor of "<<b<<endl;
    else cout << a<<" is a not factor of "<<b<<endl;
    return 0;
}

bool factors(int a, int b){
    if (b % a == 0) return true;
    else false;
}