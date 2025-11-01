#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int M = 1e5;
const int M2 = 2e5;
const int OO = 1e9 + 7;
const ll MOD = 998244353;
const double PI = 2 * acos(0.0);

#define testcase int tc; cin >> tc; for (int i = 1; i <= tc; i++)
#define int long long

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

int stringToInt(const string& s) {
    int i = 0, ret = 0;
    bool neg = false;
    if (s[0] == '-') {
        neg = true;
        i = 1;
    }
    for (; i < (int)s.size(); i++) {
        ret = ret * 10 + (s[i] - '0');
    }
    return neg ? -ret : ret;
}

void solve() {}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    testcase
        solve();
    return 0;
}