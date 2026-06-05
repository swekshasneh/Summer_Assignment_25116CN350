#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n)
        cout << n << " is a Perfect Number." << endl;
    else
        cout << n << " is not a Perfect Number." << endl;
    return 0;
}