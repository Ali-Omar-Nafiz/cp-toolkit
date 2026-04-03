// Problem: https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int lft = -1, rgt = -1;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it == arr.end() || *it != x) {
            return {-1, -1};
        }
        lft = it - arr.begin();
        it = upper_bound(arr.begin(), arr.end(), x);
        rgt = it - arr.begin() - 1;
        return {lft, rgt};
    }
};
