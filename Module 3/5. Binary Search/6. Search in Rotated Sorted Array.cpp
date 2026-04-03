// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution {
public:
    int search(vector<int>& nums, int target) {
 
        int n = nums.size();
 
        int L = 0, R = n-1; int ans = -1;
 
        while(L<=R)
        {
            int mid = L + (R-L)/2;
 
            if(nums[mid] == target)
            {
                ans = mid;
                break;
            }
 
            // L = mid+1
            // R = mid-1
 
            if(nums[mid]>=nums[L])
            {
                if(nums[L]<=target and nums[mid]>target)
                {
                    R = mid-1;
                }
                else
                {
                    L = mid+1;
                }
            }
            else
            {
                if(target >= nums[L])
                {
                    R = mid-1;
                }
                else
                {
                    if(target > nums[mid])
                    {
                        L = mid+1;
                    }
                    else
                    {
                        R = mid-1;
                    }
                }
            }
 
 
        }
        // if(L==R and ans == -1 and nums[L]==target) ans = L;
        return ans;
    }
};
