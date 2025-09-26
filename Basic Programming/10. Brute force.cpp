✅ Summary:

Brute-force: Explore all possibilities (small N, correctness).

Constructive: Build answer step-by-step following constraints.

Greedy: Make locally optimal choices to reach global optimum (works if problem satisfies greedy-choice property).

#include <bits/stdc++.h>
using namespace std;

/*
Brute-force Example: Subset Sum
Use-case: 
- Explore all possible subsets to check if any sums to a target.
- Works for small n (e.g., n ≤ 20) where correctness is more important than speed.
- Complexity: O(2^N)
*/

int main() {
    int n, S;
    cout << "Enter n (<=20) and target sum S: ";
    cin >> n >> S;
    int arr[25];
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bool found = false;
    int total = 1 << n; // 2^n subsets
    for (int mask = 0; mask < total; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += arr[i];
        }
        if (sum == S) {
            found = true;
            break;
        }
    }

    if (found) cout << "Subset with sum " << S << " exists\n";
    else cout << "No subset sums to " << S << "\n";

    return 0;
}
