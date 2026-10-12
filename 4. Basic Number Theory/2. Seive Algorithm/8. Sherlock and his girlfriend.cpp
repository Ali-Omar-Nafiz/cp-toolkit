// https://codeforces.com/contest/776/problem/B
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 1000001 > isNotPrime;

void sieve() {
    isNotPrime[1] = true;
    for (int i = 4; i <= 1000000; i += 2) {
        isNotPrime[i] = true;
    }
    for (int i = 3; i * i <= 1000000; i += 2) {
        for (int j = i * i; j <= 1000000; j += (2 * i)) {
            isNotPrime[j] = true;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
    for (int i = 2; i <= n + 1; i++) {
        if (!isNotPrime[i]) {
            cout << 1 << " ";
        } else {
            cout << 2 << " ";
        }
    }
    cout << endl;
}

signed main() {
    FAST_IO;
    sieve();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
