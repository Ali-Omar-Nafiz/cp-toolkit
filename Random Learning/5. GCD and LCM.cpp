/*
GCD of a and b: Greatest integer that divides both a and both b perfectly
LCM of a and b: Least integer that a and b divide perfectly

GCD Brueforce:
To check all numbers from min(a, b) to 1, see if it divides both a and b

GCD Optimized:
Euclidean algorithm: If we replace the greater number from a and b with the difference of a, b...the gcd remains same
Just replace the greater number by the difference of a and b...until a and b becomes same


LCM:
(a * b) / gcd(a, b);
*/

#include <bits/stdc++.h>

using namespace std;

int gcd_brute(int a, int b) {
    int ans = min(a, b);
    while (ans != 1) {
        if ((a % ans) == 0 && (b % ans) == 0) {
            return ans;
        } else {
            ans--;
        }
    }
    return ans;
}

int gcd_euclidean(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    while (a != b) {
        if (a > b) {
            a = (a - b);
        } else if (b > a) {
            b = (b - a);
        }
    }
    return a;
}

int lcm_custom(int a, int b) {
    int gd = gcd_euclidean(a, b);
    return ((a * b) / gd);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd_brute(a, b) << " " << gcd_euclidean(a, b) << endl;
    cout << lcm_custom(a, b) << endl;

    // Inbuilt functions gcd(a, b), __gcd(a, b), lcm(a, b);
    cout << gcd(a, b) << " " << __gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
    return 0;
}
