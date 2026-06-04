#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a = 0, b = 1, next;
    if (n == 0)
        cout << "Nth Fibonacci term = 0";
    else if (n == 1)
        cout << "Nth Fibonacci term = 1";
    else {
        for (int i = 2; i <= n; i++) {
            next = a + b;
            a = b;
            b = next;
        }
        cout << "Nth Fibonacci term = " << b;
    }
    return 0;
}