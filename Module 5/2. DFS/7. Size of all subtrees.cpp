#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1000];
int sz[1000];

void dfs(int cur, int p) {
    sz[cur] = 1;

    for (auto it : adj[cur]) {
        if (it != p) {
            dfs(it, cur);
            sz[cur] += sz[it];
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << "Subtree Size of " << i << " = " << sz[i] << '\n';
    }

    return 0;
}
