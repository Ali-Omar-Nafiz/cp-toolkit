// Problem: https://cses.fi/problemset/task/1633/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

int n;
vector < int > chache;

int fun(int n) {
    if (chache[n] != 0) {
        return chache[n];
    }
    int res = 0;
    if (n <= 6) {
        res = 1;
    }
    for (int i = 1; i <= 6; i++) {
        if (n <= i) {
            break;
        }
        res += fun(n - i);
        res %= MOD;
    }
    chache[n] = res;
    return chache[n];
}

void solve() {
    cin >> n;
    chache.assign(n + 1, 0);
    cout << fun(n) << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
      // cout << "Case " << i << ": \n";
      solve();
    }
    return 0;
}
