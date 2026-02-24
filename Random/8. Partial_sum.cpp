// ===== partial_sum Toolkit (CP Ready) =====
// partial_sum(start, end, destination_start)

#include <bits/stdc++.h>
using namespace std;

void example() {
    vector<int> v = {3, 4, 5, 2, 6};
    vector<int> pre(v.size());

    // Prefix sum
    partial_sum(v.begin(), v.end(), pre.begin());

    for (auto x : pre) {
        cout << x << " ";
    }
    cout << "\n";   // 3 7 12 14 20
}
