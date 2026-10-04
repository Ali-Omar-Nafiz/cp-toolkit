// Problem: https://codeforces.com/contest/20/problem/C
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    // Build undirected weighted graph
    vector < vector < pair < int, int > > > adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    int src = 1;

    // dist = shortest distance, parent = previous node in path
    vector < int > dist(n + 1, 1e12), parent(n + 1, -1);

    dist[src] = 0;

    // Stores {distance, node}
    set < pair < int, int > > inLine;

    // Initially, all nodes are in the set
    for (int i = 1; i <= n; i++) {
        inLine.insert({dist[i], i});
    }

    // Dijkstra
    while (!inLine.empty()) {
        // Take node with minimum distance
        auto [d, u] = *inLine.begin();
        inLine.erase(inLine.begin());

        // Relax all adjacent edges
        for (auto [w, v]: adj[u]) {
            if (dist[v] > d + w) {

                // Remove old distance
                inLine.erase({dist[v], v});

                // Update shortest distance
                dist[v] = d + w;
                inLine.insert({dist[v], v});

                // Store path information
                parent[v] = u;
            }
        }
    }

    // No path from 1 to n
    if (dist[n] == 1e12) {
        cout << -1 << endl;
        return;
    }

    // Reconstruct path from n back to 1
    int cur = n;
    vector < int > path;

    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    // Reverse to get path from 1 to n
    reverse(path.begin(), path.end());

    for (auto x: path) {
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
