// https://codeforces.com/contest/2236/problem/F1
#include <bits/stdc++.h>
 
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;

bitset < 1000001 > isNP;
vector < int > spf(1000001);

void sieve() {
    isNP[1] = 1, isNP[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        spf[i] = i;
    }
    for (int i = 4; i <= 1000000; i += 2) {
        isNP[i] = 1;
        spf[i] = 2;
    }
    for (int i = 3; i * i <= 1000000; i += 2) {
        if (!isNP[i]) {
            for (int j = i * i; j <= 1000000; j += (2 * i)) {
                isNP[j] = 1;
                spf[j] = i;
            }
        }
    }
}

void solve() {
    int n, t;
    cin >> n >> t;
    map < int, int > mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            mp[spf[x]]++;
            x /= spf[x];
        }
    }
    int ans = 1;
    for (auto [x, y]: mp) {
        ans = ((ans % MOD) * ((y + 1) % MOD)) % MOD;
    }
    cout << ans << endl;
}

signed main() {
    FAST_IO;
    sieve();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl << endl;
        solve();
    }
    return 0;
}
