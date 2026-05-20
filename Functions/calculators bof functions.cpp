#include <iostream>
using namespace std;
int subtract(int x , int y)
{   
    return x - y;
}
int add(int x , int y)
{
    return x + y;
}
int product(int x , int y)
{
    return x * y;
}
int divide(int x , int y)
{
    return x / y;
}
int main()
{
    int x = 0;
    int y = 0;
    char choice;
    char quit = 'q';
    cout << "Enter your choice\n";
    cout << "1) Addition\n";
    cout << "2) Subtraction\n";
    cout << "3) Multiplication\n";
    cout << "4) Division\n";
    cout << "5) for quit press q\n";
    cin >> choice ;
    if (choice == 'q')
    {
        cout << "Thank you for using\n";
    }
    if (choice != 'q')
    {
        cout << "Enter your integers\n";
        cin >> x >> y;
        if (choice == 1)
        {
            int ans = add(x , y);
            cout << "Your answer is " << ans;
        }
        else if (choice == 2)
        {
            int ans = subtract(x , y);
            cout <<  "Your answer is " <<ans;
        }
        else if (choice == 3)
        {
            int ans = product (x , y);
            cout <<  "Your answer is " <<ans;
        }
        else if (choice == 4)
        {
            int ans = divide( x , y);
            cout <<  "Your answer is " <<ans;
        }
    }
    else
    {
        cout << "Please enter a valid choice\n";
    }
    return 0;

}