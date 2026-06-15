// Prime Factorization Basic Version (O(sqrt(n)))
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << "Factor : Count" << endl;
    for (int i = 2; i * i <= n; i++) {
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
