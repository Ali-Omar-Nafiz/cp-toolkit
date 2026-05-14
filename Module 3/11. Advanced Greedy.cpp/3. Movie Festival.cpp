// https://cses.fi/problemset/task/1629
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long
 
bool cmp(pair < int, int > &a, pair < int, int > &b) {
    return a.second < b.second;
}
 
void solve() {
    int n;
    cin >> n;
    vector < pair < int, int > > v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0, lst = -1;
    for (int i = 0; i < n; i++) {
        if (v[i].first >= lst) {
            cnt++;
            lst = v[i].second;
        }
    }
    cout << cnt << endl;
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
