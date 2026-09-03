// https://atcoder.jp/contests/dp/tasks/dp_d
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

    // dp[i][j] = maximum value using first i items
    // with total weight <= j
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {

            // Don't take item i
            dp[i][j] = dp[i - 1][j];

            // Take item i if its weight fits
            if (wt[i] <= j) {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i - 1][j - wt[i]] + val[i]
                );
            }
        }
    }

    cout << dp[n][w] << endl;
}

signed main() {
    FAST_IO;

    solve();

    return 0;
}
