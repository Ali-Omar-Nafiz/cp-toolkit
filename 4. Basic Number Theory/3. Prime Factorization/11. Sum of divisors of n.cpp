// sum of divisors
#include <bits/stdc++.h>
 
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 100000001 > isNP;
vector < int > primes;

void sieve() {
    isNP[1] = 1;
    for (int i = 4; i < 100000001; i += 2) {
        isNP[i] = 1;
    }
    for (int i = 3; i * i < 100000001; i += 2) {
        if (!isNP[i]) {
            for (int j = i * i; j < 100000001; j += (2 * i)) {
                isNP[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i < 100000001; i += 2) {
        if (!isNP[i]) {
            primes.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int sum = 1;
    for (auto &i: primes) {
        if (i * i > n) {
            break;
        }
        int multiplier = 1, cur = i;  // skiping first iteration (from the below method) by settig multiplier as 1 and cur as i
        // int cnt = 0;
        while (n % i == 0) {   // cnt iterations (below method for loop can be replaced)
            // cnt++;
            n /= i;
            multiplier += cur;
            cur *= i;
        }
        sum *= multiplier;
        /*
        int multiplier = 0;
        i^0 = 1
        i^1 = i
        i^2 = i*i
        i^3 = i*i*i
        ...
        i^x = i*.....*i
        
        for (int power = 0, curr = 1; power <= cnt; power++) {  // cnt + 1 iterations
            multiplier += curr;  +=(1, i, i * i, i * i * i, ....)
            curr *= i;   
        }
        sum *= multiplier;
        */
    }
    if (n > 1) {
        sum *= (1 + n);  // (remaing n is a prime. n^0 + n ^ 1 = 1 + n)
    }
    cout << sum << endl;
}

signed main() {
    FAST_IO;
    sieve();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": " << endl;
        solve();
    }
    return 0;
}
// Time complexity: O(sqrt(n) / logn);
/*
if n = P1^x + p2^y + p3^z...
then sum of divisors of n = (p1^0 + p1^1 + ... + p1^x) * (p2^0 + p2^1 + ... + p2^y) * ...
*/
