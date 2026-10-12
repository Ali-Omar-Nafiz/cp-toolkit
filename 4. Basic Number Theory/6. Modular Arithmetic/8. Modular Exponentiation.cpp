// https://codeforces.com/contest/913/problem/A

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    if (n >= 30) {
        cout << m << endl;
    } else {
        int mod = (1ll << n);
        int ans = m % mod;
        cout << ans << endl;
    }
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
}
