// Problem: https://cses.fi/problemset/task/1197

#include <bits/stdc++.h>
 
using namespace std;
 
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector < array < int, 3 > > edg;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg.push_back({a, b, c});
    }
    vector < int > dist(n + 1, INT_MAX), parent(n + 1, -1);
    dist[1] = 0;
    int changed = -1;
    for (int i = 1; i <= n; i++) {
        for (auto [a, b, c]: edg) {
            if (dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
                parent[b] = a;
                if (i == n) {
                    changed = b;
                }
            }
        }
    }
    if (changed == -1) {
        cout << "NO" << endl;
        return;
    }
    vector < int > ans;
    int cur = changed;
    map < int, bool > mp;
    while (!mp[cur]) {
        mp[cur] = true;
        ans.push_back(cur);
        cur = parent[cur];
    }
    ans.push_back(cur);
    reverse(ans.begin(), ans.end());
    while (ans.back() != ans[0]) {
        ans.pop_back();
    }
    cout << "YES" << endl;
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
}
 
signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}
