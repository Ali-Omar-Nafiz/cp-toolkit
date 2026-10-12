#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m;
vector<int> adj[N];
int col[N];
bool hasCycle;
vector<int>topsort;
int dfs(int node){
    col[node] = 1; 
    for(auto it:adj[node]){
        if(col[it]==0){
            dfs(it);
        }
        else 
        {
            if(col[it]==1){
                hasCycle = 1;
            }
        }
    }
    col[node] =2;
    topsort.push_back(node);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==0){
            dfs(i);
        }
    }
    reverse(topsort.begin(),topsort.end());
    for(auto it:topsort){
        cout<<it<<' ';
    }
    cout<<endl;
}
