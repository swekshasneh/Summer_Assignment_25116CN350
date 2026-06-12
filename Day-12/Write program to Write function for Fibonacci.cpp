#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;

    cout << "Enter the position (n): ";
    cin >> n;

    cout << "Fibonacci number at position " << n
         << " is " << fibonacci(n) << endl;

    return 0;
}