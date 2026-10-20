#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> vis(1000);
vector<vector<int>> adjMatrix(1000, vector<int>(1000));

void dfs(int cur) {
    if (vis[cur]) {
        return;
    }

    vis[cur] = true;

    for (int i = 1; i <= n; i++) {
        if (adjMatrix[cur][i] == 1 && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    int s;
    cin >> s;

    dfs(s);

    return 0;
}
