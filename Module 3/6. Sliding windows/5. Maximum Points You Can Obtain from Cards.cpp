// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        k = n - k;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int ans = sum;
        for (int i = 0; i < n - k; i++) {
            sum -= cardPoints[i];
            sum += cardPoints[i + k];
            ans = min(sum, ans);
        }
        ans = accumulate(cardPoints.begin(), cardPoints.end(), 0ll) - ans;
        return ans;
    }
};
