#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<pair<int, int>> adj[N];   // adj[u] = {neighbour, weight}
bool vis[N];

long long prim(int src, int n) {
    // min-heap of {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    long long mst = 0;
    int cnt = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;        // already in the tree, skip

        vis[u] = true;               // add node to the tree
        mst += w;
        cnt++;

        for (auto [v, cost] : adj[u])
            if (!vis[v]) pq.push({cost, v});
    }

    return cnt == n ? mst : -1;      // -1 if graph is disconnected
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << prim(1, n) << "\n";
}
