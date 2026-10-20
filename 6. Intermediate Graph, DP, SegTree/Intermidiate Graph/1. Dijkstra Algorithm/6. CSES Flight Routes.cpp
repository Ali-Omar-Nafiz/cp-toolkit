// Problem: https://cses.fi/problemset/task/1196/

#include <bits/stdc++.h>
 
using namespace std;
 
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector < vector < pair < int, int > > > adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    vector < int > dist(n + 1);
    dist[1] = 0;
    multiset < pair < int, int > > st;
    st.insert({0, 1});
    vector < int > ans;
    map < int, int > cnt;
    while (!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        cnt[u]++;
        if (cnt[u] > k) {
            continue;
        }
        if (u == n) {
            ans.push_back(d);
        }
        for (auto [w, v]: adj[u]) {
            dist[v] = d + w;
            st.insert({dist[v], v});
        }
    }
    for (auto x: ans) {
        cout << x << " ";
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
