#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main ()
{
    int num;
    srand(time(0));
   for (int a = 1 ; a <=3 ; a++)
   {
    num = rand() % 50;
    cout << num << endl;
   }
}