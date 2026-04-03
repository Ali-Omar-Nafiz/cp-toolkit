// Problem: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/N
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long
#define endl '\n'

bool fun(int x) {
    int l = 1, r = 1e4;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid * mid * mid <= x) {
            ans = mid * mid * mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (ans == x) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    int x;
    cin >> x;
    for (int i = 1; i <= 1e4; i++) {
        int chk = x - (i * i * i);
        if (fun(chk)) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
