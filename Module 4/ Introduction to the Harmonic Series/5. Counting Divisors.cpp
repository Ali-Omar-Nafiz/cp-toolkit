// https://cses.fi/problemset/task/1713/
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > divs(1e6 + 5);

void run() {
    for (int i = 1; i < divs.size(); i++) {
        for (int j = i; j < divs.size(); j += i) {
            divs[j]++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << divs[x] << endl;
    }
}

signed main() {
    FAST_IO;
    run();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
