#include <iostream>
using namespace std;

int main()
{
    int arr[100], n;
    int sum = 0;
    float avg;

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    avg = (float)sum / n;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << avg << endl;

    return 0;
}