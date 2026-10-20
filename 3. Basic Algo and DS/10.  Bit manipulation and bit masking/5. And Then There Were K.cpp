// https://codeforces.com/contest/1527/problem/A
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
    while (x > 0) {
        cnt++;
        x = (x >> 1ll);
    }
    cout << (1ll << (cnt - 1)) - 1 << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
