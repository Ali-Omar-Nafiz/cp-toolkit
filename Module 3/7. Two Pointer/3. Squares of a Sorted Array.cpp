// https://leetcode.com/problems/squares-of-a-sorted-array/description/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squared;
        for (auto& it : nums)
            squared.push_back(it * it);
        int minIndex = min_element(squared.begin(), squared.end()) - squared.begin();
        vector<int> nums1, nums2;
        for (int i = minIndex; i < nums.size(); i++)
            nums1.push_back(squared[i]);
        for (int i = minIndex - 1; i >= 0; i--)
            nums2.push_back(squared[i]);

        // Merge Part
        int m = nums1.size(), n = nums2.size();
        int l = 0, r = 0;
        vector<int> merged;
        while (l < m && r < n) {
            if (nums1[l] < nums2[r]) {
                merged.push_back(nums1[l]);
                l++;
            } else {
                merged.push_back(nums2[r]);
                r++;
            }
        }
        while (l < m) {
            merged.push_back(nums1[l]);
            l++;
        }
        while (r < n) {
            merged.push_back(nums2[r]);
            r++;
        }
        return merged;
    }
};
