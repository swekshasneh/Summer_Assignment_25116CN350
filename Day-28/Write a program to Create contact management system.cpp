#include <iostream>
using namespace std;

class Contact {
private:
    string name;
    string phone;
    string email;

public:
    void addContact() {
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Email: ";
        getline(cin, email);
    }

    void displayContact() {
        cout << "\n----- Contact Details -----\n";
        cout << "Name         : " << name << endl;
        cout << "Phone Number : " << phone << endl;
        cout << "Email        : " << email << endl;
    }
};

int main() {
    Contact c;

    c.addContact();
    c.displayContact();

    return 0;
}