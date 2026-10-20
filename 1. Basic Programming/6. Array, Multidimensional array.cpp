#include <bits/stdc++.h>
using namespace std;

int main() {
    // -------------------------------
    // 1. One-dimensional Array
    // -------------------------------
    cout << "One-dimensional Array example:\n";
    int arr[5] = {10, 20, 30, 40, 50}; // fixed size array
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // Input from user
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;
    int numbers[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";

    // -------------------------------
    // 2. Two-dimensional Array
    // -------------------------------
    cout << "\nTwo-dimensional Array example:\n";
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Printing 2D array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // -------------------------------
    // 3. Input in 2D array
    // -------------------------------
    int rows, cols;
    cout << "\nEnter rows and cols for a matrix: ";
    cin >> rows >> cols;
    int mat[rows][cols];

    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Matrix is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    // -------------------------------
    // 4. Example: Row sum of matrix
    // -------------------------------
    cout << "\nRow sums:\n";
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += mat[i][j];
        }
        cout << "Row " << i << " sum = " << sum << endl;
    }

    return 0;
}
