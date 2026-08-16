// Bipartate and bi-coloring : je graph ke bi coloring kora possible
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m;
vector<int> adj[N];
int col[N];
bool impossible;
void dfs(int node, int currentColor)
{
    col[node] = currentColor;
    for (auto &it : adj[node])
    {
        if (col[it] == 0)
        {
            dfs(node, currentColor == 1 ? 2 : 1);
        }
        else{
            if(col[it]==currentColor){
                impossible = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==0){
            dfs(i,1);
        }
    }
}
