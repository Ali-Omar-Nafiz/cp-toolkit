// Problem: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > par, sz, mn, mx;

void init(int x) {
    par[x] = x;
    sz[x] = 1;
    mn[x] = x;
    mx[x] = x;
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
    mn[pa] = min(mn[pa], mn[pb]);
    mx[pa] = max(mx[pa], mx[pb]);
}

void solve() {
    int n, q;
    cin >> n >> q;
    par.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    mn.assign(n + 1, 0);
    mx.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        init(i);
    }
    while (q--) {
        string type;
        cin >> type;
        if (type == "union") {
            int a, b;
            cin >> a >> b;
            join(a, b);
        } else {
            int x;
            cin >> x;
            x = find(x);
            cout << mn[x] << " " << mx[x] << " " << sz[x] << endl;
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
