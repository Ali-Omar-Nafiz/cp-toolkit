#include <bits/stdc++.h>
 
using namespace std;
 
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector < array < int, 3 > > edgeList;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back({a, b, c});
    }
    vector < int > dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (auto [a, b, c]: edgeList) {
            if (dist[a] != LLONG_MAX && (dist[a] + c < dist[b])) {
                dist[b] = dist[a] + c;
                flag = false;
            }
        }
        if (flag) {
            break;
        }
        if (i == n) {
            cout << "Negative Cycle Detected!" << endl;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}
 
signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}
