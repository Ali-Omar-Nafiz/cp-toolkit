// https://www.geeksforgeeks.org/dsa/job-sequencing-problem/
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

bool cmp(pair<int,int> &a, pair<int,int> &b) {
    return a.first > b.first; // higher profit first
}

void solve() {

    int n;
    cin >> n;

    vector<pair<int,int>> v; // {profit, deadline}
    int mxDeadline = 0;

    for(int i = 0; i < n; i++) {
        int profit, deadline;
        cin >> profit >> deadline;
        v.push_back({profit, deadline});
        mxDeadline = max(mxDeadline, deadline);
    }

    // sort by profit descending
    sort(v.begin(), v.end(), cmp);

    // available time slots
    set<int> st;
    for(int i = 1; i <= mxDeadline; i++)
        st.insert(i);

    int totalProfit = 0;
    int jobsDone = 0;

    for(auto [profit, deadline] : v) {

        // first slot STRICTLY greater than deadline
        auto it = st.upper_bound(deadline);

        // no valid slot
        if(it == st.begin()) continue;

        --it; // largest slot <= deadline

        totalProfit += profit;
        jobsDone++;

        st.erase(it); // occupy slot
    }

    cout << jobsDone << " " << totalProfit << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
