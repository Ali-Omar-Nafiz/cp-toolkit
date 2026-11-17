// Problem: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > par, sz;

void init(int x) {
    par[x] = x;
    sz[x] = 1;
}

int find(int a) {
    if (par[a] == a) {
        return a;
    }
    return par[a] = find(par[a]);
}

void join(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) {
        return;
    }
    if (sz[pa] < sz[pb]) {
        swap(pa, pb);
    }
    par[pb] = pa;
    sz[pa] += sz[pb];
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    par.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        init(i);
    }
    vector < vector < int > > adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector < tuple < string, int, int > > v;
    while (q--) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        v.push_back({s, a, b});
    }
    reverse(v.begin(), v.end());
    vector < string > ans;
    for (int i = 0; i < v.size(); i++) {
        auto [s, a, b] = v[i];
        if (s == "ask") {
            if (find(a) == find(b)) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        } else {
            join(a, b);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x: ans) {
        cout << x << endl;
    }
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
