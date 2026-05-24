#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

// Sieve array: Assume all numbers are prime initially.
// Using boolean vector is highly memory efficient.
vector < bool > isPrime(1e7 + 5, true);

void sieveOfEratosthenes() {
    // 0 and 1 are mathematically not prime
    isPrime[0] = false;
    isPrime[1] = false;
    int n = 1e7;
    
    // Check up to sqrt(n). 
    // Why? Factors mirror around sqrt(n). Any composite number <= n 
    // is guaranteed to have a prime factor <= sqrt(n).
    for (int i = 2; i * i <= n; i++) {
        
        // If 'i' hasn't been crossed out, it must be a prime
        if (isPrime[i] == true) {
            
            // Cross out all multiples of this prime 'i'.
            // Why start at i * i? Because smaller multiples (e.g., i * 2, i * 3) 
            // were already crossed out when we processed the smaller primes (2, 3).
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// Dummy solve function just to make the template compilable
void solve() {
    // Your per-testcase logic goes here
}

signed main() {
    // Precompute primes once before handling any test cases
    sieveOfEratosthenes(); 
    FAST_IO;
    
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
