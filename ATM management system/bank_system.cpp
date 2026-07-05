#include <iostream>
#include <string>
#include <iomanip>
#include<limits>
#include <fstream>
using namespace std;


struct Account{
    char name[30];
    int accountNumber;
    double balance;
};


// FUNCTION PROTOTYPES -------------------------------------
void menu();
int getValidInteger();
int countData(fstream& data);
Account* createArray(int size , int fileAccounts);
Account* loadData(fstream& data , int &size);
int slotFinder(Account *accounts ,int &size);
Account create();
void createAccount(Account *&accounts , int &size);
Account* grow(Account *arr , int &size);
int findAccount(Account *accounts , int size);
void printAccount(Account account);
Account update(Account account);
void updateAccount(Account *accounts , int size);
void saveFile(Account *accounts , int size , fstream &output);
void arrCopy(Account* heap , Account* file , int fileAccounts);
void exit();


// the main function
int main (){
    fstream data{"bankData.txt" , ios::in | ios::out};
    cout<< "Enter how many accounts you want to create initially\n";
    int size = getValidInteger();
    int fileAccounts = (countData(data));
    if (fileAccounts > 0) {
        fileAccounts -= 1; 
    }

    

    Account *accounts = createArray(size , fileAccounts);
    arrCopy(accounts , loadData(data , fileAccounts) , fileAccounts);
    int choice = 6;
    while (choice != 0){
        menu();
        choice = getValidInteger();
        cin.clear();
        if (choice == 1){
            createAccount(accounts , size);
            
            cout << "Press enter to move back to main menu\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        else if (choice == 2){
            updateAccount(accounts , size);
            cout << "Press enter to move back to main menu\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        else if (choice == 3){
            int x = findAccount(accounts , size);
            if (x != -1) {  
                printAccount(accounts[x]);
            }
            cout << "Press enter to move back to main menu\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cin.get();
        }
        else if(choice == 4){
            for ( int i = 0 ; i < (size+fileAccounts) ; i++){
                if (accounts[i].name[0] != '\0'){
                    printAccount(accounts[i]);
                }
            }
            cout << "Press enter to move back to main menu\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        else if (choice == 0){
            saveFile(accounts , size , data);
            exit();
            delete[] accounts;
            break;
        }
        else {
            cout << "Enter a valid choice!\n";
            continue;
        }
        
    }

}

// functions displays main menu-------------------------------------------------
void menu(){
    cout << "----------------------------------" << endl
         << "------ WELCOME TO OUR BANK -------\n"
         << "1) Open new account\n"
         << "2) Update existing account\n"
         << "3) Print details of an account\n"
         << "4) List details of all acounts\n"
         << "Press 0 to exit menu\n"
         << "----------------------------------" << endl
         << "Enter your choice : ";
}

// Function that will create the array of accounts---------------------------------------------
Account* createArray(int size, int fileAccounts) {
    Account* array = new Account[(size + fileAccounts)](); 
    return array;
}


// function finds empty slot for an account----------------------------------------
int slotFinder(Account *accounts , int &size){
    for (int i = 0 ; i < size ; i++ ){
        if (accounts[i].name[0] == '\0') return i;
    }
return -1;
}
// functions creates the account-------------------------------------------------
Account create(){
    Account account;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
    cout << "Enter customer name\n";
    cin.getline(account.name , 30);
    cout << "Assign user an account number\n";
    account.accountNumber = getValidInteger();
    cout << "Enter the initial balance\n";
    account.balance = getValidInteger();
    cout << endl<<endl;
    cout << "New account created\n";
    cout << "Account holder name : "<< account.name<<endl;
    cout << "Account number : "<<account .accountNumber<<endl;
    cout << "Balance : "<<account.balance<<endl;

return account;
}

//function puts the account in array----------------------------------------------
void createAccount(Account *&accounts ,int &size){
   int y = slotFinder(accounts , size);
    if (y == -1){
        accounts = grow(accounts , size);
        accounts[size - 1] = create();
    }
    else accounts[y] = create();
}

// Function that will grow the size of array--------------------------------------------
Account* grow(Account *arr , int &size){
    
    Account *arr2 = new Account[size + 1]();
    for (int i = 0; i < size; i++) arr2[i] = arr[i];
    delete [] arr;
    arr = arr2;
    size += 1;
 return arr;
}

// function that will find account for modification or printing details----------- 
int findAccount(Account *accounts , int size){
    int y;
    cin.clear();
    cout << "Enter user account number to find account\n";
    cin>> y;
    int i;
    for (i = 0 ; i < size ; i++){
        if (y == accounts[i].accountNumber) {
            return i;
        }
    }
    if(i == size) cout << "Account does not exist \n";
 return -1;
}

// function that prints the details of an account ----------------------------------
void printAccount(Account account){
    cout << "Account holder name : "<< account.name<<endl;
    cout << "Account number : "<< account.accountNumber<<endl;
    cout << "Balance : "<< account.balance<<endl;

}


//function that will update status and balance of account -----------------------------
Account update(Account account){
    string n;
    printAccount(account);
    int choice;
    cin.clear();
    cout << endl;
    cout << "Enter the new balance of account\n";
    cin >> account.balance;
return account;
}

// function that will aligns the updated account with accounts array ------------------
void updateAccount(Account *accounts , int size){
    
    int x = findAccount(accounts , size);
    if (x != -1) { 
        cout << endl;
        accounts[x] = update(accounts[x]);
        cout << "Update Successful!\n";
        printAccount(accounts[x]);
        cout << endl;
    }
}

// function that will display the exit menu ---------------------------------------------
void exit(){
    cout << "All desirable changes are done\n";
    cout << "Thank you! for using our system another day\n";
}


void saveFile(Account *accounts ,int size , fstream &output){
    output.close();
    output.open("bankData.txt", ios::out | ios::trunc);
    output << "Account,Name,Balance\n"; 
    for (int i = 0 ; i < size ; i++){
        if (accounts[i].name[0] != '\0'){
            output << accounts[i].accountNumber << "," 
                   << accounts[i].name << "," 
                   << accounts[i].balance << endl;
        }
    }
    output.close();
    cout << "Data Successfully saved in the file.\n";
}

int getValidInteger(){
    int validNumber;
    while (true) {
        cin >> validNumber;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Invalid input! Please enter your choice again: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            return validNumber; 
        }
    }
}

int countData(fstream& data){
    int count = 0;
    char ch ;
    if(!data.is_open()){
        cout << "The file does not exists yet!\nCreate one to start saving accounts\n";
    }
    else{
        string dummyHeader;
        getline(data, dummyHeader);    
        while(!data.eof()){
            data.get(ch);
            if (ch == '\n') count++;
        }
    }
 return count;
}

Account* loadData(fstream& data , int &size){
    if (size <= 0) {
        return nullptr;
    }
    
    // Added () to zero-initialize the memory safely!
    Account *temp = new Account[size](); 
    
    data.close();
    data.open("bankData.txt");
    
    if(!data.is_open()){
        cerr << "Error to open file for loading data\n";
        return nullptr;
    }
    else{
        string dummyHeader;
        getline(data, dummyHeader); 
        for(int i = 0 ; i < size ; i++){
            data >> temp[i].accountNumber;
            data.ignore(numeric_limits<streamsize>::max(), ','); 
            data.getline(temp[i].name, 30, ','); 
            data >> temp[i].balance;
        }
    }
 return temp;
}

void arrCopy(Account* heap , Account* file , int fileAccounts){
    if (file == nullptr) return;
    for(int i = 0 ; i < fileAccounts ; i++) heap[i] = file[i];
    delete[] file;
}