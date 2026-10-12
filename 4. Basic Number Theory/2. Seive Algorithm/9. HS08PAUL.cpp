// https://www.spoj.com/problems/HS08PAUL/
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 10000001 > isNotPrime;
vector < int > preCheck(10000001);

void sieve() {
    isNotPrime[1] = true;
    for (int i = 4; i <= 10000000; i += 2) {
        isNotPrime[i] = true;
    }
    for (int i = 3; i * i <= 10000000; i += 2) {
        for (int j = i * i; j <= 10000000; j += (2 * i)) {
            isNotPrime[j] = true;
        }
    }
}

void pCheck() {
    for (int i = 1; i * i <= 10000000; i++) {
        for (int j = 1; j * j * j * j <= 10000000; j++) {
            int cur = (i * i) + (j * j * j * j);
            if (cur <= 10000000 && !isNotPrime[cur]) {
                preCheck[cur] = 1;
            }
        }
    }
    for (int i = 1; i <= 10000000; i++) {
        preCheck[i] += preCheck[i - 1];
    }
}

void solve() {
    int n;
    cin >> n;
    cout << preCheck[n] << endl;
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
