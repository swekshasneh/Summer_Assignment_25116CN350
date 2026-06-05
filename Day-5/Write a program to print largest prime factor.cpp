#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Enter a number: ";
    cin >> n;
    long long largestPrimeFactor = -1;

    // Divide by 2 until n becomes odd

    while (n % 2 == 0) {
        largestPrimeFactor = 2;
        n /= 2;
    }

    // Check odd factors

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largestPrimeFactor = i;
            n /= i;
        }
    }

    // If n is still greater than 2, then n itself is prime

    if (n > 2) {
        largestPrimeFactor = n;
    }
    cout << "Largest Prime Factor = " << largestPrimeFactor << endl;
    return 0;
}