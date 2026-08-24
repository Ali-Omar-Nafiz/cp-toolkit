// Problem: https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

int n, k;
vector < int > h;
vector < int > cache;  // for memoization to optimize the recursive function

int fun(int n) {
    if (n == 1) {
        cache[n] = 0;
        return cache[n];
    }
    if (cache[n] != -1) {
        return cache[n];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (n < i) {
            break;
        }
        ans = min(ans, fun(n - i) + abs(h[n] - h[n - i]));
    }
    cache[n] = ans;
    return cache[n];
}

void solve() {
    cin >> n >> k;
    h.assign(n + 1, 0);
    cache.assign(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
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
