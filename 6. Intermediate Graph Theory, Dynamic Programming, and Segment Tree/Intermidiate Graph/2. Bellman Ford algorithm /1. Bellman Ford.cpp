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

        vector<tuple<int, int, ll>> edges(m);

        for (auto &[u, v, w] : edges) {
            cin >> u >> v >> w;
        }

        vector<ll> dist(n + 1, INF);
        dist[1] = 0;

        // Bellman-Ford: relax all edges up to n times.
        for (int i = 1; i <= n; i++) {
            bool updated = false;

            for (auto [u, v, w] : edges) {
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }

            // No updates means shortest distances are finalized.
            if (!updated) break;

            // An update on the nth iteration indicates a reachable negative cycle.
            if (i == n) {
                // Negative cycle detected.
            }
        }
    }

    return 0;
}
