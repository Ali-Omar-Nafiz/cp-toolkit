// https://www.geeksforgeeks.org/dsa/minimum-number-of-jumps-to-reach-end-of-a-given-array/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // Edge case: If the array has only 1 element, 0 jumps are needed
    if (n <= 1) {
        cout << 0 << endl;
        return;
    }

    int jumps = 0;
    int current_end = 1; // The maximum index we can reach with the current number of jumps
    int farthest = 1;    // The absolute furthest index we can reach looking ahead

    for (int i = 1; i <= n; i++) {
        // Update the furthest we can reach from the current position
        farthest = max(farthest, i + v[i]);

        // If we have reached the end of the range for the current jump
        if (i == current_end) {
            // We only need to jump if we haven't reached the destination yet
            if (i != n) { 
                jumps++;
                current_end = farthest;
            }
        }
    }
    
    cout << jumps << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
