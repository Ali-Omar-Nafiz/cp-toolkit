#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

// ========================================================================
// CP TOOLKIT: Topological Sort (Kahn's Algorithm)
// Complexity: O(V + E)
// Returns the topological order of a DAG. 
// If the graph contains a cycle, it returns an empty vector.
// ========================================================================
vector<int> topoSort(int n, const vector<vector<int>>& adjList, vector<int>& inDeg) {
    queue<int> q;
    vector<int> order;

    // 1. Push all pure source nodes (in-degree == 0) to the queue
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }

    // 2. Process the graph
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        // 3. Remove dependencies for neighbors
        for (auto v : adjList[u]) {
            inDeg[v]--;
            if (inDeg[v] == 0) {
                q.push(v);
            }
        }
    }

    // 4. Cycle Detection: If we couldn't process all nodes, a cycle exists.
    if (order.size() != n) {
        return {}; // Return empty vector to signal failure
    }

    return order;
}


void solve() {
    int n, m; 
    cin >> n >> m; // n = number of nodes, m = number of directed edges

    vector<vector<int>> adjList(n + 1);
    vector<int> inDeg(n + 1, 0);

    // Read general directed edges (u -> v)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        inDeg[v]++;
    }

    // Get the topological sort
    vector<int> order = topoSort(n, adjList, inDeg);

    // Handle the result
    if (order.empty()) {
        // This handles cases where tasks are impossible to complete
        cout << "IMPOSSIBLE" << endl; 
    } else {
        for (auto x : order) {
            cout << x << " ";
        }
        cout << endl;
    }
}


signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t; // Uncomment if the problem specifies multiple test cases upfront
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
