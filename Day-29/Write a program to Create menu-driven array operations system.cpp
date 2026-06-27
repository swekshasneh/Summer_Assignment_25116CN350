#include <iostream>
using namespace std;

int main() {
    int arr[100], n, choice, i;
    int sum = 0, max, min;

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n----- Menu Driven Array Operations -----";
        cout << "\n1. Display Array";
        cout << "\n2. Find Sum";
        cout << "\n3. Find Maximum";
        cout << "\n4. Find Minimum";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Array Elements: ";
                for (i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
                break;

            case 2:
                sum = 0;
                for (i = 0; i < n; i++)
                    sum += arr[i];
                cout << "Sum = " << sum << endl;
                break;

            case 3:
                max = arr[0];
                for (i = 1; i < n; i++)
                    if (arr[i] > max)
                        max = arr[i];
                cout << "Maximum Element = " << max << endl;
                break;

            case 4:
                min = arr[0];
                for (i = 1; i < n; i++)
                    if (arr[i] < min)
                        min = arr[i];
                cout << "Minimum Element = " << min << endl;
                break;

            case 5:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}