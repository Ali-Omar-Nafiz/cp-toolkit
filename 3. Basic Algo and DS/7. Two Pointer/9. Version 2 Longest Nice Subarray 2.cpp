// https://leetcode.com/problems/longest-nice-subarray/description/
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0;
        int curr_sum=0;
        int maxlen=0;

        for(int right=0;right<nums.size();right++){
            while((curr_sum & nums[right])!=0){
                curr_sum ^= nums[left];
                left++;
            }
            curr_sum |= nums[right];
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
