Imagine several villages connected by roads, where some groups of villages are completely disconnected from others. If a group has a circular route, one of its roads is redundant and can be removed and reused to connect that group to another disconnected group. The problem is to determine the minimum number of new roads needed to connect all the villages together.

#include<bits/stdc++.h>
using namespace std;
const int N = 100;

int n,m;
vector<int> adj[N];
int vis[N];
vector<int>component;
void bfs(int src){
    queue<int>q;
    vis[src] = 1;
    component.push_back(src);
    q.push(src);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto &it:adj[f]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
                component.push_back(it);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int com = 0;
    int extra = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(i);
            com++;
            int non = component.size();
            int edges = 0;
            for(auto &x:component){
                edges += adj[x].size();
            }
            edges/=2;
            if(edges>non-1){
                extra++;
            }
            component.clear();
        }
    }
    cout<<com<<endl;
    int ans = com-1;
    ans -= extra;
    if(ans<0){
        ans = 0;
    }
    cout<<ans<<endl;
    return 0;
}
