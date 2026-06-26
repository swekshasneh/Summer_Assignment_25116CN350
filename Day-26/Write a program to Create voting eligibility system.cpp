#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "\n--- Voting Eligibility System ---\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;

    if (age >= 18)
        cout << "You are eligible to vote.";
    else
        cout << "You are not eligible to vote.";

    return 0;
}