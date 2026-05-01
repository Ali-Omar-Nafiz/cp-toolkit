#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <typename K, typename V, typename Comp = less < K > > 
using  ordered_set =  tree <K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    ordered_set < int, string > omap;  // omap[key] = value
    omap[100] = "Nafiz";
    omap[29] = "Ali";
    omap[308] = "Omar";
    for (auto [x, y]: omap) {
        cout << x << " " << y << endl;  // prints in ascending order of key
    }
    cout << endl;
    cout << omap.order_of_key(100) << endl;   // prints 1
    cout << omap.find_by_order(0) -> first << endl;   // prints 29
    cout << omap.find_by_order(0) -> second << endl;   // prints Ali
}

signed main() {
    FAST_IO;
    int t = 1;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
