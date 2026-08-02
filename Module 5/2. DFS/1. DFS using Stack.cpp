// DFS implementation using stack (TC = O(V + E))
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int > > adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int s;
    cin >> s;
    vector < bool > vis(n + 1);
    stack < int > stk;
    stk.push(s);
    vis[s] = true;
    while (!stk.empty()) {
        int t = stk.top();
        bool chk = true;
        for (auto x: adjList[t]) {
            if (!vis[x]) {
                stk.push(x);
                vis[x] = true;
                chk = false;
                break;
            }
        }
        if (chk) {
            stk.pop();
        }
    }
    return 0;
}
