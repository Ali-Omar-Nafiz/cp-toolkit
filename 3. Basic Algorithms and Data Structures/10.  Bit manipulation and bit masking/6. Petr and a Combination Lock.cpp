// https://codeforces.com/problemset/problem/1097/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
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
    for (int i = 0; i < (1 << n); i++) {
        bitset < 32 > b = i;
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (b[j]) {
                cur -= v[j];
            } else {
                cur += v[j];
            }
        }
        if (cur % 360 == 0) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
