// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

vector<int> wt, val;
vector<vector<int>> dp;

// Maximum value using first n items with weight limit w
int fun(int n, int w) {

    // Invalid weight
    if (w < 0) {
        return INT_MIN;
    }

    // No items left
    if (n == 0) {
        return 0;
    }

    // Already calculated
    if (dp[n][w] != -1) {
        return dp[n][w];
    }

    int tk, nTk;

    // Take item n
    tk = fun(n - 1, w - wt[n]) + val[n];

    // Don't take item n
    nTk = fun(n - 1, w);

    // Take the better choice
    dp[n][w] = max(tk, nTk);

    return dp[n][w];
}

void solve() {
    int n, w;
    cin >> n >> w;

    // Store item weights and values
    wt.assign(n + 1, 0);
    val.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    // -1 means not calculated yet
    dp.assign(n + 1, vector<int>(w + 1, -1));

    cout << fun(n, w) << endl;
}

signed main() {
    FAST_IO;

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
