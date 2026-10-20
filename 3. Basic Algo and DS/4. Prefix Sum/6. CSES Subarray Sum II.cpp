#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    vector < int > v(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[i] = x;
        pre[i] = pre[i - 1] + v[i];
    }
    map < int, int > mp;
    mp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int chk = pre[i] - x;
        ans += mp[chk];
        mp[pre[i]]++;
    }
    cout << ans << endl;
}
signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}

// https://cses.fi/problemset/task/1661/
