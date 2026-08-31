//https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, w;
    cin >> n >> w;

    vector<int> wt(n + 1), val(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    // dp[i][j] = maximum value using first i items with exact weight j
    // -1 means this exact weight is not possible
    vector<vector<int>> dp(n + 1, vector<int>(w + 1));

    // Initialize states for the first item
    for (int j = 0; j <= w; j++) {
        dp[1][j] = -1;
    }

    dp[1][0] = 0;

    if (wt[1] <= w) {
        dp[1][wt[1]] = val[1];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= w; j++) {

            // Don't take item i
            dp[i][j] = dp[i - 1][j];

            // Take item i if its weight fits
            if (j - wt[i] >= 0) {
                if (dp[i - 1][j - wt[i]] == -1) {
                    continue;
                }

                dp[i][j] = max(
                    dp[i][j],
                    dp[i - 1][j - wt[i]] + val[i]
                );
            }
        }
    }

    // We can use any weight up to w
    int ans = 0;

    for (int j = 0; j <= w; j++) {
        ans = max(ans, dp[n][j]);
    }

    cout << ans << endl;
}

signed main() {
    FAST_IO;

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}
