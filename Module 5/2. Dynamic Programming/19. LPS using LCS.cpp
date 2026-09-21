```cpp
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define nl '\n'

void solve()
{
    string s;
    cin >> s;

    int n = s.length();

    if (n == 0) return;

    // dp[i][j] = LCS length between s[0...i] and s[j...n-1]
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    // Base case: first row
    for (int j = n - 1; j >= 0; --j)
    {
        if (s[0] == s[j])
            dp[0][j] = 1;
        else if (j < n - 1)
            dp[0][j] = dp[0][j + 1];
    }

    // Base case: last column
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == s[n - 1])
            dp[i][n - 1] = 1;
        else if (i > 0)
            dp[i][n - 1] = dp[i - 1][n - 1];
    }

    // Fill the DP table
    for (int i = 1; i < n; ++i)
    {
        for (int j = n - 2; j >= 0; --j)
        {
            // Skip s[i] or skip s[j]
            dp[i][j] = max(dp[i][j + 1], dp[i - 1][j]);

            // Both characters can be matched
            if (s[i] == s[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
        }
    }

    // LPS length
    cout << dp[n - 1][0] << nl;

    // Recover the LPS
    string lps = "";
    int i = n - 1, j = 0;

    while (i >= 0 && j < n)
    {
        if (s[i] == s[j])
        {
            lps += s[i];
            i--;
            j++;
        }
        else
        {
            int move_up = (i > 0) ? dp[i - 1][j] : 0;
            int move_right = (j < n - 1) ? dp[i][j + 1] : 0;

            // Move toward the larger DP value
            if (move_up >= move_right)
                i--;
            else
                j++;
        }
    }

    cout << lps << nl;
}

signed main()
{
    fastio;

    solve();

    return 0;
}
```

