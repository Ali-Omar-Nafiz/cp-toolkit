// Highest index where arr[i] < target

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 3, 5, 7, 9, 9, 9, 10, 12};
    int n = v.size();

    int l = 0, r = n - 1, target = 9;
    int ans = -1;  // default (if no such index exists)

    while (l <= r) {
        int mid = l + (r - l) / 2;  // floor is enough

        if (v[mid] < target) {  // TRUE
            ans = mid;          // store possible answer
            l = mid + 1;        // go RIGHT to find last          // T T T T T T F F F F F
        } else {                // FALSE
            r = mid - 1;
        }
    }

    cout << ans << endl;   // Last True (highest index where v[i] < target)
    return 0;
}
