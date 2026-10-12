#include <bits/stdc++.h>
using namespace std;

int main() {

    /****************************
        DIFFERENCE ARRAY
    *****************************/
    int n = 10;

    int q = 5;

    map<int,int> diff;

    while (q--) {

        int L = 2, R = 5;

        diff[L] += 1;

        diff[R + 1] -= 1;

        /*
            diff[L]     → start increment
            diff[R + 1] → stop increment
        */
    }

    /****************************
        BUILD FINAL ARRAY
    *****************************/
    vector<int> finalArr(n + 1);

    int cur = 0;

    map<int,int>::iterator it = diff.begin();

    for (int i = 1; i <= n; i++) {

        for (; it != diff.end() && it->first == i; ++it) {

            cur += it->second;

            /*
                applying difference updates
            */
        }

        finalArr[i] = cur;

        /*
            finalArr[i] contains
            total increments at index i
        */
    }

    return 0;
}
