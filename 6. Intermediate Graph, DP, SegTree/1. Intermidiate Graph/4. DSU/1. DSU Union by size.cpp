// Problem: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > parent, sz;

void makeParent(int i) {
    parent[i] = i;
    sz[i] = 1;
}

int find(int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

void join(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) {
        return;
    }

    if (sz[pa] >= sz[pb]) {
        parent[pb] = pa;
        sz[pa] += sz[pb];
    } else {
        parent[pa] = pb;
        sz[pb] += sz[pa];
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    parent.assign(n + 1, 0);
    sz.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        makeParent(i);
    }

    while (q--) {
        string op;
        int a, b;
        cin >> op >> a >> b;

        if (op == "union") {
            join(a, b);
        } else {
            cout << (find(a) == find(b) ? "YES" : "NO") << endl;
        }
    }
}

signed main() {
    FAST_IO;
    solve();
    return 0;
}

