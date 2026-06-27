#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    int choice, len = 0;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    do {
        cout << "\n----- Menu Driven String Operations -----";
        cout << "\n1. Find Length";
        cout << "\n2. Reverse String";
        cout << "\n3. Convert to Uppercase";
        cout << "\n4. Display String";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                len = strlen(str);
                cout << "Length = " << len << endl;
                break;

            case 2:
                cout << "Reversed String: ";
                for (int i = strlen(str) - 1; i >= 0; i--)
                    cout << str[i];
                cout << endl;
                break;

            case 3:
                for (int i = 0; str[i] != '\0'; i++) {
                    if (str[i] >= 'a' && str[i] <= 'z')
                        str[i] = str[i] - 32;
                }
                cout << "Uppercase String: " << str << endl;
                break;

            case 4:
                cout << "String: " << str << endl;
                break;

            case 5:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}