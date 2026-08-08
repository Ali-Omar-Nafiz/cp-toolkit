#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1000];
int mx[1000];

void dfs(int cur, int p) {
    mx[cur] = 0;

    for (auto it : adj[cur]) {
        if (it != p) {
            dfs(it, cur);
            mx[cur] = max(mx[cur], mx[it] + 1);
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
        cout << "Height of " << i << " = " << mx[i] << '\n';
    }

    return 0;
}
