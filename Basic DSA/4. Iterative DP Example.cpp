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

            // dp[current_sum] = ways to make current_sum
            // Add coin -> now you can build next_sum
            dp[next_sum] = (dp[next_sum] + dp[current_sum]) % MOD;
        }
    }

    cout << dp[x] << "\n";
    return 0;
}


/*
==============================================================
                    EXPLANATION (VERY SIMPLE)
==============================================================

dp[s] means:
    "How many different ways to make the sum s?"

We start with:
    dp[0] = 1
Because there is exactly 1 way to make sum 0:
    -> use no coins.

--------------------------------------------------------------
HOW THE LOOPS WORK
--------------------------------------------------------------

We go through every sum from 0 up to x.

For each sum "current_sum":

    If dp[current_sum] = 0:
        This means we cannot reach this sum, so skip it.

    Otherwise:
        dp[current_sum] tells us how many ways we already know
        to build this sum.

        Then we try every coin:

            next_sum = current_sum + coin

        If next_sum <= x:
            Then all ways to make current_sum can now make next_sum
            simply by adding this coin at the end.

So we do:

    dp[next_sum] += dp[current_sum]

This adds new ways to reach next_sum.


--------------------------------------------------------------
SMALL EXAMPLE
--------------------------------------------------------------

Coins: [2, 3]
Target: 5

Start:
    dp[0] = 1

current_sum = 0:
    dp[0] = 1
    Try coins:
      +2 → dp[2] becomes 1
      +3 → dp[3] becomes 1

current_sum = 2:
    dp[2] = 1
      +2 → dp[4] becomes 1
      +3 → dp[5] becomes 1

current_sum = 3:
    dp[3] = 1
      +2 → dp[5] becomes 2 (because dp[5] was 1)
      +3 → dp[6] (ignored, >5)

Final:
    dp[5] = 2   --> Answer is 2 ways

--------------------------------------------------------------
WHY IT COUNTS PERMUTATIONS (ORDER MATTERS)
--------------------------------------------------------------

Because for each sum we always try all coins in order.
This means:
    2 + 3
    3 + 2
Are counted as different ways.

==============================================================
*/
