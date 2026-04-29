// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template < typename T > using ordered_set = tree < T, null_type,
        less_equal<T>, rb_tree_tag, tree_order_statistics_node_update >;
 
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set < pair < int, int> > oset;
        vector < int > cnt(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            cnt[i] = oset.order_of_key(make_pair(nums[i], -1));
            oset.insert(make_pair(nums[i], i));
        }
        return cnt;
 
    }
};
