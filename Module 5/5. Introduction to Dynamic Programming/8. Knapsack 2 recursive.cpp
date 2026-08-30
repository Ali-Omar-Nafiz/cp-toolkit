//https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > wt, val;
vector < vector < int > > dp;

int fun(int n, int v) {
    if (n == 0) {
        if (v != 0) {
            return INT_MAX;
        } else {
            return 0;
        }
    }
    if (dp[n][v] != -1) {
        return dp[n][v];
    }
    int tk = INT_MAX, nTk = INT_MAX;
    if (val[n] <= v) {
        tk = fun(n - 1, v - val[n]) + wt[n];
    }
    nTk = fun(n - 1, v);
    dp[n][v] = min(tk, nTk);
    return dp[n][v];
}

void solve() {
    int n, w;
    cin >> n >> w;
    wt.assign(n + 1, 0);
    val.assign(n + 1, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
        sum += val[i];
    }
    dp.assign(n + 1, vector < int > (sum + 1, -1));
    for (int j = sum; j >= 0; j--) {
        if (fun(n, j) <= w) {
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
