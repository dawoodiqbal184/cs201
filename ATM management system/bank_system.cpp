#include <iostream>
#include <string>
#include <iomanip>
#include<limits>
using namespace std;
enum class status{ACTIVE , INACTIVE};
struct Account{
    string name;
    int accountNumber;
    double balance;
    status accountStatus;
};
const int x = 10;
Account accounts[x];


void menu(){
    for (int i = 0 ; i < 30 ;i++)cout << "-";
    cout << endl<<endl;
    cout << " ----- WELCOME TO OUR BANK -----\n";
    cout << "1) Open new account\n";
    cout << "2) Update existing account\n";
    cout << "4) Print details of an account\n";
    cout << "5) List details of all acounts\n";
    cout << "Press 0 to exit menu\n";
    for (int i = 0 ; i < 30 ;i++)cout << "-";
    cout << endl;
    cout << "Enter your choice : ";
}


int slotFinder(Account accounts[]){
    int y;
    for (int i = 0 ; i < x ; i++){
        if (accounts[i].name == ""){
            y = i;
            break;
        }
    }
return y;
}


Account create(){
    Account account;
    cin.ignore();
    cin.clear();
    cout << "Enter customer name\n";
    getline(cin , account.name);
    cout << "Assign user an account number\n";
    cin >> account.accountNumber;
    cout << "Enter the initial balance\n";
    cin >> account.balance;
    account.accountStatus = status::ACTIVE;
    cout << endl<<endl;
    cout << "New account created\n";
    cout << "Account holder name : "<< account.name<<endl;
    cout << "Account number : "<<account .accountNumber<<endl;
    cout << "Balance : "<<account.balance<<endl;
return account;
}


void createAccount(Account accounts[]){
    int y = slotFinder(accounts);
    accounts[y] = create();
}

int findAccount(Account accounts[]){
    string user;
    int y;
    cin.ignore();
    cout << "Enter user name to find account\n";
    getline(cin , user);
    for (int i = 0 ; i < x ; i++){
        if (user == accounts[i].name) {
            y = i;
            break;
        }
    }
return y;
}

string statusPrint(Account account){
    status s = account.accountStatus;
    string r;
    switch(s){
        case status::INACTIVE : r = "Inactive";
        case status::ACTIVE : r = "Active";
        break;
    }
    return r;
}


void printAccount(Account account){
    cout << "Account holder name : "<< account.name<<endl;
    cout << "Account number : "<< account.accountNumber<<endl;
    cout << "Balance : "<< account.balance<<endl;
    cout << "Account status : "<< statusPrint(account)<<endl;
}

status changeStatus(Account account){
    int choice;
    status a = status::ACTIVE;
    status b = status::INACTIVE;
    status r;
    cout << "You want this account : \n1)Active\t2)Inactive\nEnter your choice : \n";
    cin >> choice;
    if (choice == 1) r = a;
    else if(choice == 2) r = b;
    return r;
}


Account update(Account account){
    string n;
    printAccount(account);
    int choice;
    status s;
    cin.clear();
    cout << endl;
    cout << "Enter the new balance of account\n";
    cin >> account.balance;
    cout <<"Do want to change account status also?\n1)Yes\t2)No\n";
    cin >> choice;
    if (choice == 1) s = changeStatus(account);
    if (choice == 2) n = statusPrint(account);
    account.accountStatus = s;
    return account;
}

void updateAccount(Account accounts[]){
    
    int x = findAccount(accounts);
    cout << endl;
    accounts[x] = update(accounts[x]);
    printAccount(accounts[x]);
    cout << endl;
}

void continueCode(){
    cout << "Press enter to move back to main menu\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void exit(){
    cout << "All desirable changes are done\n";
    cout << "Thank you! for using our system another day\n";
}
int main (){
    int choice = 6;
    while (choice != 0){
        menu();
        cin >> choice;
        if (choice == 1){
            createAccount(accounts);
            continueCode;
        }
        else if (choice == 2){
            updateAccount(accounts);
        }
        else if (choice == 3){
            int x = findAccount(accounts);
            printAccount(accounts[x]);
            continueCode;
        }
        else if(choice == 4){
            for ( int i = 0 ; i < x ; i++){
                if (accounts[i].name != ""){
                    printAccount(accounts[i]);
                }
            }
            continueCode;
        }
        else if (choice == 5){
            exit();
            break;
        }
        
    }

}