// https://leetcode.com/problems/longest-nice-subarray/description/
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        bool exist[31]{};
        int ans = 1, l = 0, r = 0, n = nums.size();
        for (int bit = 0; bit <= 30; bit++) {
            if (nums[0] & (1 << bit)) {
                exist[bit] = true;
            }
        }
        // cout << "Step 1" << endl;
        while (r + 1 < n) {
            r++; // added nums[r]
            while (1 && l < r) {
                // cout << "Step 2" << endl;
                // cout << l << " " << r << endl;
                bool problemAcheKina = false;
                for (int bit = 0; bit <= 30; bit++) {
                    if (nums[r] & (1 << bit)) { // New Number taken
                        if (exist[bit]) { // Agei ei bit ache // Conflitcts with
                                          // the newly added element
                            problemAcheKina = true;
                            break;
                        }
                    }
                }
                if (problemAcheKina) {
                    // remove nums[l]
                    for (int bit = 0; bit <= 30; bit++) {
                        if (nums[l] & (1 << bit)) {
                            exist[bit] = false;
                        }
                    }
                    l++;
                } else {
                    break;
                }
            }
            // cout << "Step 3" << endl;
            for (int bit = 0; bit <= 30; bit++) { // Adding new number bits
                if (nums[r] & (1 << bit)) {
                    exist[bit] = true;
                }
            }
            ans = max(r - l + 1, ans);
        }
        cout << "Step 4" << endl;
        return ans;
    }
};
