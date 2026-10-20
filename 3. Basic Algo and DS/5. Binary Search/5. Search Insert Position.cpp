// Problem: https://leetcode.com/problems/search-insert-position/submissions/1964107859/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
};
