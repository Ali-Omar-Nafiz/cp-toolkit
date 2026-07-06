// https://toph.co/p/life-of-phi
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define int long long
#define int long long

vector < int > phi(1000001);

void phi1ToN() {
    for (int i = 1; i < 1000001; i++) {
        phi[i] = i;
    }
    for (int i = 2; i < 1000001; i++) {
        if (phi[i] == i) {
            for (int j = i; j < 1000001; j += i) {
                phi[j] -= (phi[j] / i);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    sum -= n;
    sum -= phi[n] * n / 2;
    cout << sum << endl;
}

signed main() {
    FAST_IO;
    phi1ToN();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
