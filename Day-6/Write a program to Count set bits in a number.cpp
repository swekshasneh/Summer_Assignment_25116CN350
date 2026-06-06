#include <iostream>
using namespace std;

int main() {
    int num, count = 0;
    cout << "Enter a number: ";
    cin >> num;
    while (num > 0) {
        count += num & 1;
        num = num >> 1;
    }
    cout << "Number of set bits = " << count;
    return 0;
}