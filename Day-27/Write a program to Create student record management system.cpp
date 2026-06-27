#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    string course;
    float marks;

public:
    void getData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayData() {
        cout << "\n----- Student Record -----\n";
        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
        cout << "Course      : " << course << endl;
        cout << "Marks       : " << marks << endl;

        if (marks >= 40)
            cout << "Result      : Pass" << endl;
        else
            cout << "Result      : Fail" << endl;
    }
};

int main() {
    Student s;

    s.getData();
    s.displayData();

    return 0;
}