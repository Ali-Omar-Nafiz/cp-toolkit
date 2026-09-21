// Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (auto &x : a) cin >> x;

    int lis[n], prev[n];

    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        prev[i] = -1;

        // Find LIS ending at i
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Find the last index of LIS
    int ans = 1, idx = 0;

    for (int i = 0; i < n; i++) {
        if (lis[i] > ans) {
            ans = lis[i];
            idx = i;
        }
    }

    cout << ans << nl;

    // Reconstruct LIS
    vector<int> seq;

    while (idx != -1) {
        seq.push_back(a[idx]);
        idx = prev[idx];
    }

    reverse(seq.begin(), seq.end());

    for (auto x : seq) cout << x << ' ';
    cout << nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
