#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char names[10][50], temp[50];
    int n;

    cout << "Enter number of names: ";
    cin >> n;
    cin.ignore();

    cout << "Enter names:\n";
    for (int i = 0; i < n; i++) {
        cin.getline(names[i], 50);
    }

    // Sorting names alphabetically
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    cout << "\nNames in Alphabetical Order:\n";
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }

    return 0;
}