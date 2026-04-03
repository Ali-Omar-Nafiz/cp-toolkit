// Problem: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monks-encounter-with-polynomial/?purpose=login&source=problem-page&update=google
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long
#define endl '\n'

int fun(int a, int b, int c, int k, int x) {
    int chk = (a * x * x) + (b * x) + c;
    if (chk >= k) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int l = 0, r = 1e5;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int chk = fun(a, b, c, k, mid);
        if (chk == true) {
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
        solve();
    }
    return 0;
}
