// A C++ program that takes in put salary of employees in a company and point out those employees having more base salary but lesser net salary
#include<iostream>
using namespace std;


void inputSalary(int salary[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << "Enter the salary of employ # "<<i<<endl;
        cout << "$ ";
        cin>>salary[i];
    }
}


int calSalary(int salary){
    float tax;
    for (int i = 0 ; i < 10 ; i++){
        if (salary > 5000 && salary < 10000) {
            
            tax = salary * (0.05);
            salary = salary - tax;
        }
        else if (salary > 0 && salary < 5000) {
            
            float tax = salary * (0);
            salary = salary - tax;
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
            
            float tax = salary * (0.1);
            salary = salary - tax;
        }
    }
    return salary;
}


int* converter(int array[] , int size){
    int cols;
    cout << "How many columns do you want :";
    cin >> cols;
    int arrayNew[size][cols];
    for (int i = 0 ; i < size ; i++){
        arrayNew[i][0] = array[i];
        arrayNew[i][1] = calSalary(arrayNew[i][0]);
    }
    int* ptr = *arrayNew;
    return ptr;
}


void tracker(int* array , int size){
    for(int i = 0; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if (*(array + i) > *(array+j) && *(array + i) < *(array +j)){
                cout << "Employ # "<<i<<" is unlucky having base salary more than employ # "<<j<<" but net salary is lesser\n";
            }
        }
    }
}


void output(int* ptr , int size){
    cout <<"Employ Numbers\t"<<"Base salary\t"<<"Net salary\t"<<endl;
    for (int i = 0; i < size ; i++)
    cout <<i <<"\t"<<*ptr<<"\t"<<*(ptr+size)<<endl;
    ptr++;
}


void worker(int array[] , int size){
    inputSalary(array , size);
    int* ptr = converter(array , size);
    tracker(ptr , size);
    output(ptr , size);

}


int main (){
    int size;
    cout << "Enter the number of employees\n";
    cin >> size;
    int array[size];
    worker(array , size);
    return 0;
}