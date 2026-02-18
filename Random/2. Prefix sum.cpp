/******************************************************
 *                PREFIX SUM TOOLKIT
 *              (Competitive Programming)
 *
 *  Purpose:
 *  --------
 *  - Fast range sum queries
 *  - Reduce O(n) per query → O(1)
 *
 *  Indexing:
 *  ---------
 *  - 1-based indexing is used
 *  - pre[0] is defined as 0
 *
 *  ---------------------------------------------------
 *  DEFINITIONS
 *  ---------------------------------------------------
 *  Prefix of size k:
 *      First k elements of the array
 *
 *  Prefix Sum Array (pre):
 *      pre[i] = sum of first i elements
 *
 *      pre[0] = 0
 *      pre[1] = v[1]
 *      pre[2] = v[1] + v[2]
 *      ...
 *      pre[n] = v[1] + v[2] + ... + v[n]
 *
 *  ---------------------------------------------------
 *  EXAMPLE
 *  ---------------------------------------------------
 *  v (1-based):
 *      index:  1  2  3  4   5
 *      value:  1  2  5  7  10
 *
 *  pre:
 *      pre[0] = 0
 *      pre[1] = 1
 *      pre[2] = 3
 *      pre[3] = 8
 *      pre[4] = 15
 *      pre[5] = 25
 *
 *  ---------------------------------------------------
 *  RANGE SUM QUERY
 *  ---------------------------------------------------
 *  Sum of range [l, r]:
 *
 *      sum(l, r) = pre[r] - pre[l - 1]
 *
 *  Why?
 *      pre[r]       → sum up to r
 *      pre[l - 1]   → sum before l
 *
 *  Example:
 *      l = 2, r = 4
 *      sum = pre[4] - pre[1] = 15 - 1 = 14
 *
 *  ---------------------------------------------------
 *  IMPLEMENTATION TEMPLATE
 *  ---------------------------------------------------
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Input array (1-based)
    vector<long long> v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // Prefix sum array
    vector<long long> pre(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }

    /*
     * Example Query:
     * l = 2, r = 4
     * answer = pre[r] - pre[l - 1]
     */

    // long long answer = pre[4] - pre[1];

    return 0;
}

/*
 * ---------------------------------------------------
 *  TIME & SPACE COMPLEXITY
 * ----------------------------------------------------
 *  Build prefix sum:     O(n)
 *  Each range query:     O(1)
 *  Extra space used:     O(n)
 *
 * ---------------------------------------------------
 *  IMPORTANT NOTES
 * ---------------------------------------------------
 *  ✔ Always use long long for prefix sums
 *  ✔ Keep pre size = n + 1
 *  ✔ 1-based indexing avoids off-by-one errors
 *  ✔ DO NOT use push_back when size is predefined
 *
 * ---------------------------------------------------
 *  EXTENSIONS (RELATED TOPICS)
 * ---------------------------------------------------
 *  - Prefix sum with multiple queries
 *  - 2D prefix sum (matrix)
 *  - Difference array
 *  - Subarray sum problems
 *
 ******************************************************/

