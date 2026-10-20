// Problem: https://codeforces.com/contest/1201/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long
#define endl '\n'

int cost(int x, vector < int > v) {
    int med = (v.size() - 1) / 2;
    int cnt = 0;
    for (int i = med; i < v.size(); i++) {
        if (v[i] <= x) {
            cnt += (abs(x - v[i]));
        } else {
            break;
        }
    }
    return cnt;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector < int > v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int l = 1, r = 2e9;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (cost(mid, v) <= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
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
