#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int start, end;
    cout << "Enter the starting number: ";
    cin >> start;
    cout << "Enter the ending number: ";
    cin >> end;
    for (int num = start; num <= end; num++) {
        int temp = num, count = 0;
        int sum = 0;
        while (temp != 0) {
            count++;
            temp /= 10;
        }
        temp = num;
        while (temp != 0) {
            int digit = temp % 10;
            sum += pow(digit, count);
            temp /= 10;
        }
        if (sum == num)
            cout << num << " ";
    }
    return 0;
}