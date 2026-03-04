#include <iostream>
#include <string>
#include <iomanip>
#include<limits>
using namespace std;
enum class status{INACTIVE , ACTIVE};
struct Account{
    string name;
    int accountNumber;
    double balance;
    status accountStatus;
};
const int x = 10;
Account accounts[x];


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


int slotFinder(Account accounts[]){
    for (int i = 0 ; i < x ; i++ ){
        if (accounts[i].name == ""){
            return i;
        }
    }
return -1;
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
    if (y == -1){
        cout << "Unfortunately, we are out of limit, can not open another account!\n";
        return;
    }
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
    int a = static_cast<int>(account.accountStatus) ;
    string r;
    switch(a){
        case 0 : return "Inactive";
        case 1 : return "Active";
        break;
    }
return;
}


void printAccount(Account account){
    cout << "Account holder name : "<< account.name<<endl;
    cout << "Account number : "<< account.accountNumber<<endl;
    cout << "Balance : "<< account.balance<<endl;
    cout << "Account status : "<< statusPrint(account)<<endl;
}

status changeStatus(Account account){
    int choice;
    int a = static_cast<int>(account.accountStatus);
    status r;
    cout << "You want this account : \n1)Active\t2)Inactive\nEnter your choice : \n";
    cin >> choice;
    switch(choice){
        case 1 : return status::ACTIVE;
        case 2 : return status::INACTIVE;
        default : break;
    }
return ;
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
            cout << "Press enter to move back to main menu\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        else if (choice == 2){
            updateAccount(accounts);
            cout << "Press enter to move back to main menu\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        else if (choice == 3){
            int x = findAccount(accounts);
            printAccount(accounts[x]);
            cout << "Press enter to move back to main menu\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        else if(choice == 4){
            for ( int i = 0 ; i < x ; i++){
                if (accounts[i].name != ""){
                    printAccount(accounts[i]);
                }
            }
            cout << "Press enter to move back to main menu\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        else if (choice == 0){
            exit();
            break;
        }
        
    }

}