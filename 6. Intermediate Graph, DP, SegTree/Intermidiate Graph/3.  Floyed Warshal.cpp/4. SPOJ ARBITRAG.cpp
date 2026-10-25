// Problem: https://www.spoj.com/problems/ARBITRAG/en/


#include <bits/stdc++.h>
 
using namespace std;
 
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

const int N = 35;
const int INF = LLONG_MAX / 4;

double dist[N][N];
map < string, int > mp;

void solve(int n, int t) {
    cout << "Case " << t << ": ";

    mp.clear();

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[s] = i;
    }

    // Initialize exchange rates
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = 0.0;
        }
        dist[i][i] = 1.0;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string a, b;
        double r;
        cin >> a >> r >> b;
        dist[mp[a]][mp[b]] = r;
    }

    // Floyd-Warshall: maximize exchange rates
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = max(dist[i][j],
                                 dist[i][k] * dist[k][j]);
            }
        }
    }

    // A rate greater than 1 indicates arbitrage
    bool arb = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] > 1.0) {
            arb = true;
            break;
        }
    }

    cout << (arb ? "Yes" : "No") << endl;
}

signed main() {
    FAST_IO;

    int n, t = 1;
    while (cin >> n && n) {
        solve(n, t++);
    }

    return 0;
}

