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


int calSalary(int salary){
    float tax;
        if (salary > 5000 && salary < 10000) {
            tax = salary * (0.05);
            salary -= tax;
        }
        else if (salary > 10000 && salary < 15000) {
            float tax = salary * (0.1);
            salary = salary - tax;
        }
        else if (salary > 15000 && salary < 20000) {
            float tax = salary * (0.15);
            salary = salary - tax;
        }
        else if (salary > 20000 ) {
            float tax = salary * (0.2);
            salary = salary - tax;
        }
    return salary;
}


int* converter(int array[] , int size){
    int cols = 2;
    int arrayNew[size][cols];
    for (int i = 0 ; i < size ; i++){
        arrayNew[i][0] = array[i];
        arrayNew[i][1] = calSalary(arrayNew[i][0]);
    }
    int* ptr = *arrayNew;
    cout <<left<<setw(10)<<"Employ"<<left<<setw(12)<<"Base salary"<<left<<setw(12)<<"Net salary\t"<<endl;
    for (int i = 0; i < size ; i++){
        cout <<left<<setw(10)<<i+1 <<left<<setw(12)<<*(ptr+i)<<left<<setw(12)<<*(ptr+i+size)<<endl;
    }
    return ptr;
}


void tracker(int** array , int size){
    
    for(int i = 0; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if (*(array + i) > *(array+j) && *(array + size + i) < *(array + size +j)){
                cout << "Employ # "<<i<<" is unlucky having base salary more than employ # "<<j<<" but net salary is lesser\n";
            }
        }
    }
}


void output(int** ptr , int size){
    cout <<"Employ \t"<<"Base salary\t"<<"Net salary\t"<<endl;
    for (int i = 0; i < size ; i++){
        cout <<i <<"\t"<<**ptr<<"\t"<<**(ptr+size)<<endl;
        ptr++;
    }
    
}


void worker(int array[] , int *size){
    inputSalary(array , *size);
    int* ptr = converter(array , *size);
    tracker(&ptr , *size);
    output(&ptr , *size);
}


int main (){
    int size;
    cout << "Enter the number of employees\n";
    cin >> size;
    int array[size];
    int* ptr;
    inputSalary(array , size);
    ptr = converter(array , size);
    tracker(&ptr , size);
    return 0;
}