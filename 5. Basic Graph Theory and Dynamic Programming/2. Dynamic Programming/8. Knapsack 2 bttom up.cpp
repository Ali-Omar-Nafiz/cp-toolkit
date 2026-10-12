//https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, w;
    cin >> n >> w;
    vector < int > wt(n + 1), val(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
        sum += val[i];
    }
    vector < vector < int > > dp(n + 1, vector < int > (sum + 1));
    for (int j = 1; j <= sum; j++) {
        dp[1][j] = w + 1;
    }
    dp[1][0] = 0;
    dp[1][val[1]] = wt[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - val[i] >= 0) {
                if (dp[i - 1][j - val[i]] < w) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - val[i]] + wt[i]);
                }
            }
        }
    }
    for (int j = sum; j >= 0; j--) {
        if (dp[n][j] <= w) {
            cout << j << endl;
            return;
        }
    }
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
