// https://codeforces.com/contest/1526/problem/C2
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
    int n;
    cin >> n;
    priority_queue < int, vector < int > , greater < int > > pq;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        sum += x;
        while (sum < 0) {
            sum -= pq.top();
            pq.pop();
        }
    }
    
    cout << pq.size() << endl;
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


