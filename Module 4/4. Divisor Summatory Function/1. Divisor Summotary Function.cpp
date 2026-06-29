// Divisor Summotary Function = sod(1) + sod(2) + ... + sod(n)
#include <bits/stdc++.h>

using namespace std;

#define int long long

int sum(int lValue, int hValue) {
    int l = (lValue * (lValue + 1)) / 2;
    int h = (hValue * (hValue + 1)) / 2;
    return (h - l);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int divSum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {   // O(nlogn)
            divSum += i;
        }
    }
    cout << divSum << endl;
    // or,
    divSum = 0;
    for (int i = 1; i <= n; i++) {
        int multiplier = n / i;            // O(n)
        divSum += (multiplier * i);
    }
    cout << divSum << endl;
    // or,
    divSum = 0;
    for (int i = 1; i * i <= n; i++) {
        // for divisors <= sqrt(n)
        int multiplier = n / i;
        divSum += (multiplier * i);        // O(sqrt(n))
        // for divisors > sqrt(n)
        int hValue = n / i;
        int lValue = max(i, n / (i + 1));   // to avoid double counting
        divSum += (i * sum(lValue, hValue));
    }
    cout << divSum << endl;
    return 0;
}

