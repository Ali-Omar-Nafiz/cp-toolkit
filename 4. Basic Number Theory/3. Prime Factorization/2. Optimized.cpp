// Prime Factorization Optimized Version (O(nlognlong + sqrt(n) / log(sqrt(n))))
#include <bits/stdc++.h>
using namespace std;

bitset < 10000001 > isNP;
vector < int > primes;

void sieve() {
    isNP[1] = true;
    isNP[0] = true;
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
    for (int i = 3; i <= 10000000; i += 2) {
        if (!isNP[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    sieve();
    cout << "Factor : Count" << endl;
    for (auto &i: primes) {
        if (i * i > n) {
            break;
        }
        if (n % i == 0) {
            cout << i << " : ";
            int iCount = 0;
            while (n % i == 0) {
                iCount++;
                n /= i;
            }
            cout << iCount << endl;
        }
    }
    if (n > 1) {
        cout << n << " : " << 1 << endl;
    }
    return 0;
}
