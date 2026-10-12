// Problem: https://codeforces.com/problemset/problem/1725/M
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector < vector < pair < int, int > > > adj(2 * n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[n + b].push_back({c, n + a});
    }
    for (int i = 1; i <= n; i++) {
        adj[i].push_back({0, i + n});
    }
    vector < int > dist(2 * n + 1, LLONG_MAX);
    dist[1] = 0;
    set < pair < int, int > > st;
    st.insert({0, 1});
    while (!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        for (auto [w, v]: adj[u]) {
            if (w + dist[u] < dist[v]) {
                st.erase({dist[v], v});
                dist[v] = w + d;
                st.insert({dist[v], v});
            }
        }
    }
    for (int i = n + 2; i <= 2 * n; i++) {
        cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << " ";
    }
    cout << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#Case: " << i << ": " << endl;
        solve();
    }
    return 0;
}
