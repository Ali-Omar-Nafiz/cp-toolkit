// https://atcoder.jp/contests/abc190/tasks/abc190_c
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector < pair < int, int > > cond;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        cond.push_back({x, y});
    }
    int k;
    cin >> k;
    vector < pair < int, int > > v;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int ans = 0;
    for (int i = 0; i < (1 << k); i++) {
        bitset < 32 > b = i;
        vector < int > chk(n + 1);
        for (int j = 0; j < k; j++) {
            if (b[j] == 0) {
                chk[v[j].first]++;
            } else {
                chk[v[j].second]++;
            }
        }
        int cur = 0;
        for (int j = 0; j < m; j++) {
            // if both dish has at least one ball
            if (chk[cond[j].first] && chk[cond[j].second]) {
                cur++;
            }
        }
        ans = max(ans, cur);
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
