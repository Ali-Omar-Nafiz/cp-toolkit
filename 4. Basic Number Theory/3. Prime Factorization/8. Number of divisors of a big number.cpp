// https://www.hackerearth.com/problem/algorithm/number-of-divisors-5/
#include <bits/stdc++.h>
 
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 1000001 > isNP;
vector < int > primes;

void sieve() {
    isNP[0] = 1, isNP[1] = 1;
    for (int i = 4; i < 1000001; i += 2) {
        isNP[i] = 1;
    }
    for (int i = 3; i * i < 1000001; i += 2) {
        if (!isNP[i]) {
            for (int j = i * i; j < 1000001; j += (2 * i)) {
                isNP[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i < 1000001; i += 2) {
        if (!isNP[i]) {
            primes.push_back(i);
        }
    }
}
 
void solve() {
    int n;
    cin >> n;
    int ans = 1;
    for (auto i: primes) {
        if (i * i > n) {
            break;
        }
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        ans *= (cnt + 1);
    }
    if (n > 1) {
        ans *= 2;
    }
    cout << ans << endl;
}

signed main() {
    FAST_IO;
    sieve();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
// Using some basic combinatorics
// Time Complexity: O(sqrt(n) / logn);
// Every prime are pairwise independent
// with this method primality can be checked until 1e14. (if number of divisors == 2, it's a prime number)
