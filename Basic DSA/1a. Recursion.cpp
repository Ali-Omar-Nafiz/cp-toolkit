#include <bits/stdc++.h>
using namespace std;

/*
This file includes:
    factorial(n)
    fibonacci(n)
    printFromLastDigit(n)
    printFromFirstDigit(n)
    pow(a, b)
    optimizedPow(a, b)  ← uses Binary Exponentiation

Each function includes:
    Base case explanation
    Recursive case logic
    Recursion Tree Diagram (as comments)
*/



// FACTORIAL FUNCTION

int factorial(int n) {
    if (n == 0) {
        return 1; // base case / independent
    }
    return n * factorial(n - 1); // recursive call
}

/*
 Recursion Tree for factorial(4):

factorial(4)
 └── 4 * factorial(3)
        └── 3 * factorial(2)
               └── 2 * factorial(1)
                      └── 1 * factorial(0)
                             └── 1 (base case)

Computation goes upward:
factorial(1)=1
factorial(2)=2*1=2
factorial(3)=3*2=6
factorial(4)=4*6=24
*/



// FIBONACCI FUNCTION

int fibonacci(int n) {
    if (n == 1) return 0;   // base case / independent
    if (n == 2) return 1;   // base case / independent

    return fibonacci(n - 1) + fibonacci(n - 2);   // recursive call
}

/*
 Recursion Tree for fibonacci(5):

fibonacci(5)
 ├── fibonacci(4)
 │     ├── fibonacci(3)
 │     │     ├── fibonacci(2) → 1
 │     │     └── fibonacci(1) → 0
 │     │  → 1 + 0 = 1
 │     └── fibonacci(2) → 1
 │  → 1 + 1 = 2
 └── fibonacci(3)
       ├── fibonacci(2) → 1
       └── fibonacci(1) → 0
    → 1 + 0 = 1

fibonacci(5) = 2 + 1 = 3
*/


// PRINT DIGITS FROM LAST TO FIRST

void printFromLastDigit(int n) {
    if (n == 0) return;   // Base case / independent

    int lastDigit = n % 10;
    cout << lastDigit << " ";

    printFromLastDigit(n / 10);   // recursive call
}

/*
 Recursion Tree for printFromLastDigit(1234):

printFromLastDigit(1234)
 ├── print 4
 └── printFromLastDigit(123)
       ├── print 3
       └── printFromLastDigit(12)
             ├── print 2
             └── printFromLastDigit(1)
                   ├── print 1
                   └── printFromLastDigit(0) → stop

Output: 4 3 2 1
*/



// PRINT DIGITS FROM FIRST TO LAST

void printFromFirstDigit(int n) {
    if (n == 0) return;   // Base case / independent

    printFromFirstDigit(n / 10);   // recursive call
    
    int digit = n % 10;
    cout << digit << " ";
}

/*
 Recursion Tree for printFromFirstDigit(1234):

printFromFirstDigit(1234)
 ├── printFromFirstDigit(123)
 │     ├── printFromFirstDigit(12)
 │     │     ├── printFromFirstDigit(1)
 │     │     │     └── printFromFirstDigit(0) → stop
 │     │     └── print 1
 │     └── print 2
 └── print 3
print 4

Output: 1 2 3 4
*/



// POWER FUNCTION (a^b) — BASIC RECURSION

int powRec(int a, int b) {
    if (b == 0) {
        return 1; // base case: a^0 = 1
    }
    return a * powRec(a, b - 1);
}

/*
 Recursion Tree for powRec(2, 4):

powRec(2, 4)
 └── 2 * powRec(2, 3)
        └── 2 * powRec(2, 2)
               └── 2 * powRec(2, 1)
                      └── 2 * powRec(2, 0)
                             └── 1 (base case)

Computation: 2 * 2 * 2 * 2 = 16
*/



// OPTIMIZED POWER FUNCTION — BINARY EXPONENTIATION

int optimizedPow(int a, int b) {
    if (b == 0) {
        return 1; // base case
    }
    if (b % 2 == 0) { // if even
        int half = optimizedPow(a, b / 2);
        return half * half;
    } else { // if odd
        return a * optimizedPow(a, b - 1);
    }
}

/*
 Recursion Tree for optimizedPow(2, 5):

optimizedPow(2, 5)
 ├── odd → 2 * optimizedPow(2, 4)
 │           ├── even → half = optimizedPow(2, 2)
 │           │             ├── even → half = optimizedPow(2, 1)
 │           │             │             ├── odd → 2 * optimizedPow(2, 0)
 │           │             │             │             └── 1 (base)
 │           │             │         → 2 * 1 = 2
 │           │         → half = 2 → half * half = 4
 │           └── return 4
 └── return 2 * 4 = 8
Wait — check b=5 → optimizedPow(2,5)=2*optimizedPow(2,4)=2*16=32

Computation Steps:
(2^5) = 2 * (2^4)
(2^4) = (2^2)^2
(2^2) = (2^1)^2
(2^1) = 2 * (2^0)
*/



// MAIN FUNCTION — TESTING AREA

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== RECURSION TOOLKIT DEMO ===\n\n";

    int n;

    // Factorial Demo
    n = 4;
    cout << "factorial(" << n << ") = " << factorial(n) << "\n\n";

    // Fibonacci Demo
    n = 5;
    cout << "fibonacci(" << n << ") = " << fibonacci(n) << "\n\n";

    // Print digits from last to first
    n = 1234;
    cout << "Digits from last to first of " << n << ": ";
    printFromLastDigit(n);
    cout << "\n\n";

    // Print digits from first to last
    cout << "Digits from first to last of " << n << ": ";
    printFromFirstDigit(n);
    cout << "\n\n";

    // Power function demo
    int a = 2, b = 4;
    cout << "powRec(" << a << ", " << b << ") = " << powRec(a, b) << "\n\n";

    // Optimized power demo
    a = 2, b = 5;
    cout << "optimizedPow(" << a << ", " << b << ") = " << optimizedPow(a, b) << "\n";

    return 0;
}
