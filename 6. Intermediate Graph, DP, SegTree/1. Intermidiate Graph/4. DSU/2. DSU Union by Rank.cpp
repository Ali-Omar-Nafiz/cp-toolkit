
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > parent, rankk;

void makeParent(int i) {
    parent[i] = i;
    rankk[i] = 0;
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

    if (rankk[pa] > rankk[pb]) {
        parent[pb] = pa;
    } else if (rankk[pa] < rankk[pb]) {
        parent[pa] = pb;
    } else {
        parent[pb] = pa;
        rankk[pa]++;
    }
}

void init(int n) {
    parent.assign(n + 1, 0);
    rankk.assign(n + 1, 0);

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

