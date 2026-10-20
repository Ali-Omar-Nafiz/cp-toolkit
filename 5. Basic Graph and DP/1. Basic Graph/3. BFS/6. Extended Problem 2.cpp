You are given a labyrinth containing a start cell A, an end cell B, open cells ., and walls #. You can move up, down, left, or right. However, you have a special ability that can be used at most once: you can break through a wall and move into that cell. Find the shortest path from A to B, considering whether the wall-breaking ability has already been used or not. If a path exists, output its length and the path; otherwise, output NO.

#include <bits/stdc++.h>
using namespace std;
#define ti tuple<int, int, int>
const int N = 100;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
string s[N];
int n, m;
int vis[N][N][2];
int dis[N][N][2];
pair<int, int> par[N][N];
int sx, sy, dx, dy;
bool isValid(int x, int y)
{
    if (x < 0 or y < 0)
        return 0;
    if (x >= n or y >= m)
        return 0;
    return 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int sx, sy, dsx, dsy;
    cin >> sx >> sy >> dsx >> dsy;
    queue<ti> q;
    vis[sx][sy][0] = 1;
    dis[sx][sy][0] = 0;
    q.push(make_tuple(sx, sy, 0));
    while (!q.empty())
    {
        ti f = q.front();
        int ux, uy, dh;
        tie(ux, uy, dh) = f;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if (isValid(nx, ny))
            {
                if (dh == 1)
                {
                    if (vis[nx][ny][1] == false and s[nx][ny] != '#')
                    {
                        vis[nx][ny][1] = true;
                        dis[nx][ny][1] = dis[ux][uy][dh] + 1;
                        q.push(make_tuple(nx,ny,1));
                    }
                }
                else
                {
                    if (vis[nx][ny][0] == false and s[nx][ny] != '#')
                    {
                        vis[nx][ny][0] = true;
                        dis[nx][ny][0] = dis[ux][uy][dh] + 1;
                        q.push(make_tuple(nx,ny,0));
                    }

                    if (vis[nx][ny][1] == false and s[nx][ny] == '#')
                    {
                        vis[nx][ny][1] = true;
                        dis[nx][ny][1] = dis[ux][uy][dh] + 1;
                        q.push(make_tuple(nx,ny,1));
                    }
                }
            }
        }
    }
    return 0;
}
