#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    // dp[i] = {minimum cost to reach i, previous stone}
    vector<pair<int, int>> dp(n + 1);

    dp[1] = {0, -1}; // Start from stone 1

    for (int i = 2; i <= n; i++) {
        int mn = INT_MAX, idx = -1;

        // Try all stones within K jumps
        for (int j = i - 1; j >= max(1LL, i - k); j--) {
            int cur = dp[j].first + abs(h[i] - h[j]);

            // Update minimum cost and previous stone
            if (cur < mn) {
                mn = cur;
                idx = j;
            }
        }

        dp[i] = {mn, idx};
    }

    cout << dp[n].first << endl;

    // Retrieve the path from N back to 1
    int cur = n;
    while (cur != -1) {
        cout << cur << " ";
        cur = dp[cur].second;
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
