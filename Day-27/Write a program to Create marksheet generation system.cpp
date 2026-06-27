#include <iostream>
using namespace std;

class Marksheet {
private:
    string name;
    int rollNo;
    float m1, m2, m3, m4, m5;
    float total, percentage;
    char grade;

public:
    void getData() {
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter marks of 5 subjects: ";
        cin >> m1 >> m2 >> m3 >> m4 >> m5;
    }

    void calculate() {
        total = m1 + m2 + m3 + m4 + m5;
        percentage = total / 5;

        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 75)
            grade = 'B';
        else if (percentage >= 60)
            grade = 'C';
        else if (percentage >= 40)
            grade = 'D';
        else
            grade = 'F';
    }

    void display() {
        cout << "\n----- Student Marksheet -----\n";
        cout << "Name       : " << name << endl;
        cout << "Roll No.   : " << rollNo << endl;
        cout << "Total Marks: " << total << "/500" << endl;
        cout << "Percentage : " << percentage << "%" << endl;
        cout << "Grade      : " << grade << endl;
    }
};

int main() {
    Marksheet student;

    student.getData();
    student.calculate();
    student.display();

    return 0;
}