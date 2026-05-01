// https://www.spoj.com/problems/MEANARR/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <typename T, typename Comp = less < T > > 
using  ordered_set =  tree <T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector < int > v(n + 1), store(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
        store[i] = v[i] - (k * i);
    }
    ordered_set < pair < int, int > > oset;
    int ans = 0;
    oset.insert({0, 0});
    for (int i = 1; i <= n; i++) {
        ans += oset.order_of_key({store[i], INT_MAX});
        oset.insert({store[i], i});
    }
    cout << ans << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
