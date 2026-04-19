// https://leetcode.com/problems/merge-sorted-array/description/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Method 1
        // Create ans
        // nums1 = ans

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
        nums1 = merged;
    }
};
