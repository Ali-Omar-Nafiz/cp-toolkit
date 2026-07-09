// Modular Operations
// https://cp-algorithms.com/algebra/module-inverse.html
// https://codeforces.com/blog/entry/143150
// https://www.geeksforgeeks.org/dsa/fermats-little-theorem/
#include <iostream>
using namespace std;
#define int long long
int m = 97;

int modpow(int a, int b) { // pow(a,b)%m
    a %= m;
    if (b == 0) // Base Case, pow(a, 0) = 1
        return 1;
    if (b & 1) { // odd power, a^b = a * a^(b/2) * a^(b/2) = a * (a*a)^(b/2)
        return (a * modpow(a * a, b / 2)) % m;
    } else {
        return modpow(a * a, b / 2);
    }
}


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

int32_t main() 
{
    cout << modinv(2) << '\n';
    cout << modpow2(10, 100) << '\n';
    return 0;
}
// https://www.geeksforgeeks.org/dsa/modulo-1097-1000000007/
// https://www.geeksforgeeks.org/dsa/modular-division/
