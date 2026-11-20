#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

string a, b;
vector < vector < int > > dp;

int fun(int i, int j) {
    if (i >= a.size() || j >= b.size()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if (a[i] == b[j]) {
        ans = 1 + fun(i + 1, j + 1);
    } else {
        ans = max(fun(i + 1, j), fun(i, j + 1));
    }
    dp[i][j] = ans;
    return ans;
}

void solve() {
    cin >> a >> b;
    dp.assign(a.size(), vector < int > (b.size(), -1));
    cout << fun(0, 0) << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}

