// https://codeforces.com/group/isP4JMZTix/contest/379072/problem/G
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long
#define endl '\n'

bool fun(int mid, int k, int n) {
    int chk = mid - (int)(mid / n);
    if (chk >= k) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int l = 1, r = 2e9;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (fun(mid, k, n)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}
