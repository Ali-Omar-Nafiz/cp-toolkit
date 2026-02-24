// ===== Accumulate Toolkit (CP Ready) =====
// accumulate(start, end, initial_value, operation)
// default operation = addition

#include <bits/stdc++.h>
using namespace std;

// Custom multiply function
int multiply(int a, int b) {
    return a * b;
}

void example() {
    vector<int> v = {3, 2, 5, 24, 9};

    // Sum of elements
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << "\n";   // 43

    // Product of elements
    int mlti = accumulate(v.begin(), v.end(), 1, multiply);
    cout << mlti << "\n";   // prints 6480
}
