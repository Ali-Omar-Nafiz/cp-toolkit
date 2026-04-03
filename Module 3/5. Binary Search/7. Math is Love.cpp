// Problem: https://www.spoj.com/problems/MATHLOVE/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long
#define endl '\n'

void solve() {
    int y;
    cin >> y;
    int l = 0, r = 1e5;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int chk = (mid * (mid + 1)) / 2;
        if (chk == y) {
            ans = mid;
            break;
        }
        if (chk > y) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (ans == -1) {
        cout << "NAI" << endl;
    } else {
        cout << ans << endl;
    }
}

signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
