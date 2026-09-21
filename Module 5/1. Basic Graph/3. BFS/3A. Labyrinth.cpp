#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char dir[] = {'L', 'R', 'U', 'D'};

bool isValid(int x, int y, int n, int m)
{
    if (x < 0 or y < 0)
        return false;
    if (x >= n or y >= m)
        return false;
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int sx, sy, dsx, dsy;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'A')
            {
                sx = i, sy = j;
            }

            if (s[i][j] == 'B')
            {
                dsx = i, dsy = j;
            }
        }
    }

    vector<vector<int>> vis(n, vector<int>(m));
    vector<vector<int>> dis(n, vector<int>(m));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));
    vector<vector<char>> move(n, vector<char>(m));

    queue<pair<int, int>> q;

    q.push(make_pair(sx, sy));
    vis[sx][sy] = 1;

    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();

        int x = f.first, y = f.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (isValid(nx, ny, n, m) and s[nx][ny] != '#' and !vis[nx][ny])
            {
                vis[nx][ny] = 1;
                dis[nx][ny] = dis[x][y] + 1;
                par[nx][ny] = make_pair(x, y);
                move[nx][ny] = dir[i];

                q.push(make_pair(nx, ny));
            }
        }
    }

    if (!vis[dsx][dsy])
    {
        cout << "NO" << endl;
        return 0;
    }

    vector<char> ans;

    int x = dsx, y = dsy;

    while (x != sx or y != sy)
    {
        ans.push_back(move[x][y]);

        int px = par[x][y].first;
        int py = par[x][y].second;

        x = px;
        y = py;
    }

    reverse(ans.begin(), ans.end());

    cout << "YES" << endl;
    cout << ans.size() << endl;

    for (auto it : ans)
        cout << it;

    cout << endl;

    return 0;
}
