// https://www.geeksforgeeks.org/dsa/minimum-fibonacci-terms-sum-equal-k/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <typename T, typename Comp = less<T>>
using ordered_set =
tree<T, null_type, Comp, rb_tree_tag,
tree_order_statistics_node_update>;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {

    int k;
    cin >> k;

    // Generate Fibonacci numbers
    vector<int> fib = {1, 1};

    while(true) {
        int nxt = fib.back() + fib[fib.size()-2];
        if(nxt > k) break;
        fib.push_back(nxt);
    }

    int ans = 0;

    // Greedy: take largest possible Fibonacci
    for(int i = (int)fib.size() - 1; i >= 0; i--) {
        while(k >= fib[i]) {
            k -= fib[i];
            ans++;
        }
    }

    cout << ans << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

