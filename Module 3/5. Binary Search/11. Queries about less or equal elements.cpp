// Problem: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/H
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector < int > a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        int ans = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] > x) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
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
