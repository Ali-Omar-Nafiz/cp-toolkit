#include <bits/stdc++.h>
using namespace std;

int main() {
    // -------------------------------
    // 1. Frequency Array
    // -------------------------------
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " numbers (range 0-9 for demo):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // frequency array
    vector<int> freq(10, 0); // size 10, initialized with 0
    for (int val : arr) {
        freq[val]++;
    }

    cout << "\nFrequencies:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << " -> " << freq[i] << endl;
    }

    // -------------------------------
    // 2. Grid (2D array / matrix)
    // -------------------------------
    int rows, cols;
    cout << "\nEnter rows and columns of grid: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Enter grid elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "\nGrid is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    // Example: Sum of all elements
    int totalSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            totalSum += grid[i][j];
        }
    }
    cout << "\nSum of all grid elements = " << totalSum << endl;

    // Example: Count how many times '5' appears in the grid
    int count5 = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 5) count5++;
        }
    }
    cout << "Number of times 5 appears in grid = " << count5 << endl;

    return 0;
}
