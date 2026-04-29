#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_bit.add
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> 
using  ordered_set =  tree <T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    ordered_set < int > st;  // declaration
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
