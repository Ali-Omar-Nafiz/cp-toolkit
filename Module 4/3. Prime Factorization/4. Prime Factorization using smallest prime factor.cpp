// Time Complexity - O(logN)
#include <bits/stdc++.h>
 
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 100000001 > isNP;
vector < int > spf(100000001);
 
void sieve() {
    isNP[1] = 1, isNP[0] = 1;
    for (int i = 1; i <= 100000000; i++) {
        spf[i] = i;
    }
    for (int i = 4; i <= 100000000; i += 2) {
        isNP[i] = 1;
        spf[i] = 2;
    }
    for (int i = 3; i * i <= 100000000; i += 2) {
        if (!isNP[i]) {
            for (int j = i * i; j <= 100000000; j += (2 * i)) {
                isNP[j] = 1;
                spf[j] = i;
            }
        }
    }
}
 
void solve() {
    int n;   // Highest range is same as the highest range of sieve
    cin >> n;
    while (n > 1) {
        cout << spf[n] << " ";
        n /= spf[n];
    }
    cout << endl;
}

signed main() {
    FAST_IO;
    sieve();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl << endl;
        solve();
    }
    return 0;
}
