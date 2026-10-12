// https://www.spoj.com/problems/LCMSUM/
//Editorial: https://forthright48.com/spoj-lcmsum-lcm-sum/
#include <bits/stdc++.h>
using namespace std;

#define int uint64_t

vector<int> phi(1000001), sigma(1000001);

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

    iota(phi.begin(), phi.end(), 0ll);

    for (int i = 2; i <= 1000000; i++)
        if (phi[i] == i)
            for (int j = i; j <= 1000000; j += i)
                phi[j] -= phi[j] / i;

    for (int i = 1; i <= 1000000; i++)
        for (int j = i; j <= 1000000; j += i)
            sigma[j] += i * phi[i];

    int t;
    cin >> t;

    int l, r;

    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << n * (sigma[n] + 1) / 2 << '\n';
    }

    return 0;
}
