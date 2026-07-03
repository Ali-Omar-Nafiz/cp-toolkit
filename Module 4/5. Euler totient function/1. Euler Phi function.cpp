// Euler phi function
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
            /*
            result = result * ((i - 1) / i);
         => result = result (1 - (1 / i))
         => result = result - (result / i)
            */
            result -= (result / i);

        }                                // TC:  sqrt(n)..can be optimized using more optimized prime factorization
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
// https://cp-algorithms.com/algebra/phi-function.html
/*
phi(n) = count of number of x's in range [1, n) such that gcd(n, x) = 1. Means n and x are relative prime or coprime

phi(p) = p - 1;   // for prime number
phi(p ^ y) = p^y - (p^y / p) = p^y * (1 - (1 / p)) = p^y * ((p - 1) / p)    // for single prime factor containg number
phi(a * b) = phi(a) * phi(b) // from chinese reminder theorem, where a and b are relative prime
phi(N) = phi(p1^x * p2^y) = phi(p1^x) * phi(p2^y) = p1^x * ((p1 - 1) / p1) * p2^y * ((p2 - 1) / p2)  // for all number

Final Formula:
phi(N) = N * ((p1 - 1) / p1) * ((p2 - 1) / p2) * ...  // For all numbers
phi(1) = 1
*/
