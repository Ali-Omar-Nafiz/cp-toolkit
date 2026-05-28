#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <typename T, typename Comp = less < T > > 
using  ordered_set =  tree <T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    ordered_set < int > oset1;   // ascending
    ordered_set < int, greater < int > > oset2;  // descending
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    return 0;
}
/*
 Comparators:
 less,greater (for set)
 less_equal, greater_equal (for multiset) (Not recommended, instade use pair with set)

 Useful functions
 st.order_of_key(value) // returns the index of the value in the set (number of element < value)
 *st.find_by_order(i) // returns the iterator of the ith (0 based) index element of the set
*/
