// https://www.spoj.com/problems/DCEPC505/en/
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 100000001 > isPrime;
bitset < 106000001 > isTaken;
vector < int > primes, ans;
int lastNum = 106000000;   // random guess

void sieve() {
    // Sieve
    for (int i = 4; i <= 100000000; i += 2) {
        isPrime[i] = true;
    }
    for (int i = 3; i * i <= 100000000; i += 2) {
        if (!isPrime[i]) {
            for (int j = i * i; j <= 100000000; j += (2 * i)) {
                isPrime[j] = true;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= 100000000; i += 2) {
        if (!isPrime[i]) {
            primes.push_back(i);
        }
    }
    int P = primes.size();
    for (int i = 0; i < P; i++) {
        int prime1 = primes[i];
        for (int j = i + 1; j < P; j++) {
            int prime2 = primes[j];
            int specialNum = prime1 * prime2;
            if (specialNum <= lastNum) {
                isTaken[specialNum] = true;
            }
            else {
                break;
            }
        }
    }
    for (int i = 6; i <= lastNum; i++) {
        if (isTaken[i]) {
            ans.push_back(i);
        }
    }
}

void solve() {
    int k;
    cin >> k;
    cout << ans[k - 1] << endl;
}

signed main() {
    FAST_IO;
    sieve();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
