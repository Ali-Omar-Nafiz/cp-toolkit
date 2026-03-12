#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> tmp = {1, 4, 6, 7, 9, 2};
    int n = tmp.size();

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = tmp[i - 1];
    }

    /****************************
        PREFIX ARRAY
    *****************************/
    vector<int> pre(n + 1);

    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }

    /****************************
        COUNT SUBARRAY SUM = k
    *****************************/
    int k = 5;
    int ans = 0;

    map<int,int> mp;

    mp[0] = 1;

    for (int i = 1; i <= n; i++) {

        int target = pre[i] - k;

        ans += mp[target];

        mp[pre[i]]++;
    }

    return 0;
}
