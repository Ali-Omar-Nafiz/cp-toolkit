// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=484
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 1000001 > isNotPrime;
vector < int > primes;

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
    for (int i = 3; i <= 1000000; i += 2) {
        if (!isNotPrime[i]) {
            primes.push_back(i);
        }
    }
}

void solve() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        bool flag = true;
        for (int i = 0; i < primes.size(); i++) {
            int a = primes[i];
            int b = n - a;
            if (!isNotPrime[b]) {
                cout << n << " = " << a << " + " << b << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }
}

signed main() {
    FAST_IO;
    sieve();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
