// https://www.spoj.com/problems/LASTDIG/en/

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

int modPow(int a, int b, int m) {
    int ans = 1;
    while (b > 0) {
        a %= m;
        if (b & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void solve() {
    string a;
    int b;
    cin >> a >> b;
    cout << modPow(a.back() - '0', b, 10) << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
}
