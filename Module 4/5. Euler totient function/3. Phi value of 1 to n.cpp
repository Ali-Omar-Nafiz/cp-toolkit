// Euler phi function precalculate from 1 to n
#include <bits/stdc++.h>
 
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > phiVal(1000001);

void phi_1toN() {
    for (int i = 1; i <= 1000000; i++) {
        phiVal[i] = i;   // result = i initially
    }
    for (int i = 2; i <= 1000000; i++) {
        // isPrime(i) ?
        if (phiVal[i] == i) {   // untouched phival[i], means this is prime
            for (int j = i; j <= 1000000; j += i) {
                phiVal[j] -= (phiVal[j] / i);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << phiVal[n] << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    phi_1toN();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
