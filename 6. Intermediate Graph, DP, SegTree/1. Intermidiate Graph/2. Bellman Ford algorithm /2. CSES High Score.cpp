// Problem: https://cses.fi/problemset/task/1673/

#include <bits/stdc++.h>
 
using namespace std;
 
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector < array < int, 3 > > edgeList;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back({a, b, c});
    }
    vector < int > dist(n + 1, LLONG_MIN);
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (auto [u, v, w]: edgeList) {
            if (dist[u] != LLONG_MIN && (dist[v] < dist[u] + w)) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto [u, v, w]: edgeList) {
            if (dist[u] != LLONG_MIN && (dist[u] == LLONG_MAX || dist[v] < dist[u] + w)) {
                dist[v] = LLONG_MAX;
            }
        }
    }
    cout << (dist[n] == LLONG_MAX ? -1 : dist[n]) << endl;
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
