/*
------------------------------------------------------------
PROBLEM STATEMENT
------------------------------------------------------------

You are given an array of n integers.

Operation:
    - Select any pair of elements (a, b).
    - The larger element of the pair is removed from the array.
    - The cost of this operation is equal to the smaller element.

Goal:
    Perform operations until only ONE element remains.
    Find the MINIMUM total cost.

------------------------------------------------------------
GREEDY OBSERVATION
------------------------------------------------------------

Each operation removes exactly one element.
So we must perform (n - 1) operations.

Key Idea:
    To minimize total cost, we should always pay the
    smallest possible value as the operation cost.

Optimal Strategy:
    Keep the smallest element alive until the end.
    Always pair the smallest element with any other element.

Why?
    - Smaller element survives.
    - Larger element gets removed.
    - Cost added each time = smallest element.

Thus,
    total cost = smallest_element * (n - 1)

------------------------------------------------------------
TIME COMPLEXITY
    O(n)

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long

int32_t main() {
    FAST_IO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // find minimum element
    int mn = *min_element(a.begin(), a.end());

    // minimum total cost
    int ans = mn * (n - 1);

    cout << ans << '\n';

    return 0;
}
