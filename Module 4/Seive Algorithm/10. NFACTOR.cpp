// https://www.spoj.com/problems/NFACTOR/
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 1000001 > isNotPrime;
vector < int > primeFactorCnt(1000001);
vector < vector < int > > preCheck(11, vector < int > (1000001));

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
    vector < int > primes;
    primes.push_back(2);
    for (int i = 3; i <= 1000000; i += 2) {
        if (!isNotPrime[i]) {
            primes.push_back(i);
        }
    }
    for (int i = 0; i < primes.size(); i++) {
        int a = primes[i];
        for (int j = a; j <= 1000000; j += a) {
            primeFactorCnt[j]++;
        }
    }
}

void pCheck() {
    preCheck[0][1] = 1;
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j <= 1000000; j++) {
            if (primeFactorCnt[j] == i) {
                preCheck[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < 11; i++) {
        for (int j = 1; j <= 1000000; j++) {
            preCheck[i][j] += preCheck[i][j - 1];
        }
    }
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    cout << preCheck[n][b] - preCheck[n][a - 1] << endl;
}

signed main() {
    FAST_IO;
    sieve();
    pCheck();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
