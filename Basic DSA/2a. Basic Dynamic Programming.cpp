#include <bits/stdc++.h>
using namespace std;

/*
DYNAMIC PROGRAMMING TOOLKIT

CONCEPT:
    Dynamic Programming (DP) is applied when the current state
    depends on one or more smaller subproblems.

HOW TO DECIDE IF DP CAN BE USED:
    If the solution of the problem can be expressed in terms of 
    previously solved smaller subproblems.

HOW TO CHOOSE THE DP APPROACH (based on dependency):
    Example: Fibonacci sequence

        f(n) = f(n - 1) + f(n - 2)

    → f(n) depends on f(n-1) and f(n-2)
    → So we can build results from smaller values to larger values

    If dependency is from larger → smaller → use recursion + memoization (Top-Down)
    If dependency is from smaller → larger → use iteration + table (Bottom-Up)
*/

// 1. Naive Recursive Approach
/*
Time Complexity: O(2^n)
Concept: Calls the same subproblems repeatedly without storing results
*/
int fibonacciRecursiveNaive(int n) {
    if (n == 1) return 0;   // Base Case 1
    if (n == 2) return 1;   // Base Case 2
    return fibonacciRecursiveNaive(n - 1) + fibonacciRecursiveNaive(n - 2);
}

// 2. Recursive DP (Memoization)
/*
Time Complexity: O(n)
Idea:
    - Store the result of each subproblem in dp[].
    - Before solving a subproblem, check if it's already computed.
    - If yes → reuse it.
    - This is the TOP-DOWN approach (recursion + memory).
*/
vector<int> dp(100, -1);  // initialize dp array with -1 (uncomputed)

int fibonacciRecursiveDP(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    if (dp[n] != -1)           // if already computed → reuse
        return dp[n];

    dp[n] = fibonacciRecursiveDP(n - 1) + fibonacciRecursiveDP(n - 2);
    return dp[n];
}

// 3. Iterative DP (Tabulation)
/*
Time Complexity: O(n)
Space Complexity: O(n)
Idea:
    - Build the solution from base cases upward.
    - Each state depends only on smaller states.
    - This is the BOTTOM-UP approach.
*/
int fibonacciIterativeDP(int n) {
    vector<int> fib(n + 1, 0);
    fib[1] = 0;
    fib[2] = 1;

    for (int i = 3; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

// Explanation / Summary
/*
COMPARISON TABLE
| Approach              | Style        | Time       | Space | Dependency Direction | Notes            |
|----------------------- |------------- |------------|--------|----------------------|------------------|
| Naive Recursion        | Exponential  | O(2^n)     | O(n)  | f(n) → f(n-1), f(n-2) repeatedly | Slow, redundant |
| Recursive DP (Memo)    | Top-Down     | O(n)       | O(n)  | Depends on smaller subproblems   | Saves results   |
| Iterative DP (Tab)     | Bottom-Up    | O(n)       | O(n)  | Builds from base upward          | Efficient       |

USEFUL NOTES:
- DP applies when the problem has dependencies between subproblems.
- If a state depends on smaller states → build bottom-up.
- If recursion is more natural → use top-down with memoization.
*/

void solve() {
    int n;
    cin >> n;

    cout << fibonacciRecursiveNaive(n);
    cout << fibonacciRecursiveDP(n);
    cout << fibonacciIterativeDP(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
