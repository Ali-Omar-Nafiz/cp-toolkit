#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    int dp[n][m];
    memset(dp, 0, sizeof(dp));

    // First row
    for (int j = 0; j < m; j++) {
        if (s1[0] == s2[j]) {
            dp[0][j] = 1;
        }
        else if (j > 0) {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // First column
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[0]) {
            dp[i][0] = 1;
        }
        else if (i > 0) {
            dp[i][0] = dp[i - 1][0];
        }
    }

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if (s1[i] == s2[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    cout << dp[n - 1][m - 1] << nl;

    // Backtrack to reconstruct LCS
    int i = n - 1, j = m - 1;
    string lcs;

    while (i >= 0 && j >= 0) {
        if (s1[i] == s2[j]) {
            lcs += s1[i];
            i--;
            j--;
        }
        else if (i > 0 && dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << lcs << nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
