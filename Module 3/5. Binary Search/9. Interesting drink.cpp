// Problem: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/E
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector < int > v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid] <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << (ans + 1) << endl;
    }
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}
