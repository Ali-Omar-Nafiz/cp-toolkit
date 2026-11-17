
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

    if (sz[pa] < sz[pb]) {
        swap(pa, pb);
    }

    parent[pb] = pa;
    sz[pa] += sz[pb];
}

void init(int n) {
    parent.assign(n + 1, 0);
    sz.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        makeParent(i);
    }
}

signed main() {
    FAST_IO;

    int n;
    cin >> n;

    init(n);

    return 0;
}

