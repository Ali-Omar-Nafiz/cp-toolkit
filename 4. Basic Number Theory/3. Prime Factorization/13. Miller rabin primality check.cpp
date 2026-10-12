#include <bits/stdc++.h>
 
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

using ull = unsigned long long;
using u128 = __uint128_t;

ull mod_mul(ull a, ull b, ull mod) {
    return (u128)a * b % mod;
}

ull mod_pow(ull a, ull d, ull mod) {
    ull res = 1;
    while (d) {
        if (d & 1) res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        d >>= 1;
    }
    return res;
}

bool isPrime(ull n) {   // copy paste
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;
    ull d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }
    for (ull a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a % n == 0) continue;
        ull x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (ull r = 1; r < s; ++r) {
            x = mod_mul(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}
 
void solve() {
    cout << isPrime(18446744073709551615ull) << endl;
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
// Largest supported n: 18446744073709551615ULL (2^64−1)
// Worst-case complexity: O(7 log n) modular multiplications (effectively O(log n) since the number of witnesses is constant).
// Typical capacity in a 1-second contest: around 10⁶ primality checks on a modern judge.
