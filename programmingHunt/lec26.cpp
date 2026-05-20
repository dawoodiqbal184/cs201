#include <iostream>
using namespace std;


class Account{
    private:
        int pin;
        double balance;

    public:

        char accountNo[15];
        void deposit(double amount);
        void withdraw(int pin , double balance);
        void print();


    Account(int pin, double balance){
        this->pin = pin;
        this->balance = balance;
    }
};


int main(){
   Account a = Account(1234, 500.0); //creating new acc
    a.print(); // printing status
    a.deposit(100); //depositing 100 rupees
    a.print(); // printing status
    a.withdraw(1234, 1000); // try to withdraw amount > balance
    a.withdraw(2345, 200); // try to withdraw with wrong pin
    a.withdraw(1234, 200);  // try to withdraw normal
    a.print();  // printing status
}

void Account::print(){
        cout << "Balance: " << this->balance << endl << "Pin: " << "****" << endl;
}

void Account::deposit(double amount){
    Account::balance += amount;
}

void Account::withdraw(int pin , double amount){
    if (pin == Account::pin){
        if (amount <= Account::balance) {
            Account::balance -= amount;
            cout << "Transaction successfull!\n"<<"New Balance : "<<Account::balance<<endl;
        }
        else cout << "Insufficient funds!\n";
    }
    else cout << "Incorrect Pin!\n";
}



