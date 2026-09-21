// Total Connected Components
#include <bits/stdc++.h>
using namespace std;

vector < bool > vis(1000);
vector < vector < int > > adjList(1000);

void dfs(int cur) {
    if (vis[cur]) {
        return;
    }
    vis[cur] = true;
    for (auto x: adjList[cur]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
