#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    string id;
    string name;
    int age;
    string department;
    float gpa;
    bool used = false;
};

void addStudent(Student arr[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "Record full. Cannot add more students.\n";
        return;
    }
    int idx = -1;
    for (int i = 0; i < MAX_STUDENTS; ++i) if (!arr[i].used) { idx = i; break; }
    if (idx == -1) return;

    cout << "Enter student ID: ";
    getline(cin, arr[idx].id);
    cout << "Enter name: ";
    getline(cin, arr[idx].name);
    cout << "Enter age: ";
    cin >> arr[idx].age; cin.ignore();
    cout << "Enter department: ";
    getline(cin, arr[idx].department);
    cout << "Enter GPA: ";
    cin >> arr[idx].gpa; cin.ignore();
    arr[idx].used = true;
    count++;
    cout << "Student added.\n";
}

void displayAll(const Student arr[]) {
    cout << left << setw(12) << "ID" << setw(20) << "Name" << setw(6) << "Age" << setw(15) << "Department" << setw(6) << "GPA" << '\n';
    cout << string(59, '-') << '\n';
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (!arr[i].used) continue;
        cout << left << setw(12) << arr[i].id << setw(20) << arr[i].name << setw(6) << arr[i].age << setw(15) << arr[i].department << setw(6) << fixed << setprecision(2) << arr[i].gpa << '\n';
    }
}

int findById(const Student arr[], const string &id) {
    for (int i = 0; i < MAX_STUDENTS; ++i) if (arr[i].used && arr[i].id == id) return i;
    return -1;
}

void searchStudent(const Student arr[]) {
    string id; cout << "Enter ID to search: "; getline(cin, id);
    int idx = findById(arr, id);
    if (idx == -1) { cout << "Student not found.\n"; return; }
    cout << "Found: " << arr[idx].name << ", Age " << arr[idx].age << ", Dept " << arr[idx].department << ", GPA " << fixed << setprecision(2) << arr[idx].gpa << "\n";
}

void updateStudent(Student arr[]) {
    string id; cout << "Enter ID to update: "; getline(cin, id);
    int idx = findById(arr, id);
    if (idx == -1) { cout << "Student not found.\n"; return; }
    cout << "Enter new name (leave empty to keep): ";
    string s; getline(cin, s); if (!s.empty()) arr[idx].name = s;
    cout << "Enter new age (0 to keep): "; int a; cin >> a; cin.ignore(); if (a>0) arr[idx].age = a;
    cout << "Enter new department (leave empty to keep): "; getline(cin, s); if (!s.empty()) arr[idx].department = s;
    cout << "Enter new GPA (-1 to keep): "; float g; cin >> g; cin.ignore(); if (g >= 0.0f) arr[idx].gpa = g;
    cout << "Updated.\n";
}

void deleteStudent(Student arr[], int &count) {
    string id; cout << "Enter ID to delete: "; getline(cin, id);
    int idx = findById(arr, id);
    if (idx == -1) { cout << "Student not found.\n"; return; }
    arr[idx].used = false; count--; cout << "Deleted.\n";
}

void sortByName(Student arr[]) {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (!arr[i].used) continue;
        for (int j = i+1; j < MAX_STUDENTS; ++j) {
            if (!arr[j].used) continue;
            if (arr[j].name < arr[i].name) swap(arr[i], arr[j]);
        }
    }
    cout << "Sorted by name.\n";
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    while (true) {
        cout << "\nStudent Record System\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Sort by name 7.Exit\nChoose: ";
        int choice; if (!(cin >> choice)) break; cin.ignore();
        switch (choice) {
            case 1: addStudent(students, count); break;
            case 2: displayAll(students); break;
            case 3: searchStudent(students); break;
            case 4: updateStudent(students); break;
            case 5: deleteStudent(students, count); break;
            case 6: sortByName(students); break;
            case 7: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
    return 0;
}
