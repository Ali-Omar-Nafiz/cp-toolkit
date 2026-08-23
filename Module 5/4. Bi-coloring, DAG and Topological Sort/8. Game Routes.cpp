#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int MOD = 1e9+7;
vector<int> adj[N];
int col[N];
bool hasCycle;
vector<int> topsort;
int n, m;
void dfs(int cur)
{
    col[cur] = 1;
    for (auto &it : adj[cur])
    {
        if (col[it] == 0)
        {
            dfs(it);
        }
        else if (col[it] == 1)
        {
            hasCycle = 1;
        }
    }
    col[cur] = 2;
    topsort.push_back(cur);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 0)
        {
            dfs(i);
        }
    }
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (auto &i : topsort)
    {
        for(auto &it:adj[i]){
            dp[i] += dp[it];
            dp[i] %= MOD;
        }
    }
    cout << dp[1] << endl;
    
}