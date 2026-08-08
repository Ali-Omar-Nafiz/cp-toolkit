// Suppose there are n cities connected by roads. Some cities already have hospitals. For every city, we want to find the minimum number of roads needed to reach the nearest hospital.

// Multi-source BFS
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<bool> vis(n + 1);
    vector<int> dist(n + 1);

    queue<int> q;

    int k;
    cin >> k;              // number of sources

    for(int i = 1; i <= k; i++) {
        int s;
        cin >> s;

        vis[s] = true;
        dist[s] = 0;
        q.push(s);
    }

    while(!q.empty()) {
        int f = q.front();
        q.pop();

        for(auto &it : adj[f]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] = true;
                dist[it] = dist[f] + 1;
            }
        }
    }

    // distance of every node from nearest source
    for(int i = 1; i <= n; i++) {
        cout << "Distance of " << i << " = " << dist[i] << '\n';
    }

    return 0;
}
