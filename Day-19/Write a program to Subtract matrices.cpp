#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int A[10][10], B[10][10], Diff[10][10];

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> B[i][j];
        }
    }

    // Matrix Subtraction
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Diff[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "Difference of Matrices:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << Diff[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}