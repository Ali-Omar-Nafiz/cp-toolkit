#include <bits/stdc++.h>
using namespace std;
#define int long long

// Knapsack 1
// https://atcoder.jp/contests/dp/tasks/dp_d
/*
1. Definition:
   input: pos, c
   output: maximum profit
2. Faith: This function will give max profit from current position to the last by choosing the best possible combination of elements.
3. Base Case: when pos == n, the process will end.
*/

int dp[100][100001];
vector < int > wt, val;
int n;

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

signed main() {
    int w;
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        wt.push_back(a);
        val.push_back(b);
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= 100000; j++) {
            dp[i][j] = -1;
        }
    }
    int ans = knapsack(0, w);
    cout << ans << endl;
    return 0;
}

// Time Complexity: TC of the single function * size of DP array (Take functon call as O(1))
