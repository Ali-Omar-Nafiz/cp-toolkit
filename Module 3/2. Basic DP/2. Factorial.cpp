#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
    if (n == 0) {
        return 1;   // Normal Recursion
    }
    return n * fact (n - 1);
}

int main() {
    // Factorial using iterative dp
    int n;
    cin >> n;
    vector < int > fact(n + 1, -1);
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            fact[i] = 1;
        } else {
            fact[i] = i * fact[i - 1];
        }
    }
    cout << fact[n] << endl;
}

/*
For iterative DP:
1. All possible input case must be covered under for loop (e.g. line 36)
2. Maintain loop order (Make sure the dp call is currently using have previously calculated. e.g. line 44. dp[n - 1] and dp[n - 2] are calculated before dp[n])
*/
