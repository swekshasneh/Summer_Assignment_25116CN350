#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 2, 4, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array after removing duplicates: ";

    for (int i = 0; i < n; i++) {
        bool duplicate = false;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                duplicate = true;
                break;
            }
        }

        if (!duplicate) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}