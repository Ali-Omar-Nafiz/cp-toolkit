// https://cses.fi/problemset/task/1642
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

const int MOD = 998244353;
 
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector < pair < int, int > > v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back({x, i + 1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j + 1 < n; j++) {
            int target = x - v[i].first - v[j].first;
            int l = j + 1, r = n - 1, sum = 0;
            while (l < r) {
                int sum = v[l].first + v[r].first;
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    cout << v[i].second << " " << v[j].second << " " << v[l].second << " " << v[r].second << endl;
                    return;
                }
            }
        }
    }
    cout << "-1" << endl;
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
