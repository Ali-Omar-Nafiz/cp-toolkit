#include <bits/stdc++.h>
using namespace std;

/*
=====================================
FIBONACCI SERIES
=====================================
Series:
0 1 1 2 3 5 8 13 21 ...
Definition:
fibo(n) = fibo(n - 1) + fibo(n - 2)
Meaning:
nth Fibonacci number is sum of previous two.
*/

int fibo(int n) {
    // Base Case 1
    // We memorize fibo(0)
    if (n == 0) {
        return 0;
    }
    // Base Case 2
    // We memorize fibo(1)
    if (n == 1) {
        return 1;
    }
    // Faith:
    // fibo(n - 1) works correctly
    // fibo(n - 2) works correctly
    int result = fibo(n - 1) + fibo(n - 2);
    return result;
}

int main() {
    cout << fibo(10) << endl;  // prints 55
    cout << fibo(5) << endl;   // prints 5
    return 0;
}
