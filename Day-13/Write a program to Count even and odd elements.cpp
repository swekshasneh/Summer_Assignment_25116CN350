#include <iostream>
using namespace std;

int main()
{
    int arr[100], n;
    int evenCount = 0, oddCount = 0;

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    cout << "Number of even elements = " << evenCount << endl;
    cout << "Number of odd elements = " << oddCount << endl;

    return 0;
}