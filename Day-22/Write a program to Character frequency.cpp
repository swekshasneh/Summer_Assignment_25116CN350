#include <iostream>
using namespace std;

int main() {
    char str[100], ch;
    int count = 0;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    cout << "Enter character to find frequency: ";
    cin >> ch;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    cout << "Frequency of '" << ch << "' = " << count;

    return 0;
}