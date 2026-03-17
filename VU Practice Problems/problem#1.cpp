// A C++ program that takes in put salary of employees in a company and point out those employees having more base salary but lesser net salary
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


void output(int array[][2] , int rows){
    cout <<left<<setw(12)<<"Employ"<<left<<setw(12)<<"Base salary"<<left<<setw(12)<<"Net salary\t"<<endl;
    for (int i = 0; i < rows ; i++){
        cout <<left<<setw(12)<<i+1;
       for (int j = 0 ; j < 2 ; j++){
        cout <<left<<setw(12)<< array[i][j];
       }
       cout << endl;
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

void tracker(int array[][2] , int rows){
    
    for(int i = 0; i < rows ; i++){
        for(int j = 0 ; j < 2 ; j++){
            if (array[i][0] > array[j][0] && array[j][1]> array[i][1]){
                cout << "Employ # "<<i+1<<" is unlucky having base salary more than employ # "<<j+1<<" but net salary is lesser\n";
            }
        }
    }
}


void converter(int array[] , int size){
    int arrayNew[size][2];
    for (int i = 0 ; i < size ; i++){
        arrayNew[i][0] = array[i];
        arrayNew[i][1] = calSalary(arrayNew[i][0]);
    }
    int* ptr = *arrayNew;
    output(arrayNew , size);
    tracker(arrayNew , size);
}


int main (){
    int size;
    cout << "Enter the number of employees\n";
    cin >> size;
    int array[size];
    inputSalary(array , size);
    converter(array , size);
    return 0;
}