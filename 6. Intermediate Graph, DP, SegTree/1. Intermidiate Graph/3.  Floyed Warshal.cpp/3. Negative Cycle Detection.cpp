
#include <bits/stdc++.h>
 
using namespace std;
 
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long
 
const int INF = LLONG_MAX / 4;

void solve() {
    int n, m;
    cin >> n >> m;

    vector < vector < int > > dist(n + 1, vector < int > (n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        if (w < dist[a][b]) {
            dist[a][b] = w;
        }
    }

    // Floyd-Warshall: find shortest paths between all pairs
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // Skip unreachable intermediate paths
                if (dist[i][k] == INF || dist[k][j] == INF) {
                    continue;
                }

                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // A negative diagonal distance indicates a negative cycle
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative Cycle Found!" << endl;
            return;
        }
    }

    cout << "NO Negative Cycle Found!" << endl;
}
 
signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Scenario #" << i << endl;
        solve();
    }
    return 0;
}
v
