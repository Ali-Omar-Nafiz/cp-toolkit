// https://cses.fi/problemset/task/1079/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > factorial(1e6 + 1);

int modpow2(int a, int b) {
    int ans = 1;
    while (b > 0) {
        a %= MOD;
        if (b & 1) ans = (ans * a) % MOD;
        b >>= 1, a *= a;
    }
    return ans;
}

int modinv(int a) {
    return modpow2(a, MOD - 2);
}

int mult(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int divi(int a, int b) {
    return mult(a, modinv(b));
}

void fact() {
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i < 1e6 + 1; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = divi(factorial[a], mult(factorial[b], factorial[a - b]));
    cout << ans << endl;
}

signed main() {
    FAST_IO;
    fact();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
}
