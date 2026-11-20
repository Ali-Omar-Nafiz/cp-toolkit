#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> par, sz;

void init(int x) {
    par[x] = x;
    sz[x] = 1;
}

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    par[b] = a;
    sz[a] += sz[b];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    par.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) init(i);

    vector<array<int, 3>> edgeList;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({w, u, v});
        edgeList.push_back({w, v, u});
    }
    sort(edgeList.begin(), edgeList.end());

    vector<array<int, 3>> mstEdge;
    vector<vector<pair<int, int>>> mstAdj(n + 1); // {neighbor, weight}
    int ans = 0;

    for (auto [w, u, v] : edgeList) {
        if (find(u) != find(v)) {
            ans += w;
            mstEdge.push_back({u, v, w});
            mstAdj[u].push_back({v, w});
            mstAdj[v].push_back({u, w});
            join(u, v);
        }
    }

    cout << ans << "\n";
    for (auto [u, v, w] : mstEdge)
        cout << u << " " << v << " " << w << "\n";
}
