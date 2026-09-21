#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

void solve() {
    string s1;
    cin >> s1;

    // The core trick: create s2 as the reverse of s1
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    int n = s1.length();

    // 1-based indexing for DP table to cleanly handle edge cases
    // dp[i][j] will store the LCS of s1[0..i-1] and s2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Fill DP table (Standard LCS logic)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Print the length of the Longest Palindromic Subsequence
    cout << dp[n][n] << nl;

    // Backtrack to reconstruct the LPS
    int i = n, j = n;
    string lps = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            // Match found, add to palindrome and move diagonally up-left
            lps += s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            // Move up
            i--;
        } else {
            // Move left
            j--;
        }
    }

    // Since we traced backward, reverse it to get the correct order 
    // (Though for a perfect palindrome, it reads the same both ways!)
    reverse(lps.begin(), lps.end());

    cout << lps << nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
