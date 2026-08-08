// Tree Diameter Endpoint Technique
// For every node v:
// max distance from v = max(distA[v], distB[v])

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> distA, distB;

void dfs(int cur, int parent, vector<int>& dist) {
    for (auto it : adj[cur]) {
        if (it != parent) {
            dist[it] = dist[cur] + 1;
            dfs(it, cur, dist);
        }
    }
}

int main() {
    cin >> n >> m;

    adj.assign(n + 1, {});
    distA.assign(n + 1, 0);
    distB.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // --------------------------------
    // Step 1: Find one endpoint of diameter
    // --------------------------------

    distA[1] = 0;
    dfs(1, -1, distA);

    int nodeA = 1;

    for (int i = 1; i <= n; i++) {
        if (distA[i] > distA[nodeA]) {
            nodeA = i;
        }
    }

    // --------------------------------
    // Step 2: Find the other endpoint
    // --------------------------------

    fill(distA.begin(), distA.end(), 0);

    dfs(nodeA, -1, distA);

    int nodeB = nodeA;

    for (int i = 1; i <= n; i++) {
        if (distA[i] > distA[nodeB]) {
            nodeB = i;
        }
    }

    // --------------------------------
    // Step 3: Distance from nodeB
    // --------------------------------

    dfs(nodeB, -1, distB);

    // --------------------------------
    // Step 4: For every node,
    // maximum distance = max(distA, distB)
    // --------------------------------

    for (int i = 1; i <= n; i++) {
        int farthest = max(distA[i], distB[i]);

        cout << "Node " << i
             << " : " << farthest << '\n';
    }

    return 0;
}
