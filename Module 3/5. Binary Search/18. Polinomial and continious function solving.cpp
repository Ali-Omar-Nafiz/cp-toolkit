/*
Continuous Function / Polynomial Root Finding

The function (or the chosen range) must be monotonic 
(either increasing or decreasing in that interval).

We want to solve:
    f(x) = target

To do this, we first find two values x1 and x2 such that:
    f(x1) < target
    f(x2) > target
(or vice versa)

This guarantees that a solution exists between x1 and x2.

Then we apply binary search on the range [x1, x2]
to find the value of x where f(x) ≈ target.

Example:
    Solve f(x) = 0
    f(x) = x^3 + 5x^2 - 4x + 3
*/

#include <bits/stdc++.h>
using namespace std;

// Function: f(x) = x^3 + 5x^2 - 4x + 3
double f(double x) {
    return x*x*x + 5.0*x*x - 4.0*x + 3;
}

int main() {
    // Initial range [l, r] such that:
    // f(l) < 0 and f(r) > 0 → root exists in this interval
    double l = -6, r = 1.0;

    // Binary search on continuous function
    for (int step = 0; step < 100; step++) {
        double mid = (l + r) / 2.0;

        // If f(mid) > 0, root is on the left side
        if (f(mid) > 0) {
            r = mid;
        }
        // If f(mid) < 0, root is on the right side
        else {
            l = mid;
        }
    }

    // Final approximation of the root
    double ans = (l + r) / 2.0;

    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}
