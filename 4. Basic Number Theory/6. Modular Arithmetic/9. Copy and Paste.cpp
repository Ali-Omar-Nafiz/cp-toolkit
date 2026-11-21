
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

// Binary Exponentiation: (a^b) % MOD
int modpow(int a, int b) {
    int ans = 1;
    a %= MOD;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

// Modular Inverse: (1/a) % MOD
int modinv(int a) {
    return modpow(a, MOD - 2);
}

// Modular Addition: (a + b) % MOD
int add(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

// Modular Subtraction: (a - b) % MOD
int subs(int a, int b) {
    return (((a % MOD) - (b % MOD)) % MOD + MOD) % MOD;
}

// Modular Multiplication: (a * b) % MOD
int mult(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

// Modular Division: (a / b) % MOD
int divi(int a, int b) {
    return mult(a, modinv(b));
}

int32_t main() {
    cout << modinv(2) << '\n';
    cout << modpow(10, 100) << '\n';

    return 0;
}

