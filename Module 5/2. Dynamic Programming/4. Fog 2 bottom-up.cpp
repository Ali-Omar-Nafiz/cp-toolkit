#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector < int > h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    vector < int > dp(n + 1, INT_MAX);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[i] = 0;
        } else if (i == 2) {
            dp[i] = abs(h[1] - h[2]);
        } else {
            int ans = INT_MAX;
            for (int j = i - 1; j >= max(1ll, i - k); j--) {
                int cur = abs(h[i] - h[j]) + dp[j];
                ans = min(ans, cur);
            }
            dp[i] = ans;
        }
    }
    cout << dp[n] << endl;
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
