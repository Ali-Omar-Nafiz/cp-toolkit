#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

bool isCycle;

vector < vector < int > > adjList;
vector < int > color;
vector < int > order;

void dfs (int cur) {
    color[cur] = 1;
    for (auto x: adjList[cur]) {
        if (color[x] == 0) {
            dfs(x);
        } else if (color[x] == 1) {
            isCycle = true;
        }
    }
    color[cur] = 2;
    order.push_back(cur);
}

void solve() {
    int n, m;
    cin >> n >> m;
    adjList.assign(n + 1, {});
    color.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    if (isCycle) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    reverse(order.begin(), order.end());
    for (auto x: order) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
      // cout << "Case " << i << ": \n";
      solve();
    }
    return 0;
}