// https://codeforces.com/problemset/problem/1669/F
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
 
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long
 
void solve() {
    int n;
    cin >> n;
    vector < int > v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int l = 0, r = n - 1;
    long long lSum = 0, rSum = 0;
    int ans = 0;
    while (l <= r) {
        if (lSum <= rSum) {
            lSum += v[l++];
        } else {
            rSum += v[r--];
        }
        if (lSum == rSum) {
            ans = l + (n - 1 - r);
        }
    }
    cout << ans << endl;
}
 
signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
}
