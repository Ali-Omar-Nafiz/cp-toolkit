#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Each edge stores {u, v, w}
        vector<array<ll, 3>> edges(m);

        for (auto &e : edges) {
            cin >> e[0] >> e[1] >> e[2];
        }

        vector<ll> dist(n + 1, INF);
        dist[1] = 0;

        // Bellman-Ford
        for (int i = 1; i <= n; i++) {
            bool updated = false;

            for (auto &e : edges) {
                ll u = e[0];
                ll v = e[1];
                ll w = e[2];

                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }

            if (!updated) break;

            if (i == n) {
                // Reachable negative cycle detected
            }
        }
    }

    return 0;
}
