#include <iostream>
using namespace std;

// Recursive function to calculate sum of digits
int sumofdigits(int n)
{
    if (n == 0)
        return 0;

    return (n % 10) + sumofdigits(n / 10);
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Sum of digits = " << sumofdigits(num) << endl;
    return 0;
}