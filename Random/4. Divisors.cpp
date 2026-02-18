/*
Divisors: Divisors of a number n is those numbers that devide n perfectly. It is also known as factors.

factors of 36:
1 x 36
2 x 18
3 x 12
4 x 9
6 x 6
1, 2, 3, 4, 6, 9, 12, 18, 36

Brute approach:
for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
        cout << i << endl;   // its a divisor of n
    }
}

Optimized approach:
for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
        int a = i;
        int b = n / a;
        if (a != b) {
            cout << a << " " << b << endl;   // a and b both are two different divisors
        } else {
            cout << a << endl; // both are same divisors..so pick any of them
        }
    }
}
*/
#include <bits/stdc++.h>

using namespace std;

vector < int > getDivisors(int n) {
    vector < int > v;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if ((n / i) != i) {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main() {
    int n;
    cin >> n;

    // Brute approach O(n)
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Optimized approach O(sqrt(n))
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int a = i;
            int b = n / a;
            if (a != b) {
                cout << a << " " << b << " ";
            } else {
                cout << a << " ";
            }
        }
    }
    cout << endl;

    vector < int > v = getDivisors(n);
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

// https://www.youtube.com/watch?v=Ae_Ag_saG9s
