class Solution {
public:
    vector<vector<int>> dp;
    string s;

    int fun(int l, int r) {
        if (l > r) {
            return 0;
        }

        if (l == r) {
            return 1;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        if (s[l] == s[r]) {
            dp[l][r] = fun(l + 1, r - 1) + 2;
        } else {
            dp[l][r] = max(fun(l, r - 1), fun(l + 1, r));
        }

        return dp[l][r];
    }

    int longestPalindromeSubseq(string s) {
        this->s = s;

        int n = s.length();
        dp.assign(n, vector<int>(n, -1));

        return fun(0, n - 1);
    }
};
