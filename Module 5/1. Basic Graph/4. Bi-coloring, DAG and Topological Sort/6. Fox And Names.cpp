#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

bool isCycle;

vector < vector < int > > adjList(26);
vector < int > color(26);
vector < int > order;

void dfs (int cur) {
    color[cur] = 1;
    for (auto x: adjList[cur]) {
        if (color[x] == 0) {
            dfs(x);
        } else if (color[x] == 1) {
            isCycle = true;
        }
    }
    color[cur] = 2;
    order.push_back(cur);
}

void solve() {
    int n;
    cin >> n;
    vector < string > s;
    for (int i = 0; i < n; i++) {
        string in;
        cin >> in;
        s.push_back(in);
    }
    for (int i = 1; i < n; i++) {
        bool chk = true;
        for (int j = 0; j < min(s[i].size(), s[i - 1].size()); j++) {
            if (s[i][j] != s[i - 1][j]) {
                adjList[(s[i - 1][j] - 'a')].push_back((s[i][j] - 'a'));
                chk = false;
                break;
            }
        }
        if (chk && s[i - 1].size() > s[i].size()) {
            cout << "Impossible" << endl;
            return;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    if (isCycle) {
        cout << "Impossible" << endl;
        return;
    }
    reverse(order.begin(), order.end());
    for (auto x: order) {
        cout << char(x + 'a');
    }
    cout << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
      // cout << "Case " << i << ": \n";
      solve();
    }
    return 0;
}