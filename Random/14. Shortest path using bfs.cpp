#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

// ========================================================================
// CP TOOLKIT: BFS & Shortest Path Reconstruction (Unweighted Graphs)
// Complexity: O(V + E)
// - Calculates shortest distance from `src`.
// - Tracks the `parent` array to reconstruct the actual path.
// ========================================================================

void bfs(int src, const vector<vector<int>>& adjList, vector<int>& dist, vector<int>& parent) {
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adjList[u]) {
            if (dist[v] == -1) { // If not visited
                dist[v] = dist[u] + 1;
                parent[v] = u; // Record where we came from
                q.push(v);
            }
        }
    }
}

// Function to reconstruct the path from 'src' to 'dest'
vector<int> getPath(int dest, const vector<int>& dist, const vector<int>& parent) {
    if (dist[dest] == -1) {
        return {}; // Node is unreachable
    }
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end()); // Reverse to get Source -> Destination
    return path;
}

void solve() {
    int n, m;
    cin >> n >> m;

    // 1-based indexing (standard for most CP graph problems)
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line if the graph is Directed
    }

    // Initialize state arrays inside solve() to handle multiple test cases cleanly
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);

    int src = 1;
    int dest = n;

    // 1. Run BFS
    bfs(src, adjList, dist, parent);

    // 2. Check reachability and print
    if (dist[dest] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        // Print the length of the path (number of edges)
        cout << dist[dest] << endl; 
        
        // Print the actual path
        vector<int> path = getPath(dest, dist, parent);
        for (auto x : path) {
            cout << x << " ";
        }
        cout << endl;
    }
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
