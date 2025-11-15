#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // dp[s] = number of ways to make sum s
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;  // one way to make 0

    // Build sums from 0 to x
    for (int current_sum = 0; current_sum <= x; current_sum++) {

        // If no way to reach this sum, skip it
        if (dp[current_sum] == 0) continue;

        // Try every coin
        for (int coin : coins) {

            int next_sum = current_sum + coin;

            // Do not go outside the target
            if (next_sum > x) continue;

            // --- LOGIC VISUALIZATION ---
            // dp[current_sum] = ways to make current_sum
            // We add coin -> now we can make next_sum
            //
            // So:
            // dp[next_sum] += dp[current_sum]
            //
            // Example:
            // If 3 ways to make sum 5, then
            // 3 new ways to make sum (5 + coin)

            dp[next_sum] = (dp[next_sum] + dp[current_sum]) % MOD;
        }
    }

    cout << dp[x] << "\n";
    return 0;
}


Problem link: https://cses.fi/problemset/task/1635