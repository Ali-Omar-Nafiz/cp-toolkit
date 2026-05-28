#include <bits/stdc++.h>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    cout << "Enter two points (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Equation of line: (y - y1) = m * (x - x1)
    // => y = m*x + c
    double m, c;
    if (x1 == x2) {
        cout << "Vertical line: x = " << x1 << "\n";
    } else {
        m = (y2 - y1) / (x2 - x1);
        c = y1 - m * x1;

        cout << "Equation of line: y = " << m << "x + " << c << "\n";
    }

    // Check if a third point lies on the line
    double x, y;
    cout << "Enter point to check (x y): ";
    cin >> x >> y;

    bool onLine = false;

    if (x1 == x2) {
        // For vertical line, x must be same
        if (x == x1) onLine = true;
    } else {
        // Substitute in line equation: y ?= m*x + c
        if (fabs(y - (m * x + c)) < 1e-9) onLine = true;
    }

    if (onLine)
        cout << "The point (" << x << ", " << y << ") lies on the line.\n";
    else
        cout << "The point (" << x << ", " << y << ") does NOT lie on the line.\n";

    return 0;
}
