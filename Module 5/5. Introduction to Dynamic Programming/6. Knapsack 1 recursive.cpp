//https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

vector<int> wt, val;
vector<vector<int>> dp;

// Returns maximum value using first n items with total weight <= w
int fun(int n, int w) {
    // No items left
    if (n == 0) {
        return 0;
    }

    // Already calculated
    if (dp[n][w] != -1) {
        return dp[n][w];
    }

    int tk = 0, nTk = 0;

    // Take item n if it fits
    if (wt[n] <= w) {
        tk = fun(n - 1, w - wt[n]) + val[n];
    }

    // Don't take item n
    nTk = fun(n - 1, w);

    // Choose the better option
    dp[n][w] = max(tk, nTk);

    return dp[n][w];
}

void solve() {
    int n, w;
    cin >> n >> w;

    wt.assign(n + 1, 0);
    val.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    // -1 means the state has not been calculated yet
    dp.assign(n + 1, vector<int>(w + 1, -1));

    cout << fun(n, w) << endl;
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
