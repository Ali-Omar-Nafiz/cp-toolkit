// Problem: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > sz, par, val;

int sum(int x) {
    if (par[x] == x) {
        return val[x];
    }
    return val[x] + sum(par[x]);
}

void init(int x) {
    par[x] = x;
    sz[x] = 1;
}

int find(int a) {
    if (par[a] == a) {
        return a;
    }
    return find(par[a]);
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
    val[pb] -= val[pa];
}

void solve() {
    int n, m;
    cin >> n >> m;
    sz.assign(n + 1, 0);
    par.assign(n + 1, 0);
    val.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        init(i);
    }
    while (m--) {
        string s;
        cin >> s;
        if (s == "add") {
            int a, v;
            cin >> a >> v;
            val[find(a)] += v;
        } else if (s == "join") {
            int a, b;
            cin >> a >> b;
            join(a, b);
        } else {
            int x;
            cin >> x;
            cout << sum(x) << endl;
        }
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
