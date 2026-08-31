#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> h(n + 1);
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    // Base cases
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);

    // Bottom-up calculation
    for (int i = 3; i <= n; i++) {
        dp[i] = min(
            dp[i - 1] + abs(h[i] - h[i - 1]),
            dp[i - 2] + abs(h[i] - h[i - 2])
        );
    }

    cout << dp[n] << endl;
}

signed main() {
    FAST_IO;

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
