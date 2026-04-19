// https://cses.fi/problemset/task/1640
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
 
void Solve()
{
    ll n, target;
    cin >> n >> target;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    while (r >= 0) {
        while (arr[l].first + arr[r].first < target && l < r)
            l++;
        if (l != r && arr[l].first + arr[r].first == target) {
            cout << arr[l].second << " " << arr[r].second << '\n';
            return;
        }
        r--;
    }
    cout << "IMPOSSIBLE\n";
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        Solve();
    }
    return 0;
}
// Coded by Tahsin Arafat (@TahsinArafat)
