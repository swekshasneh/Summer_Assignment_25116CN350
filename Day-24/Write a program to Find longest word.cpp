#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[200], longest[100];
    int maxLen = 0, len = 0, start = 0;

    cout << "Enter a sentence: ";
    cin.getline(str, 200);

    for (int i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            len++;
        } else {
            if (len > maxLen) {
                maxLen = len;

                for (int j = 0; j < len; j++) {
                    longest[j] = str[start + j];
                }
                longest[len] = '\0';
            }

            len = 0;
            start = i + 1;
        }

        if (str[i] == '\0')
            break;
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << maxLen;

    return 0;
}