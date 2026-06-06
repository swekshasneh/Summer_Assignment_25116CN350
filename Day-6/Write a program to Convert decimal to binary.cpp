#include <iostream>
using namespace std;

int main() {
    int num, binary[32], i = 0;
    cout << "Enter a decimal number: ";
    cin >> num;
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    cout << "Binary equivalent: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }
    return 0;
}