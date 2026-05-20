/*6.12 (Parking Charges) A parking garage charges a $20.00 minimum fee to park for up to three
hours. The garage charges an additional $5.00 per hour for each hour or part thereof in excess of three
hours. The maximum charge for any given 24-hour period is $50.00. Assume that no car parks for
longer than 24 hours at a time. Write a program that calculates and prints the parking charges for each
of three customers who parked their cars in this garage yesterday. You should enter the hours parked
for each customer. Your program should print the results in a neat tabular format and should calculate
and print the total of yesterday’s receipts. The program should use the function calculateCharges to
determine the charge for each customer.*/

#include <iostream>
#include <iomanip>
using namespace std;

template<typename t> inline t calCharges(t hours);
void menu(){
    cout << "\n\nWELCOME TO CAR PARKING MANAGEMENT SYSTEM\n\n"
        <<"What are we upto today :\n"
        <<"1)Generate parking slip for one car\n"
        <<"2)calculate the total amount\n"
        <<"Enter your choice : ";
    
}


void input(float array[] , int size){
    cout << "Enter the hours of each car parked : \n";
    for (int i = 0 ; i < size ; i++){
        cin >> array[i];
    }
}


int main(){
    int num;
    int choice;
    float charges;
    float hours;
    int size;
    float total;
    
    menu();
    cin >> choice;
    if (choice == 1){
        cout << "Enter the number of hours : ";
        cin >> hours;
        charges = calCharges(hours);
        cout <<"Hours : "<<hours << "\tParking bill : "<<charges;
    }
    else if(choice == 2){
        cout << "Enter the number of cars parked : ";
        cin >> size;
        float array[size];
        input(array , size);
        for (int i = 0 ; i < size ; i++){
            charges = calCharges(array[i]);
            cout <<"Number of hours parked  : "<<array[i]<<"\tParking bill : "<<charges<<endl;
            total += charges;
        }
        cout << "Total : "<<total;
    }

}
template<typename t> inline t calCharges(t hours){
    if (hours <= 24){
        if(hours <= 3) return 20;
    else if (hours > 3) return ((hours - 3) * 5) + 20;
    }
    else cout << "The car has been seized due to long parking time\nContact administration for further procedure\n";
    return 250;
}