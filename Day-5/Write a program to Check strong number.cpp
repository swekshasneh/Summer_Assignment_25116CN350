#include <iostream>
using namespace std;

int main() {
    int n, temp, digit;
    int sum = 0;

    cout << "Enter a number: ";
    cin >> n;

    temp = n;

    while (temp > 0) {
        digit = temp % 10;

        // Calculate factorial of the digit
        int fact = 1;
        for (int i = 1; i <= digit; i++) {
            fact *= i;
        }

        sum += fact;
        temp /= 10;
    }

    if (sum == n)
        cout << n << " is a Strong Number." << endl;
    else
        cout << n << " is not a Strong Number." << endl;

    return 0;
}