// https://cses.fi/problemset/submit/1082/
#include <bits/stdc++.h>

using namespace std;

const int m = 1e9 + 7;

#define int long long

int modpow2(int a, int b) {
    int ans = 1;
    while (b > 0) {
        a %= m;
        if (b & 1) ans = (ans * a) % m;
        b >>= 1, a *= a;
    }
    return ans;
}

int modinv(int a) { // (1/a) mod m
    return modpow2(a, m - 2);    // a^(-1) = a^(m - 2) (mod m) (little theoram)
}

int add(int a, int b) {
    return ((a % m) + (b % m)) % m;
}

int subs(int a, int b) {
    return ((((a % m) - (b % m)) % m) + m) % m;   // x % m = ((x % m) + m) % m   (if x is negative); (a % m) - (b % m) can be negative
}

int mult(int a, int b) {
    return ((a % m) * (b % m)) % m;
}

int divi(int a, int b) { // a/b
    return mult(a, modinv(b));   // (a / b) = a * (1 / b) (mod m)
}


int sum(int lValue, int hValue) {
    int l = divi(mult(lValue, lValue + 1), 2);
    int h = divi(mult(hValue, hValue + 1), 2);
    return subs(h, l);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int divSum = 0;
    for (int i = 1; i * i <= n; i++) {
        // for divisors <= sqrt(n)
        int multiplier = n / i;
        divSum += (multiplier * i);        // O(sqrt(n))
        // for divisors > sqrt(n)
        int hValue = n / i;
        int lValue = max(i, n / (i + 1));   // to avoid double counting
        divSum += (i * sum(lValue, hValue));
        divSum %= m;
    }
    cout << divSum << endl;
    return 0;
}

