// https://www.spoj.com/problems/ORDERSET/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_bit.add
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main() {
    ordered_set < int > oset;
    int q;
    cin >> q;
    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'I') oset.insert(x);
        else if (c == 'D') oset.erase(x);
        else if (c == 'K') {
            x--;
            if (oset.size() <= x) cout << "invalid" << endl;
            else cout << *oset.find_by_order(x) << endl;
        }
        else {
            cout << oset.order_of_key(x) << endl;
        }
    }
    return 0;
}

