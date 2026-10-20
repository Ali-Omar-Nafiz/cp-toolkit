// Problem: https://lightoj.com/problem/crossed-ladders
#include <bits/stdc++.h>
//
using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

double check(double d, double x, double y) {
    double h1 = sqrt((x * x) - (d * d));
    double h2 = sqrt((y * y) - (d * d));
    double h = (h1 * h2) / (h1 + h2);
    return h;
}

void solve() {
    double x, y, c;
    cin >> x >> y >> c;
    double l = 0, r = min(x, y);
    for (int step = 1; step < 100; step++) {
        double mid = l + (r - l) / 2.0;
        if (check(mid, x, y) > c) {
            l = mid;
        } else {
            r = mid;
        }
    }
    double ans = (l + r) / 2.0;
    cout << fixed << setprecision(7) << ans << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
