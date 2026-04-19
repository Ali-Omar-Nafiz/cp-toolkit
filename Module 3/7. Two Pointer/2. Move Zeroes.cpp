// https://leetcode.com/problems/move-zeroes/description/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int firstZero = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                firstZero = i;
                break;
            }
        }
        if (firstZero == -1)
            return;
        int green = firstZero, red = firstZero;
        while (green < n) {
            while (green < n && nums[green] == 0)
                green++;
            if (green == n)
                break;
            swap(nums[red], nums[green]);
            red++;
        }
    }
};
