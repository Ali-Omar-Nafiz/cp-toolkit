// Problem: https://vjudge.net/problem/UVA-11280

#include <bits/stdc++.h>
 
using namespace std;
 
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long
 
void solve() {
    int n;
    cin >> n;
    map < string, int > city;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        city[s] = i;
    }
    int m;
    cin >> m;
    vector < array < int, 3 > > edg;
    for (int i = 0; i < m; i++) {
        string s, d;
        cin >> s >> d;
        int w;
        cin >> w;
        edg.push_back({city[s], city[d], w});
    }
    vector < vector < int > > dist(n + 1, vector < int > (n + 1, LLONG_MAX));
    dist[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        dist[i] = dist[i - 1];
        for (auto [u, v, w]: edg) {
            if (dist[i - 1][u] != LLONG_MAX && dist[i][v] > dist[i - 1][u] + w) {
                dist[i][v] = dist[i - 1][u] + w;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x = min(x + 1, n);
        if ( x <= n && dist[x][n] != LLONG_MAX) {
            cout << "Total cost of flight(s) is $" << dist[x][n] << endl;
        } else {
            cout << "No satisfactory flights" << endl;
        }
    }
}
 
signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Scenario #" << i << endl;
        solve();
        if (i != t) {
            cout << endl;
        }
    }
    return 0;
}
