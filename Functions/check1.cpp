#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int maximum(int a , int b , int c )
{
    int maximum{a};
    if (b > maximum) maximum = b;
    if (c > maximum) maximum = c;
    return maximum;
}
int sum_digits(int x , int y)
{
    int z;
    z = x + y;
    return z;
}
int main ()
{
   int a , b , c;
    cout << "Enter your numbers : \n";
    cin >> a >> b >> c;
    cout << "The maximum number is : "<<maximum(a , b , c) << endl;
}