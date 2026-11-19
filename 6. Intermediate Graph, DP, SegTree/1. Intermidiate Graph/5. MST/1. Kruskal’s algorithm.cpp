#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int par[N], sz[N];

void make(int i) {
    par[i] = i;
    sz[i] = 1;
}

int find(int i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) make(i);        // one set per NODE

    vector<array<int, 3>> edges;                 // {weight, u, v}
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());            // cheapest edges first

    long long mst = 0;
    for (auto [w, u, v] : edges) {
        if (find(u) != find(v)) {                // no cycle, so take this edge
            mst += w;
            join(u, v);
        }
    }

    cout << mst << "\n";
}
