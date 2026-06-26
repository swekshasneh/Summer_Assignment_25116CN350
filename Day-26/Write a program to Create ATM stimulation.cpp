#include <iostream>
using namespace std;

class ATM {
private:
    int pin = 1234;
    float balance = 10000;

public:
    void login() {
        int userPin;
        cout << "Enter ATM PIN: ";
        cin >> userPin;

        if (userPin != pin) {
            cout << "Incorrect PIN! Access Denied.";
            return;
        }

        int choice;
        float amount;

        do {
            cout << "\n\n----- ATM Menu -----";
            cout << "\n1. Check Balance";
            cout << "\n2. Deposit Money";
            cout << "\n3. Withdraw Money";
            cout << "\n4. Exit";
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Current Balance: ₹" << balance << endl;
                    break;

                case 2:
                    cout << "Enter amount to deposit: ₹";
                    cin >> amount;
                    balance += amount;
                    cout << "Deposit Successful.\n";
                    break;

                case 3:
                    cout << "Enter amount to withdraw: ₹";
                    cin >> amount;

                    if (amount <= balance) {
                        balance -= amount;
                        cout << "Withdrawal Successful.\n";
                    } else {
                        cout << "Insufficient Balance.\n";
                    }
                    break;

                case 4:
                    cout << "Thank You for using the ATM!";
                    break;

                default:
                    cout << "Invalid Choice!";
            }

        } while (choice != 4);
    }
};

int main() {
    ATM atm;
    atm.login();

    return 0;
}