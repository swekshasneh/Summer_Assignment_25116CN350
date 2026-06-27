#include <iostream>
using namespace std;

class Employee {
private:
    int empID;
    string name;
    string department;
    float salary;

public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayData() {
        cout << "\n----- Employee Details -----\n";
        cout << "Employee ID : " << empID << endl;
        cout << "Name        : " << name << endl;
        cout << "Department  : " << department << endl;
        cout << "Salary      : ₹" << salary << endl;
    }
};

int main() {
    Employee emp;

    emp.getData();
    emp.displayData();

    return 0;
}