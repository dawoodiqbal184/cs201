/*The Objective:
    Create a program that takes a Student struct and permanently saves it to a text file.
The Requirements:
1) The Blueprint: Use the Student struct you built in Mission 1 (name, ID, GPA).
2) The Input: Ask the user to enter the data for one student.
3) The Save Feature: Open a file named database.txt in Append Mode (ios::app).
4) The Write: Write the student's data into the file. Format it nicely (e.g., Name: Dawood | ID: 123 | GPA: 3.8).
5) The Verification: Close the file, reopen it in Read Mode (ios::in), and print the entire contents of the file to the terminal to prove the data was saved.*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

struct students{
    char name[50];
    int id;
    float gpa;
};
void add(students student[] , bool array[] , int size, fstream &myFile);
void remove(students student[] , bool array[] , int size);
void display(students student[] , int size , bool array[]);
int tracker(bool array[] , int size);
void printFile(fstream &myFile);

void menu(){
    cout << endl<<endl;
    cout << "What are we upto today?\n";
    cout << "1) Add student\n";
    cout << "2) Delete data\n";
    cout << "3) Display all students data\n";
    cout << "4) Press 0 to exit\n";
    cout << "Enter your choice here : ";
    
}


int main(){
    students student[3];
    fstream myFile("database.txt" , ios::in|ios::app);
    bool array[3] ;
    fill_n(array , 3 , true);
    int choice = 4;
    while (choice != 0){
        menu();
        cin >> choice;
        if (choice == 0) break;
        else if (choice == 1) add(student , array , 3 , myFile);
        else if (choice == 2) remove(student , array , 3);
        else if (choice == 3) display(student , 3 , array);
        cout <<endl<<"--------------------------------------"<<endl;
    }

    cout << "File contents : \n";
    myFile.close();
    printFile(myFile);

}

void add(students student[] , bool array[] , int size , fstream &myFile){
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
    myFile<< setw(10)<<left<<"Name : "<<student[i].name<<" | "<< setw(10)<<left<<"ID no. : "<<student[i].id<<" | "<< setw(10)<<left<<"GPA : "<<student[i].gpa<<endl;
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

void printFile(fstream &myFile){
    myFile.open("database.txt" , ios::in);
    myFile.seekg(0L , ios::beg);
    while (!myFile.eof()){

        char array[100];
        myFile.getline(array , 100);
        cout << array;
    }
    myFile.close();
}