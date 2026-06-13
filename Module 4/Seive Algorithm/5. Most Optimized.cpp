// Most Optimized (Time Complexity - O(nlog(log(n))))
#include <bits/stdc++.h>
using namespace std;

bitset < 100000001 > is_prime;

int main() {
    int n = 1e8;

    is_prime[1] = true;  // we will thing in reverse for keeping it more optimized
    for (int i = 4; i <= n; i += 2) {
        is_prime[i] = true;
    }
    for (int i = 3; i * i <= n; i++) {
        for (int j = i * i; j <= n; j += (2 * i)) {
            is_prime[j] = true;
        }
    }
    cout << 2 << " ";
    for (int i = 3; i <= n; i += 2) {
        if (!is_prime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
