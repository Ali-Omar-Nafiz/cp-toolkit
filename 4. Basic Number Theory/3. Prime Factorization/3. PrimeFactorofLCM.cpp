// https://www.spoj.com/problems/MAIN12B/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bitset < 10000001 > isNP;
vector < int > primes;

void sieve() {
    isNP[1] = true;
    for (int i = 4; i <= 10000000; i += 2) {
        isNP[i] = true;
    }
    for (int i = 3; i * i <= 10000000; i += 2) {
        if (!isNP[i]) {
            for (int j = i * i; j <= 10000000; j += (2 * i)) {
                isNP[j] = true;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= 10000000; i++) {
        if (!isNP[i]) {
            primes.push_back(i);
        }
    }
}

signed main() {
    int t;
    cin >> t;
    sieve();
    for (int tc = 1; tc <= t; tc++) {
        int x;
        cin >> x;
        set < int > st;
        while (x--) {
            int n;
            cin >> n;
            for (auto &i: primes) {
                if (i * i > n) {
                    break;
                }
                if (n % i == 0) {
                    st.insert(i);
                    while (n % i == 0) {
                        n /= i;
                    }
                }
            }
            if (n > 1) {
                st.insert(n);
            }
        }
        cout << "Case #" << tc << ": " << st.size() << endl;
        for (auto val: st) {
            cout << val << endl;
        }
    }
    return 0;
}
