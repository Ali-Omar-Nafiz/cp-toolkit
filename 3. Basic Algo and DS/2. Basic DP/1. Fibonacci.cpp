#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming(DP)
// DP is recursion with memoization. It uses memory to reduce function calls.

// Fibonacci with recursive DP
int n;
vector < int > dp(n + 1, -1);

int fibo(int n) {
    if (n == 0) {
        dp[n] = 0;
        return dp[n];
    }
    if (n == 1) {
        dp[n] = 1;
        return dp[n];
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
    cout << fibo(n) << endl;

    // Fibonacci with Iterative DP
    vector < int > fibo(n + 1, -1);
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            fibo[i] = 0;
        } else if (i == 1) {
            fibo[i] = 1;
        } else if (fibo[i] != -1) {
            continue;
        } else {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
    }
    cout << fibo[n] << endl;
    return 0;
}

/*
For iterative DP:
1. All possible input case must be covered under for loop (e.g. line 36)
2. Maintain loop order (Make sure the dp call is currently using have previously calculated. e.g. line 44. dp[n - 1] and dp[n - 2] are calculated before dp[n])

Time Complexity: size of dp array * number of operation in a function call
*/
