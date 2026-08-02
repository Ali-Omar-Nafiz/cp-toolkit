// DFS in tree
// No need of extra visited array
// Because every node can try to visit only it's parent twice
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;

void dfs(int cur, int parent) {
    cout << cur << " ";

    for (auto x : adjList[cur]) {
        if (x != parent) {
            dfs(x, cur);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adjList.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1, -1);

    return 0;
}
