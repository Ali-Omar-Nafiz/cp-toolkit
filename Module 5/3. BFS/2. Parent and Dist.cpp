#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1);
    vector<int> dis(n + 1);
    vector<int> par(n + 1);

    queue<int> q;

    int s;
    cin >> s;

    vis[s] = 1;
    par[s] = -1;
    q.push(s);

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (auto it : adj[f]) {
            if (!vis[it]) {
                vis[it] = 1;
                dis[it] = dis[f] + 1;
                par[it] = f;
                q.push(it);
            }
        }
    }

    int x;
    cin >> x;

    vector<int> path;

    while (x != -1) {
        path.push_back(x);
        x = par[x];
    }

    reverse(path.begin(), path.end());

    for (auto it : path)
        cout << it << ' ';

    cout << '\n';

    return 0;
}
