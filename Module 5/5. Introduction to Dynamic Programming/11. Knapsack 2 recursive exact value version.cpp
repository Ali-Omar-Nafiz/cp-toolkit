#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > wt, val;
vector < vector < int > > dp;

// Returns minimum weight needed to get exact value v using first n items
int fun(int n, int v) {
    if (v == 0) {
        return 0; // No value needed, so weight is 0
    }
    if (n == 0) {
        return -1; // Impossible to get value v
    }

    if (dp[n][v] != -2) {
        return dp[n][v]; // Already calculated
    }

    // Take current item
    int tk = fun(n - 1, v - val[n]);

    // Don't take current item
    int nTk = fun(n - 1, v);

    // Both choices are impossible
    if (tk == -1 && nTk == -1) {
        dp[n][v] = -1;
    }
    // Only don't-take is possible
    else if (tk == -1) {
        dp[n][v] = nTk;
    }
    // Only take is possible
    else if (nTk == -1) {
        dp[n][v] = tk + wt[n];
    }
    // Choose the smaller weight
    else {
        dp[n][v] = min(tk + wt[n], nTk);
    }

    return dp[n][v];
}

void solve() {
    int n, w;
    cin >> n >> w;

    wt.assign(n + 1, 0);
    val.assign(n + 1, 0);

    int sum = 0;

    // Input weight and value
    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
        sum += val[i];
    }

    // dp[n][v] = minimum weight to achieve value v
    dp.assign(n + 1, vector < int > (sum + 1, -2));

    // Try values from maximum to minimum
    for (int i = sum; i >= 0; i--) {
        int cur = fun(n, i);

        // First possible value within weight limit is the answer
        if (cur != -1 && cur <= w) {
            cout << i << endl;
            return;
        }
    }
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
