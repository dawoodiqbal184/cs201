#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main () 
{
  srand(time (0));
  double num = rand() % 41 + 10;
  cout << fixed << setprecision(2);
  cout << "----- PRICE CHECK -----\n";
  cout << left << setw(14)<< "Original Price"<<right<<setw(5)<<"$"<<145.99<<endl;
  double discount = (num / 100) * 145.99;
  double price = 145.99 - discount;
  cout << left << setw(20)<< "Discount (%)"<<right<<setw(5)<<num<<endl;
  for (int a = 1 ; a <=25 ; a++) cout << "-";
  cout << endl;
  cout << left << setw(14)<< "Final Price"<<right<<setw(5)<<"$"<<price<<endl;
  return 0;
}