// https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            ans = max(ans, abs(r - l) * min(height[l], height[r]));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
