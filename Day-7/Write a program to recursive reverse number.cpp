#include <iostream>
using namespace std;

int ReverseNumber(int n, int rev = 0)
{
    if (n == 0)
        return rev;

    return ReverseNumber(n / 10, rev * 10 + n % 10);
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Reversed number = " << ReverseNumber(num) << endl;
    return 0;
}