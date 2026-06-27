#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int empID;
    float basicSalary, hra, da, grossSalary;

public:
    void getData() {
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Employee ID: ";
        cin >> empID;

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }

    void calculateSalary() {
        hra = basicSalary * 0.20;   // 20% HRA
        da = basicSalary * 0.10;    // 10% DA
        grossSalary = basicSalary + hra + da;
    }

    void display() {
        cout << "\n--- Salary Details ---\n";
        cout << "Employee Name : " << name << endl;
        cout << "Employee ID   : " << empID << endl;
        cout << "Basic Salary  : " << basicSalary << endl;
        cout << "HRA           : " << hra << endl;
        cout << "DA            : " << da << endl;
        cout << "Gross Salary  : " << grossSalary << endl;
    }
};

int main() {
    Employee emp;

    emp.getData();
    emp.calculateSalary();
    emp.display();

    return 0;
}