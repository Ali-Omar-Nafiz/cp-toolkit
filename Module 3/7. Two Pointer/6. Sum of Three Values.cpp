// https://cses.fi/problemset/task/1641/
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
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1, currentTarget = target - arr[i].first;
        while (r >= i + 1) {
            while (arr[l].first + arr[r].first < currentTarget && l < r)
                l++;
            if (l != r && arr[l].first + arr[r].first == currentTarget) {
                cout << arr[l].second << " " << arr[r].second << " " << arr[i].second << '\n';
                return;
            }
            r--;
        }
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
