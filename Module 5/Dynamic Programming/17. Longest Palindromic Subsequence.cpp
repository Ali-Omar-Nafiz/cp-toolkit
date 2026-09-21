#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

void solve() {
    string s;
    cin >> s;

    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Single character
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Build from shorter to longer substrings
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[0][n - 1] << nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
