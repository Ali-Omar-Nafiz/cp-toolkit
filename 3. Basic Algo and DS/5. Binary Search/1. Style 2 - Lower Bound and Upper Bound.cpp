/*
Binary search (l <= r version)

Lower Bound: First index i where arr[i] >= target
Upper Bound: First index i where arr[i] > target
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 3, 5, 7, 9, 9, 9, 10, 12};
    int n = v.size();

    // 🔹 LOWER BOUND (first >= target)
    int l = 0, r = n - 1, target = 9;
    int ans = n;  // default (if not found)

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (v[mid] >= target) {   // TRUE
            ans = mid;            // store possible answer
            r = mid - 1;          // go left to find first        // F F F F F F T T T T T 
        } else {                  // FALSE
            l = mid + 1;
        }
    }
    cout << ans << endl;


    // 🔹 UPPER BOUND (first > target)
    l = 0, r = n - 1, target = 9;
    ans = n;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (v[mid] > target) {    // TRUE
            ans = mid;
            r = mid - 1;                           // F F F F F F F F F T T
        } else {                  // FALSE
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
