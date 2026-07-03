// https://lightoj.com/problem/mathematically-hard
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int unsigned long long           // important

vector < int > phies(5000001);

void phi() {
    for (int i = 2; i <= 5000000; i++) {
        phies[i] = i;
    }
    for (int i = 2; i <= 5000000; i++) {
        if (phies[i] == i) {
            for (int j = i; j <= 5000000; j += i) {
                phies[j] -= (phies[j] / i);
            }
        }
    }
    for (int i = 2; i <= 5000000; i++) {
        phies[i] = phies[i - 1] + (phies[i] * phies[i]);
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = phies[b] - phies[a - 1];
    cout << ans << endl;
}

signed main() {
    FAST_IO;
    phi();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
