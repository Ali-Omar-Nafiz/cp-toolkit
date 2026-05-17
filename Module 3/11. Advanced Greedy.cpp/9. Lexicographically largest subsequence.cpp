// https://www.geeksforgeeks.org/dsa/lexicographically-largest-subsequence-every-character-occurs-least-k-times/
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

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> ans;

    int mx = LLONG_MIN;

    // build suffix maximum subsequence
    for(int i = n - 1; i >= 0; i--) {
        if(v[i] >= mx) {
            ans.push_back(v[i]);
            mx = v[i];
        }
    }

    reverse(ans.begin(), ans.end());

    for(int x : ans)
        cout << x << " ";
    cout << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    while(t--) solve();
    return 0;
}
