https://codeforces.com/problemset/problem/579/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int x;
    cin >> x;
    int cnt = 0;
    for (int i = 0; i < 30; i++) {
        if (x & (1ll << i)) {
            cnt++;
        }
    }
    cout << cnt << endl;
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
