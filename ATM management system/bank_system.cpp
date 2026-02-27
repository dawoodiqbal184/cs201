#include <iostream>
#include <string>
#include <iomanip>
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
    cout << "1) Open new account\n";
    cout << "2) Update existing account\n";
    cout << "4) Print details of an account\n";
    cout << "5) List details of all acounts\n";
    cout << "Press 0 to exit menu\n";
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
return account;
}


void createAccount(Account accounts[]){
    int y = slotFinder(accounts);
    accounts[y] = create();
}

int findAccount(Account accounts[]){
    string user;
    int y;
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
    switch(s){
        case status::ACTIVE : return "Active";
        case status::INACTIVE : return "Inactive";
    }
}


void printAccount(Account account){
    cout << "Account holder name : "<< account.name<<endl;
    cout << "Account number : "<< account.accountNumber<<endl;
    cout << "Balance : "<< account.balance<<endl;
    cout << "Account status : "<< statusPrint(account);
}

status changeStatus(Account account){
    int choice;
    status a = status::ACTIVE;
    status b = status::INACTIVE;
    cout << "You want this account : \n1)Active\t2)Inactive\nEnter your choice : \n";
    cin >> choice;
    switch(choice){
        case 1 : return a;
        case 2 : return b;
    }
}


Account update(Account account){
    printAccount(account);
    int choice;
    status s;
    cout << "Enter the new balance of account\n";
    cin >> account.balance;
    cout <<"Do want to change account status also?\n1)Yes\t2)No\n";
    cin >> choice;
    switch(choice){
        case 1 :  s = changeStatus(account);
    }
    account.accountStatus = s;
    return account;
}

void updateAccount(Account accounts[]){
    int x = findAccount(accounts);
    printAccount(accounts[x]);
    accounts[x] = update(accounts[x]);
    printAccount(accounts[x]);
}


int main (){
    int choice = 6;
    while (choice != 0){
        menu();
        cin >> choice;
        if (choice == 1){
            createAccount(accounts);
        }
        else if (choice == 2){
            updateAccount(accounts);
        }
        else if (choice == 3){
            int x = findAccount(accounts);
            printAccount(accounts[x]);
        }
        else if(choice == 4){
            for ( int i = 0 ; i < x ; i++){
                if (accounts[i].name != ""){
                    printAccount(accounts[i]);
                }
            }
        }
        
    }

}