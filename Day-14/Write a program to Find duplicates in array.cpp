#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Duplicate elements are: ";

    bool found = false;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

    
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate)
            continue;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                found = true;
                break;
            }
        }
    }

    if (!found)
        cout << "No duplicates found.";

    cout << endl;

    return 0;
}