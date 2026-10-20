// Problem: https://codeforces.com/contest/10/problem/D
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n;
    cin >> n;
    vector < int > a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector < int > b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    vector < vector < int > > lcis(n + 1, vector < int > (m + 1));
    vector < vector < int > > pMax(n + 1, vector < int > (m + 1));
    for (int j = 1; j <= m; j++) {
        if (a[1] == b[j]) {
            lcis[1][j] = 1;
        }
    }
    for (int j = 1; j <= m; j++) {
        pMax[1][j] = max(pMax[1][j - 1], lcis[1][j]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                lcis[i][j] = 1;
                for (int k = i - 1; k >= 1; k--) {
                    if (a[k] < a[i]) {
                        lcis[i][j] = max(lcis[i][j], 1 + pMax[k][j - 1]);
                    }
                }
            }
        }
        for (int j = 1; j <= m; j++) {
            pMax[i][j] = max(pMax[i][j - 1], lcis[i][j]);
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, pMax[i][m]);
    }
    cout << ans << endl;
    vector < int > seq;
    int tar = ans;
    int col = m, row = n;
    while (tar > 0) {
        while (row > 0 && col > 0 && pMax[row][col] != tar) {
            row--;
        }
        while (row > 0 && col > 0 && lcis[row][col] != tar) {
            col--;
        }
        seq.push_back(a[row]);
        tar--;
    }
    reverse(seq.begin(), seq.end());
    for (auto x: seq) {
        cout << x << " ";
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
    
    return 0;
}
