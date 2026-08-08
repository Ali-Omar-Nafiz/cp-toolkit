// BFS
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int > > adj(n + 1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector < bool > vis(n + 1);
    queue < int > q;
    int s;
    cin >> s;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto &it: adj[f]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] = true;
            }
        }
    }
    return 0;
}
// Dfs can find only tree's shortest path (because there is only one path from source to any node)
// Bfs can find shortest path of every graph
