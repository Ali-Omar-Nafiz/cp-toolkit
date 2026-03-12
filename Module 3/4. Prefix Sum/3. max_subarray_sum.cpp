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
        MAXIMUM SUBARRAY SUM
    *****************************/
    int ans = INT_MIN;
    int mn = 0;

    for (int i = 1; i <= n; i++) {

        int rsum = pre[i];

        ans = max(ans, rsum - mn);

        mn = min(mn, pre[i]);

        /*
            rsum - mn → best subarray ending at i
        */
    }

    return 0;
}
