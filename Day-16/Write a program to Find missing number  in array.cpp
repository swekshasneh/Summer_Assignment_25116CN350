#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int size, int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 6; // Numbers should be from 1 to 6

    cout << "Missing Number: " << findMissingNumber(arr, size, n) << endl;

    return 0;
}