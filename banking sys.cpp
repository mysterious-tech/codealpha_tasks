//banking system
#include <iostream>
using namespace std;

class Customer {
public:
    string name;
    int customerID;

    Customer(string n = "Unknown", int id = 0) {
        name = n;
        customerID = id;
    }
};

class Account {
public:
    int accountNumber;
    double balance;
    Customer owner;

    Account(int accNo, Customer c, double bal = 0) : owner(c) {
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " successfully! New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Error: Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn " << amount << " successfully! New Balance: " << balance << endl;
        }
    }

    void displayInfo() {
        cout << "\n--- Account Info ---\n";
        cout << "Customer Name: " << owner.name << endl;
        cout << "Customer ID: " << owner.customerID << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void showTransaction() {
        cout << type << " of " << amount << endl;
    }
};

int main() {
    string name;
    int custID, accNo;
    double initialBalance;

    cout << "Enter Customer Name: ";
    cin >> name;
    cout << "Enter Customer ID: ";
    cin >> custID;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    Customer c1(name, custID);
    Account acc1(accNo, c1, initialBalance);

    int choice;
    double amount;

    while (true) {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Show Account Info\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc1.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc1.withdraw(amount);
                break;

            case 3:
                acc1.displayInfo();
                break;

            case 4:
                cout << "Exiting Banking System. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

