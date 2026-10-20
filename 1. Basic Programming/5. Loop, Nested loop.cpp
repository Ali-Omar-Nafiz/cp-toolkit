#include <bits/stdc++.h>
using namespace std;

int main() {
    // -------------------------------
    // For loop
    // -------------------------------
    cout << "For loop (1 to 5): ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << "\n";

    // -------------------------------
    // While loop
    // -------------------------------
    cout << "While loop (5 to 1): ";
    int x = 5;
    while (x >= 1) {
        cout << x << " ";
        x--;
    }
    cout << "\n";

    // -------------------------------
    // Do-While loop
    // -------------------------------
    cout << "Do-While loop (runs at least once): ";
    int y = 0;
    do {
        cout << y << " ";
        y++;
    } while (y < 3);
    cout << "\n";

    // -------------------------------
    // Nested loops - Multiplication table
    // -------------------------------
    cout << "\nMultiplication table (1 to 3):\n";
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << i << " x " << j << " = " << i * j << "\t";
        }
        cout << "\n";
    }

    // -------------------------------
    // Nested loops - Pattern printing
    // -------------------------------
    cout << "\nPattern (triangle of *):\n";
    int n = 5;
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << "\n";
    }

    return 0;
}
