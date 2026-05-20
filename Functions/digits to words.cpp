#include <iostream>
#include <string>
using namespace std;
void print_digit (int num1)
{
    if (num1 >=0 && num1 <=9)
    {
   if (num1 == 1) cout << " one ";
    else if (num1 == 2) cout << " two ";
    else if (num1 == 3) cout << " three ";
    else if (num1 == 4) cout << " four ";
    else if (num1 == 5) cout << " five ";
    else if (num1 == 6) cout << " six ";
    else if (num1 == 7) cout << " seven ";
    else if (num1 == 8) cout << " eight ";
    else if (num1 == 9) cout << " nine ";
    }
}
void print_tens (int num2)
{
    if (num2 == 2) cout << " twenty ";
    else if (num2 == 3) cout << " thirty ";
    else if (num2 == 4) cout << " fourty ";
    else if (num2 == 5) cout << " fifty ";
    else if (num2 == 6) cout << " sixty ";
    else if (num2 == 7) cout << " seventy ";
    else if (num2 == 8) cout << " eighty ";
    else if (num2 == 9) cout << " ninety ";
}
void print_tens1(int num1)
{
    if (num1>=0 && num1 <=9)
    {
    if (num1 == 0) cout << " ten ";
        else if (num1 == 1 ) cout << " eleven";
        else if (num1 == 2) cout << " twelve";
        else if (num1 == 3) cout << " thirteen";
        else if (num1 == 4) cout << " fourteen";
        else if (num1 == 5) cout << " fifteen";
        else if (num1 == 6) cout << " sixteen";
        else if (num1 == 7) cout << " seventeen";
        else if (num1 == 8) cout << " eighteen";
        else if (num1 == 9)  cout << " nineteen";
    }
}
int main ()
{
    int x;
    cout << "Enter your number\n";
    cin >> x;
    string t = "thousand";
    string h = "hundreds";
    string a = "and";
    int num1 = x % 10;
    int num2 = (x/10) % 10;
    int num3 = (x/100) % 10;
    int num4 = (x / 1000);
    cout << "The number you entered was :\n";
    cout << num4 <<" "<< num3 << " "<< num2 << " "<<num1<<endl;
    cout << "Your number in words is :\n";
    if (num4 !=0)
    {
        print_digit(num4);
        cout << " "<<t;
    } 
    if (num3 != 0) 
    {
        print_digit(num3);
        cout << " " << h<<" "<< a;
    }
    if (num2 != 0) print_tens(num2);
    if (num2 == 1 && num1 >=0 && num1 <9) print_tens1(num1);
    if (num1 != 0 && num2 != 1) print_digit(num1);
    return 0;
}
