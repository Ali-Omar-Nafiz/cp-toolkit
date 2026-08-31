// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, w;
    cin >> n >> w;

    vector<int> wt(n + 1), val(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    // dp[i][j] = max value using first i items with exact weight j
    // -1 means this exact weight is not possible
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    // parent[i][j] = previous weight if item i was taken
    // -1 means item i was not taken
    vector<vector<int>> parent(n + 1, vector<int>(w + 1, -1));

    dp[1][0] = 0;

    // Take the first item
    if (wt[1] <= w) {
        dp[1][wt[1]] = val[1];
        parent[1][wt[1]] = 0;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= w; j++) {

            // Don't take item i
            dp[i][j] = dp[i - 1][j];
            parent[i][j] = -1;

            // Take item i if possible
            if (j >= wt[i] && dp[i - 1][j - wt[i]] != -1) {
                int cur = dp[i - 1][j - wt[i]] + val[i];

                // Taking item i gives a better value
                if (cur > dp[i][j]) {
                    dp[i][j] = cur;
                    parent[i][j] = j - wt[i];
                }
            }
        }
    }

    // Find the best possible weight
    int bestW = 0;

    for (int j = 0; j <= w; j++) {
        if (dp[n][j] > dp[n][bestW]) {
            bestW = j;
        }
    }

    cout << dp[n][bestW] << endl;

    // Retrieve selected items from n -> 1
    vector<int> items;
    int curW = bestW;

    for (int i = n; i >= 1; i--) {
        if (parent[i][curW] != -1) {
            items.push_back(i);
            curW = parent[i][curW];
        }
    }

    // Reverse to get items in increasing order
    reverse(items.begin(), items.end());

    for (int item : items) {
        cout << item << " ";
    }
    cout << endl;
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
