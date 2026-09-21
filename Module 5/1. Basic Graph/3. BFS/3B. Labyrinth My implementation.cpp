#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

const vector < int > dx = {-1, 1, 0, 0};
const vector < int > dy = {0, 0, -1, 1};
const vector < char > directon = {'U', 'D', 'L', 'R'};

bool isValid(int x, int y, int n, int m) {
    if ((x < 0) || (y < 0) || (x >= n) || (y >= m)) {
        return false;
    } else {
        return true;
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector < string > s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.push_back(x);
    }
    int sx = -1, sy = -1, dsx = -1, dsy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                sx = i, sy = j;
            }
            if (s[i][j] == 'B') {
                dsx = i, dsy = j;
            }
        }
    }
    vector < vector < bool > > vis(n, vector < bool > (m));
    vector < vector < int > > dist(n, vector < int > (m, -1));
    vector < vector < char > > move(n, vector < char > (m));
    vector < vector < pair < int, int > > > parent(n + 1, vector < pair < int, int > > (m));
    queue < pair < int, int > > q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    parent[sx][sy] = {-1, -1};
    dist[sx][sy] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny, n , m) && s[nx][ny] != '#' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                move[nx][ny] = directon[i];
                q.push({nx, ny});
            }
        }
    }
    if (dist[dsx][dsy] == -1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << dist[dsx][dsy] << endl;
    vector < char > ans;
    while (parent[dsx][dsy] != make_pair(-1ll, -1ll)) {
        ans.push_back(move[dsx][dsy]);
        auto[x, y] = parent[dsx][dsy];
        dsx = x, dsy = y;
    }
    reverse(ans.begin(), ans.end());
    for (auto x: ans) {
        cout << x;
    }
    cout << endl;
}
 
signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
}
