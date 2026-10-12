// https://www.spoj.com/problems/ETF/
#include <bits/stdc++.h>
 
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int unsigned long long            // important to keep unsigned

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= (result / i);  
        } // sqrt(n)..can be optimized using more optimized prime factorization
    }
    if (n > 1) {
        result -= (result / n); 
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    cout << phi(n) << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
