#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 3>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v, u});
        adj[v].push_back({w, u, v});
    }

    vector<int> vis(n + 1);
    vector<vector<pair<int, int>>> mst(n + 1); // MST adjacency list: {neighbor, weight}
    set<array<int, 3>> st;
    st.insert({0, 1, 0});
    int total = 0;
    int cnt = 0;

    while (!st.empty()) {
        auto [d, v, u] = *st.begin();
        st.erase(st.begin());
        if (vis[v]) continue;
        vis[v] = 1;
        cnt++;
        total += d;
        if (u != 0) {
            mst[u].push_back({v, d});
            mst[v].push_back({u, d});
        }
        for (auto [w, v2, u2] : adj[v])
            if (!vis[v2]) st.insert({w, v2, u2});
    }

    if (cnt < n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << total << "\n";
    for (int u = 1; u <= n; u++)
        for (auto [v, w] : mst[u])
            if (u < v) cout << u << " " << v << " " << w << "\n";
}
