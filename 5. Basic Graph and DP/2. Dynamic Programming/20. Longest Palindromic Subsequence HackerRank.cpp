// Problem: https://www.hackerrank.com/challenges/longest-palindromic-subsequence/problem
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)

#define endl '\n'

#define int long long

vector < vector < int > > lps, lcs;

void solve() {

   int n, k;

   cin >> n >> k;

   string s;

   cin >> s;

   // More than 2 insertions cannot be handled
   if (k > 2) {

    cout << 0 << endl;

    return;
   }

   // With 0 insertions, any of 26 letters can be inserted
   // at any of n + 1 positions
   if (k == 0) {

    cout << (26 * (n + 1)) << endl;

    return;
   }

   // 1-based indexing
   s = " " + s;

   // LPS[i][j] = LPS length of s[i...j]
   lps.assign(n + 2, vector < int > (n + 2));

   for (int i = 1; i <= n; i++) {

    lps[i][i] = 1;
   }

   // Build LPS table by increasing substring length
   for (int i = 2; i <= n; i++) {

    int l = 1, r = i;

    while (r <= n) {

        if (s[l] == s[r]) {

            lps[l][r] = lps[l + 1][r - 1] + 2;

        } else {

            lps[l][r] = max(lps[l][r - 1], lps[l + 1][r]);
        }

        l++, r++;
    }
   }

   // LCS[i][j] = LCS of s[1...i] and s[j...n]
   lcs.assign(n + 2, vector < int > (n + 2));

   // Base case: first row
   for (int j = n; j >= 1; j--) {

    if (s[1] == s[j]) {

        lcs[1][j] = 1;

    } else if (j != n) {

        lcs[1][j] = lcs[1][j + 1];
    }
   }

   // Base case: last column
   for (int i = 1; i <= n; i++) {

    if (s[i] == s[n]) {

        lcs[i][n] = 1;

    } else {

        lcs[i][n] = lcs[i - 1][n];
    }
   }

   // Build LCS table
   for (int i = 2; i <= n; i++) {

    for (int j = n - 1; j >= 1; j--) {

        if (s[i] == s[j]) {

            lcs[i][j] = lcs[i - 1][j + 1] + 1;

        } else {

            lcs[i][j] = max(lcs[i][j + 1], lcs[i - 1][j]);
        }
    }
   }

   int ans = 0;

   // Try every insertion position
   for (int i = 0; i <= n; i++) {

    int cur;

    // Try inserting every possible lowercase letter
    for (char c = 'a'; c <= 'z'; c++) {

        // Original LPS without insertion
        cur = lps[1][n];

        // Case 1: inserted character matches a character on the left
        for (int j = 1; j <= i; j++) {

            if (s[j] == c) {

                // LPS inside left part + matching characters
                // from the right side + inserted pair
                int chk = lps[j + 1][i]
                        + (2 * lcs[j - 1][i + 1])
                        + 2;

                cur = max(cur, chk);
            }
        }

        // Case 2: inserted character matches a character on the right
        for (int j = i + 1; j <= n; j++) {

            if (s[j] == c) {

                int chk = lps[i + 1][j - 1]
                        + (2 * lcs[i][j + 1])
                        + 2;

                cur = max(cur, chk);
            }
        }

        // Case 3: inserted character is the center of the palindrome
        int chk = (2 * lcs[i][i + 1]) + 1;

        cur = max(cur, chk);

        // Count this insertion if LPS increases by at least k
        if ((cur - lps[1][n]) >= k) {

            ans++;
        }
    }
   }

   cout << ans << endl;
}

signed main() {

    FAST_IO;

    int t = 1;

    cin >> t;

    for (int i = 1; i <= t; i++) {

        // cout << "#TestCase: " << i << endl;

        solve();
    }

    return 0;
}
