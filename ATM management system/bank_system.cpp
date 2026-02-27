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
    cout << "2) Update balance of existing account\n";
    cout << "3) Delete an account\n";
    cout << "4) Print details of an account\n";
    cout << "5) List details of all acounts\n";
    cout << "Press 0 to exit menu\n";
}
Account createAccount(Account accounts[]){
    int y;
    for (int i = 0 ; i < x ; i++){
        if (accounts[i].name == ""){
            y = i;
            break;
        }
    }
    cin.ignore();
    cin.clear();
    cout << "Enter customer name\n";
    getline(cin , accounts[y].name);
    cout << "Assign user an account number\n";
    cin >> accounts[y].accountNumber;
    cout << "Enter the initial balance\n";
    cin >> accounts[y].balance;
    accounts[y].accountStatus = status::ACTIVE;
    return accounts[y];
}


Account findAccount(Account accounts[]){
    string user;
    cout << "Enter user name to find account\n";
    getline(cin , user);
    for (int i = 0 ; i < x ; i++){
        if (accounts[i].name != ""){
            if (user == accounts[i].name) return accounts[i];
        }
    }
}


void printAccount(Account account){
    account = findAccount(accounts);
    cout << "Account holder name : "<< account.name<<endl;
    cout << "Account number : "<< account.accountNumber<<endl;
    cout << "Balance : "<< account.balance<<endl;
    cout << "Account status : ";
    account.accountStatus = status::ACTIVE;
}
Account updateAccount(Account account){
    account = findAccount(accounts);
    printAccount(account);
    cout << "Enter the new balance of account\n";
    cin >> account.balance;
    return account;
}
int main (){
    int choice = 6;
    while (choice != 0){
        menu();
        cin >> choice;
        if (choice == 1){
            createAccount(accounts);
        }
        else if(choice == 4){
            Account acc = findAccount(accounts);
            printAccount(acc);
        }
        
    }

}