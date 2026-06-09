#include <iostream>
using namespace std;

int main() {
    for (char ch = 'A'; ch <= 'E'; ch++) {
        for (int i = 0; i < (ch - 'A' + 1); i++) {
            cout << ch;
        }
        cout << endl;
    }
    return 0;
}