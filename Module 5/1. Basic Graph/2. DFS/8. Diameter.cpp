// Diameter = maximum shortest-path distance between any two vertices. (Guaranteed for trees. For a general graph, especially a cyclic graph, this DFS approach is not generally valid.)
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector < vector < int > > adj;
vector < int > dist;

void dfs(int cur, int parent) {
    for (auto it : adj[cur]) {
        if (it != parent) {
            dist[it] = dist[cur] + 1;
            dfs(it, cur);
        }
    }
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    dist.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // First DFS
    dist[1] = 0;
    dfs(1, -1);

    int mx = 0, node = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > mx) {
            mx = dist[i];
            node = i;
        }
        dist[i] = 0;
    }

    // Second DFS
    dfs(node, -1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dist[i]);
    }

    cout << ans << endl;

    return 0;
}
