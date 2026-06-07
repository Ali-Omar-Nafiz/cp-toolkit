// https://atcoder.jp/contests/abc172/tasks/abc172_d
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > divs(1e7 + 1);

void run() {
    for (int i = 1; i < divs.size(); i++) {
        for (int j = i; j < divs.size(); j += i) {
            divs[j]++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (i * divs[i]);
    }
    cout << ans << endl;
}

signed main() {
    FAST_IO;
    run();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
