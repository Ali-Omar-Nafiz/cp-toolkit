class Solution {
public:
    string a, b;
    vector<vector<int>> dp;

    int fun(int f, int s) {
        if (f < 0 || s < 0) {
            return 0;
        }

        if (dp[f][s] != -1) {
            return dp[f][s];
        }

        if (a[f] == b[s]) {
            dp[f][s] = fun(f - 1, s - 1) + 1;
        } 
        else {
            dp[f][s] = max(fun(f - 1, s), fun(f, s - 1));
        }

        return dp[f][s];
    }

    int longestCommonSubsequence(string text1, string text2) {
        a = text1;
        b = text2;

        dp.assign(a.length(), vector<int>(b.length(), -1));

        return fun(a.length() - 1, b.length() - 1);
    }
};
