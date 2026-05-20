#include <iostream>
using namespace std;
int sqr(int x)
{
    return  x * x;
}
int cube(int x)
{
    return x * x * x ;
}
int quadra(int x)
{
    return x* x * x * x;
}
int penta ( int x)
{
    return x * x * x * x * x;
}
int hexa ( int x)
{
    return x * x * x * x * x * x ;
}

int main ()
{
    int x;
    int y;
    cout << "Enter a number\n";
    cin >> x;
    cout << "enter which power you need\n";
    cin >> y;
    if (y > 1 && y < 7)
    {
        if ( y == 2)
        {
            cout << sqr(x);
        }
        if (y == 3)
        {
            cout << cube(x);
        }
        if ( y == 4)
        {
            cout << quadra(x);
        }
        if (y == 5)
        {
            cout << penta (x);
        }
        if (y == 6)
        {
            cout << hexa(x);
        }
    }
    return 0;
}
