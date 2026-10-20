#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, w;
    cin >> n >> w;

    vector<int> wt(n + 1), val(n + 1);

    // Input weight and value
    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    // dp[i][j] = max value using first i items with weight exactly j
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    // take[i][j] = whether item i was taken to reach dp[i][j]
    vector<vector<bool>> take(n + 1, vector<bool>(w + 1));

    // Base case: item 1 is either not taken or taken
    dp[1][0] = 0;
    dp[1][wt[1]] = val[1];
    take[1][wt[1]] = true;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= w; j++) {

            // Don't take item i
            dp[i][j] = dp[i - 1][j];

            // Take item i
            if (j - wt[i] >= 0) {
                int chk = dp[i - 1][j - wt[i]];

                if (chk != -1) {
                    if (chk + val[i] > dp[i][j]) {
                        dp[i][j] = chk + val[i];
                        take[i][j] = true;
                    }
                }
            }
        }
    }

    // Find the weight giving maximum value
    int idx = -1, mx = INT_MIN;

    for (int j = 0; j <= w; j++) {
        if (dp[n][j] > mx) {
            mx = dp[n][j];
            idx = j;
        }
    }

    // Reconstruct selected items
    vector<int> selected;

    for (int i = n; i >= 1; i--) {
        if (take[i][idx]) {
            selected.push_back(i);
            idx -= wt[i];
        }
    }

    // Items are collected in reverse order
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
