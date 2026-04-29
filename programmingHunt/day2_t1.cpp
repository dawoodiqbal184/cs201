/*Your Objectives:
Define the Blueprint: Create a struct named Student. It must contain:
A name (use a char array of size 50, or a string).
A studentID (an int).
A gpa (a double or float).
Build the Roster: In your main() function, declare an array of 3 Student structures (e.g., Student roster[3];).
Collect the Data the Name, ID, and GPA for all 3 students.
Display the Results for all 3 students in a clean, readable format.*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;

struct students{
    char name[50];
    int id;
    float gpa;
};
void add(students student[] , bool array[] , int size);
void remove(students student[] , bool array[] , int size);
void display(students student[] , int size , bool array[]);
int tracker(bool array[] , int size);

void menu(){
    
    cout << "What are we upto today?\n";
    cout << "1) Add student\n";
    cout << "2) Delete data\n";
    cout << "3) Display all students data\n";
    cout << "4) Press 0 to exit\n";
    cout << "Enter your choice here : ";
    cout << "------------------------------"<<endl<<endl;
}


int main(){
    students student[3];
    bool array[3] ;
    fill_n(array , 3 , true);
    int choice = 4;
    while (choice != 0){
        menu();
        cin >> choice;
        if (choice == 0) break;
        else if (choice == 1) add(student , array , 3);
        else if (choice == 2) remove(student , array , 3);
        else if (choice == 3) display(student , 3 , array);
        cout <<endl<<"--------------------------------------"<<endl;
    }

}

void add(students student[] , bool array[] , int size){
    cin.ignore();
    int i = tracker(array , size);
    if (i == -1 ){
        cout << "Roster is full we cant add more students\n";
        return;
    }
    cout << "Enter the name of student : ";
    cin.getline(student[i].name , 50);
    cout << "Enter the id of student : ";
    cin >> student[i].id;
    cout << "Enter the gpa of student : ";
    cin >> student[i].gpa;
    cout <<endl<<endl;
    cout << "Student added successfully!\n";
    cout << setw(10)<<left<<"Name : "<<student[i].name<<endl;
    cout << setw(10)<<left<<"ID no. : "<<student[i].id<<endl;
    cout << setw(10)<<left<<"GPA : "<<student[i].gpa<<endl;
    array[i] = false;
}

void remove(students student[] , bool array[] , int size){
    cout << "Enter the id of student to remove it : ";
    int id;
    cin >> id;
    int i = 0;
    for(; i <size ; i++){
        if (student[i].id == id)break;
    }
    student[i].name[0] = '\0';
    student[i].id = 0;
    student[i].gpa = 0.0;
    array[i] = true;
    if (i >= size) {
        cout << "Student not found!"; 
        return; 
    }
}

void display(students student[] , int size , bool array[]){
    for (int i = 0 ; i < size ; i++){
        if (array[i] == false){
            cout << "Data for student number "<<i+1<<endl;
            cout << setw(10)<<left<<"Name : "<<student[i].name<<endl;
            cout << setw(10)<<left<<"ID no. : "<<student[i].id<<endl;
            cout << setw(10)<<left<<"GPA : "<<student[i].gpa<<endl;
            cout <<endl<<endl;
        }
        else continue;
    }
}

int tracker(bool array[] , int size){
    for (int i = 0 ; i < size ; i++){
        if (array[i] == true) return i;
    }
    return -1;
}