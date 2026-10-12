// https://cses.fi/problemset/task/1642
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector < int > v;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }
    map < int, pair < int, int > > left, right;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = v[i] + v[j];
            if (!left.count(sum) || (left[sum].second > j + 1)) {
                left[sum] = {i + 1, j + 1};
            }
        }
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            int sum = v[i] + v[j];
            if (!right.count(sum) || right[sum].second < i + 1) {
                right[sum] = {j + 1, i + 1};
            }
        }
    }
    for (auto [a, b]: left) {
        int cur = a;
        int rem = x - cur;
        if (right.count(rem)) {
            if (right[rem].first > left[cur].second) {
                cout << left[cur].first << " " << left[cur].second << " ";
                cout << right[rem].first << " " << right[rem].second << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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
