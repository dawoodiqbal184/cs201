// A C++ program that takes in put salary of employees in a company and point out those employees having more base salary but lesser net salary
#include<iostream>
using namespace std;
void inputSalary(int salary[], int x){
    for (int i = 0 ; i < x ; i++){
        cout << "Enter the salaries of employ # "<<i<<endl;
        cout << "$ ";
        cin>>salary[i];
    }
}
void calSalary(int salary[][2] , int x){
    for (int i = 0 ; i < x ; i++){
        if (salary[i][0] > 5000 && salary[i][0] < 10000) {
            cout << "Tax Rate is 5% according to salary $5k to $10k\n";
            float tax = salary[i][0] * (0.05);
            salary[i][1] = salary[i][0] - tax;
        }
        else if (salary[i][0] > 0 && salary[i][0] < 5000) {
            cout << "Tax Rate is 0% for salary upto $5k\n";
            float tax = salary[i][0] * (0);
            salary[i][1] = salary[i][0] - tax;
        }
        else if (salary[i][0] > 10000 && salary[i][0] < 15000) {
            cout << "Tax Rate is 10% according to salary $10k to $15k\n";
            float tax = salary[i][0] * (0.1);
            salary[i][1] = salary[i][0] - tax;
        }
        else if (salary[i][0] > 15000 && salary[i][0] < 20000) {
            cout << "Tax Rate is 15% according to salary $15k to $20k\n";
            float tax = salary[i][0] * (0.15);
            salary[i][1] = salary[i][0] - tax;
        }
        else if (salary[i][0] > 20000 ) {
            cout << "Tax Rate is 20% according to salary more than $20k\n";
            float tax = salary[i][0] * (0.1);
            salary[i][1] = salary[i][0] - tax;
        }
    }
}
void converter()