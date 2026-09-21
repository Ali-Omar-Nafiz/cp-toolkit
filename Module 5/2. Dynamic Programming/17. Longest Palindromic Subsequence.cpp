#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

vector<vector<int>> dp;

int longestPalindromeSubseq(string s) {
    int n = s.length();

    dp.assign(n, vector<int>(n, 0));

    // Single characters
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Gap between l and r
    for (int i = 1; i < n; i++) {
        int l = 0, r = i;

        while (r < n) {
            if (s[l] == s[r]) {
                dp[l][r] = dp[l + 1][r - 1] + 2;
            }
            else {
                dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]);
            }

            l++;
            r++;
        }
    }

    return dp[0][n - 1];
}

void solve() {
    string s;
    cin >> s;

    cout << longestPalindromeSubseq(s) << nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
