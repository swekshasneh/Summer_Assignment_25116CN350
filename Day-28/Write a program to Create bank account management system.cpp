#include <iostream>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    float balance;

public:
    void createAccount() {
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount Deposited Successfully.\n";
    }

    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully.\n";
        } else {
            cout << "Insufficient Balance.\n";
        }
    }

    void display() {
        cout << "\n----- Account Details -----\n";
        cout << "Account Holder : " << name << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }
};

int main() {
    BankAccount account;
    int choice;

    account.createAccount();

    do {
        cout << "\n----- Bank Account System -----";
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Display Account Details";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.deposit();
                break;
            case 2:
                account.withdraw();
                break;
            case 3:
                account.display();
                break;
            case 4:
                cout << "Thank You!";
                break;
            default:
                cout << "Invalid Choice!";
        }

    } while (choice != 4);

    return 0;
}