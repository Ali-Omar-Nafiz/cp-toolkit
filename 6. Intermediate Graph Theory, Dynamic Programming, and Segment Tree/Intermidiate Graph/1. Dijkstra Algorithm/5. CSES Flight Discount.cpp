// Problem: https://cses.fi/problemset/task/1195/

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector < vector < pair < int, int > > > adj(2 * n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[n + a].push_back({c, n + b});
        adj[a].push_back({c / 2, n + b});
    }
    vector < int > dist(2 * n + 1, LLONG_MAX);
    dist[1] = 0;
    set < pair < int, int > > st;
    st.insert({0, 1});
    while (!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        for (auto [w, v]: adj[u]) {
            if (dist[u] + w < dist[v]) {
                st.erase({dist[v], v});
                dist[v] = d + w;
                st.insert({dist[v], v});
            }
        }
    }
    cout << dist[2 * n] << endl;
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

