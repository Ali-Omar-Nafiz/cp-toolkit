#include <iostream>
using namespace std;
#define int long long
int m = 97;

int modPow(int a, int b) { // pow(a,b)%m
    a %= m;
    if (b == 0) // Base Case, pow(a, 0) = 1
        return 1;
    if (b & 1) { // odd power, a^b = a * a^(b/2) * a^(b/2) = a * (a*a)^(b/2)
        return (a * modPow(a * a, b / 2)) % m;
    } else {
        return modPow(a * a, b / 2);
    }
}

int modPow2(int a, int b) {
    int ans = 1;
    while (b > 0) {
        a %= m;
        if (b & 1) ans = (ans * a) % m;    // a ^ b = (a ^ (b / 2)) * (a ^ (b / 2)) = (a * a) ^ (b / 2)
        b >>= 1, a *= a;
    }
    return ans;
}

int32_t main() 
{
    cout << modPow(10, 100) << '\n';
    cout << modPow2(10, 100) << '\n';
    return 0;
}