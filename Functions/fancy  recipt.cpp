#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
    cout <<left << setw(10)<<"ITEM"<<left<<setw(5)<<"PRICE\n";
    cout <<"---------------\n";
    cout << fixed << setprecision(2);
    cout <<left <<setw(10)<<"Milk "<<"$"<<3.5<<endl;
    cout <<left <<setw(10)<<"Bread"<<"$"<<2.25<<endl;
    cout <<left <<setw(10)<<"Egg  "<<"$"<<4<<endl;
}