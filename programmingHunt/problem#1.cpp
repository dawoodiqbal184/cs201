// A C++ program that takes in put salary of employees in a company and point out those employees having more base salary but lesser net salary
//but all of the task should be done by functions
#include<iostream>
#include<iomanip>
using namespace std;


void inputSalary(int salary[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << "Enter the salary of employ # "<<i+1<<endl;
        cout << "$ ";
        cin>>salary[i];
    }
}


int calSalary(int salary){
    float tax;
        if (salary > 5000 && salary <= 10000) {
            tax = salary * (0.05);
            salary -= tax;
        }
        else if (salary > 10000 && salary <= 15000) {
            float tax = salary * (0.1);
            salary = salary - tax;
        }
        else if (salary > 15000 && salary <= 20000) {
            float tax = salary * (0.15);
            salary = salary - tax;
        }
        else if (salary > 20000 ) {
            float tax = salary * (0.2);
            salary = salary - tax;
        }
    return salary;
}


int** converter(int array[] , int size){
    int** ptr = new int*[size];
    for (int i = 0 ; i < size ; i++){
        ptr[i] = new int[2];
    }
    for (int i = 0 ; i < size ; i++){
        ptr[i][0] = array[i];
        ptr[i][1] = calSalary(ptr[i][0]);
    }
    return ptr;
}


void output(int **ptr , int rows){
    cout <<left<<setw(12)<<"Employ"<<left<<setw(12)<<"Base salary"<<left<<setw(12)<<"Net salary\t"<<endl;
    for (int i = 0; i < rows ; i++){
        cout <<left<<setw(12)<<i+1;
       for (int j = 0 ; j < 2 ; j++){
        cout <<left<<setw(12)<< ptr[i][j];
       }
       cout << endl;
    }
}


void trackerx(int **ptr , int size){
    for (int i = 0 ; i < size ; i ++){
        for (int j = 0 ; j < size ; j++){
            if (i == j) continue;
            if (ptr[i][0] > ptr[j][0] && ptr[i][1]< ptr[j][1]){
                cout << "Employ # "<<i +1<<" has more base salary than employ # "<<j + 1<<" but has lesser net salary\n";
            }
        }
    }
}


int main (){
    int size;
    cout << "Enter the number of employees\n";
    cin >> size;
    int array[size];
    inputSalary(array , size);
    int **ptr = converter(array , size);
    output(ptr , size);
    trackerx(ptr , size);
    return 0;
}