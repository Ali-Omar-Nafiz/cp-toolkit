// it gives same dp table as the bottom up version
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
#define int long long

vector<int> wt, val;
vector<vector<int>> dp;

// dp[n][w] = maximum value for exact weight w
// using the first n items
//
// -2 = state not calculated
// -1 = exact weight w is impossible
int fun(int n, int w) {

    // Exact weight 0 is always possible
    // by taking nothing.
    if (w == 0)
        return 0;

    // No items left, but still need positive weight.
    // Therefore impossible.
    if (n == 0)
        return -1;

    // Already calculated
    if (dp[n][w] != -2)
        return dp[n][w];

    // Don't take item n
    int res1 = fun(n - 1, w);

    // Take item n
    int res2 = -1;

    if (w >= wt[n]) {
        res2 = fun(n - 1, w - wt[n]);

        if (res2 != -1)
            res2 += val[n];
    }

    // Both choices impossible
    if (res1 == -1 && res2 == -1)
        return dp[n][w] = -1;

    // Only one possible
    if (res1 == -1)
        return dp[n][w] = res2;

    if (res2 == -1)
        return dp[n][w] = res1;

    // Both possible
    return dp[n][w] = max(res1, res2);
}

void solve() {

    int n, W;
    cin >> n >> W;

    wt.assign(n + 1, 0);
    val.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    // -2 = not calculated
    dp.assign(n + 1, vector<int>(W + 1, -2));

    int ans = 0;

    // We need weight <= W, not necessarily exactly W.
    for (int w = 0; w <= W; w++) {
        int res = fun(n, w);

        if (res != -1)
            ans = max(ans, res);
    }

    cout << ans << nl;
}

signed main() {

    fastio;

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}
