#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, w;
    cin >> n >> w;

    vector<int> wt(n + 1), val(n + 1);

    // Input item weights and values
    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    // dp[i][j] = maximum value using first i items with weight j
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    // Base case: first item
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[1][wt[1]] = val[1];

    // Build DP table
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= w; j++) {

            // Don't take item i
            dp[i][j] = dp[i - 1][j];

            // Take item i if possible
            if (j - wt[i] >= 0) {
                int chk = dp[i - 1][j - wt[i]];

                if (chk != -1) {
                    dp[i][j] = max(dp[i][j], chk + val[i]);
                }
            }
        }
    }

    // Find weight giving maximum value
    int idx = -1, mx = INT_MIN;

    for (int j = 0; j <= w; j++) {
        if (dp[n][j] > mx) {
            mx = dp[n][j];
            idx = j;
        }
    }

    // Reconstruct selected items
    vector<int> selected;

    for (int i = n - 1; i >= 0; i--) {

        // Item i+1 was selected
        if (dp[i][idx] != dp[i + 1][idx]) {
            selected.push_back(i + 1);
            idx -= wt[i + 1];
        }
    }

    for (auto x : selected) {
        cout << x << " ";
    }

    cout << endl;
}

signed main() {
    FAST_IO;

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++) {
        // cout << "#Case: " << i << ": " << endl;
        solve();
    }

    return 0;
}
