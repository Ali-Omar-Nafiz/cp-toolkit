#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n, m;
vector<int> adj[N];
int ind[N];

vector<int> topsort;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        ind[v]++;
    }

    queue<int> cur;

    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            cur.push(i);
        }
    }

    while (!cur.empty())
    {
        int f = cur.front();
        cur.pop();

        topsort.push_back(f);

        for (auto it : adj[f])
        {
            ind[it]--;

            if (ind[it] == 0)
            {
                cur.push(it);
            }
        }
    }

    if (topsort.size() != n)
    {
        cout << "Cycle exists\n";
        return 0;
    }

    for (auto it : topsort)
    {
        cout << it << ' ';
    }

    cout << '\n';
}
