#include <bits/stdc++.h>
using namespace std;

int main() {

    /****************************
        MAKE ARRAY 1-BASED
    *****************************/
    vector<int> tmp = {1, 4, 6, 7, 9, 2};
    int n = tmp.size();

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = tmp[i - 1];
    }

    /****************************
        BUILD PREFIX SUM
    *****************************/
    vector<int> pre(n + 1);

    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i];
        // pre[i] = v[1] + v[2] + ... + v[i]
    }

    return 0;
}
