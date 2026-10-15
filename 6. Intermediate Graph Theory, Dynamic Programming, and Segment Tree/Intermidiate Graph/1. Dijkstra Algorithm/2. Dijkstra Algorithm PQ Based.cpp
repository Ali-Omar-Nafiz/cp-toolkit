#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    // Build undirected graph
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    int src = 1;

    // dist = shortest distance, parent = path reconstruction
    vector<int> dist(n + 1, LLONG_MAX), parent(n + 1, -1);

    dist[src] = 0;

    // {distance, node} - min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> inLine;
    inLine.push({0, src});

    // Dijkstra
    while (!inLine.empty()) {
        auto [d, u] = inLine.top();  // this d is the minimum distance from src to u, that will never change
        inLine.pop();

        // Ignore outdated entry
        if (d > dist[u]) {
            continue;
        }

        for (auto [w, v] : adj[u]) {
            // Relax edge
            if (dist[v] > d + w) {
                dist[v] = d + w;
                inLine.push({dist[v], v});

                // Store previous node
                parent[v] = u;
            }
        }
    }

    // Destination is unreachable
    if (dist[n] == LLONG_MAX) {
        cout << -1 << endl;
        return;
    }

    // Reconstruct path from n to 1
    int cur = n;
    vector<int> path;

    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    // Reverse to get 1 -> n
    reverse(path.begin(), path.end());

    // Print shortest path
    for (auto x : path) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    FAST_IO;

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++) {
        // cout << "#Case: " << i << ": " << endl;
        solve();
    }

    return 0;
}
