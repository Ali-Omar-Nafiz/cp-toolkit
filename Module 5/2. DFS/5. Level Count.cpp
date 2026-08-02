// Level Count
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<int> level;

void dfs(int cur, int parent) {
    for (auto x : adjList[cur]) {
        if (x != parent) {
            level[x] = level[cur] + 1;
            dfs(x, cur);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adjList.resize(n + 1);
    level.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    level[1] = 0;
    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << "Level[" << i << "] = " << level[i] << '\n';
    }

    return 0;
}
