#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_bit.add
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> 
using  ordered_set =  tree <T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update>;
// comparator
// less, less_equal, greater, greater_equal
int main() {
    ordered_set < int > set;  // declaration
    return 0;
}
