// https://codeforces.com/contest/26/problem/A
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 3001 > isNotPrime;
vector < int > divCnt(3001);

void run() {
    isNotPrime[1] = true;
    for (int i = 4; i <= 3000; i += 2) {
        isNotPrime[i] = true;
    }
    for (int i = 3; i * i <= 3000; i += 2) {
        for (int j = i * i; j <= 3000; j += (2 * i)) {
            isNotPrime[j] = true;
        }
    }
    vector < int > primes;
    for (int i = 1; i <= 3000; i++) {
        if (!isNotPrime[i]) {
            primes.push_back(i);
        }
    }
    for (int i = 0; i < primes.size(); i++) {
        int a = primes[i];
        for (int j = a; j <= 3000; j += a) {
            divCnt[j]++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (divCnt[i] == 2) {
            ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    FAST_IO;
    run();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
