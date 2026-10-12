✅ Summary:

Brute-force: Explore all possibilities (small N, correctness).

Constructive: Build answer step-by-step following constraints.

Greedy: Make locally optimal choices to reach global optimum (works if problem satisfies greedy-choice property).

#include <bits/stdc++.h>
using namespace std;

/*
Constructive Example: Build a valid string step-by-step
Use-case:
- Directly construct an answer satisfying constraints without searching.
- Example: Create binary string of length n with k ones and no two ones adjacent.
- Complexity: O(n)
*/

int main() {
    int n, k;
    cout << "Enter n and k (binary string length n with k ones, no adjacent ones): ";
    cin >> n >> k;

    // Feasibility check
    if (k > (n + 1) / 2) {
        cout << "Impossible\n"; 
        return 0;
    }

    string s;
    s.resize(n, '0'); // initialize with zeros

    // Place ones at every alternate position
    int idx = 0;
    while (k > 0) {
        s[idx] = '1';
        idx += 2;
        k--;
    }

    cout << "Constructed string: " << s << endl;
    return 0;
}
