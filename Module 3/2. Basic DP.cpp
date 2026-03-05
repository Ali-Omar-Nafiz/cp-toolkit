#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming(DP)
// DP is recursion with memoization. It uses memory to reduce function calls.

// Fibonacci with recursive DP

vector < int > dp(n + 1, -1); // Global
for (int i = 0; i <= n; i++) {
    dp[i] = -1;   // under main
}

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

// Fibonacci with Iterative DP

dp[0] = 0;
dp[1] = 1;
for (int i = 2; i <= n; i++) {             // Under main
    dp[i] = dp[i - 1] + dp[i - 2];
}
cout << dp[n] << endl;

// Knapsack 1
// https://atcoder.jp/contests/dp/tasks/dp_d

int dp[100][100001]; // Global

vector < int > wt, val;
for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    wt.push_back(a);
    val.push_back(b);
}
for (int i = 0; i < 100; i++) {
    for (int j = 0; j <= 100000; j++) {    // Under main
        dp[i][j] = -1;
    }
}

int knapsack(int pos, int c) {
    if (pos == n) {
        return 0;
    }
    if (dp[pos][c] != -1) {
        return dp[pos][c];
    }
    int max1 = 0, max2 = 0;
    if (c >= wt[pos]) {
        max1 = val[pos] + knapsack(pos + 1, c - wt[pos]);   // max profit including current element
    }
    max2 = knapsack(pos + 1, c);   // max profit excluding current element
    dp[pos][c] = max(max1, max2);
    return dp[pos][c];
}

/*
1. Definition:
   input: pos, c
   output: maximum profit
2. Faith: This function will give max profit from current position to the last by choosing the best possible combination of elements.
3. Base Case: when pos == n, the process will end.
*/

int main() {
}
