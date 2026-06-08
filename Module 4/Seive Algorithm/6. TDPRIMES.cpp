// Most Optimized (Time Complexity - O(nlog(log(n))))
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'

bitset < 100000001 > is_prime;

int main() {
    FAST_IO;
    int n = 1e8;

    is_prime[1] = true;  // we will thing in reverse for keeping it more optimized
    for (int i = 4; i <= n; i += 2) {
        is_prime[i] = true;
    }
    for (int i = 3; i * i <= n; i += 2) {
        for (int j = i * i; j <= n; j += (2 * i)) {
            is_prime[j] = true;
        }
    }
    for (int i = 1, cnt = 0; i <= n; i++) {
        if (!is_prime[i]) {
            cnt++;
            if ((cnt % 100) == 1) {
                cout << i << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
// https://www.spoj.com/problems/TDPRIMES/en/

