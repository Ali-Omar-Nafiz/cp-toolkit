#include <bits/stdc++.h>
using namespace std;

/*
=============================================================
Introduction to Functions
- Real-life analogy: A function is like a kitchen recipe.
  You give ingredients (inputs/parameters), follow steps (function body), and get a dish (output/return value).
- Functions help organize code, avoid repetition, and improve readability.
=============================================================
*/

// -----------------------------
// 1. Simple function: add two numbers
// -----------------------------
int add(int a, int b) {
    return a + b;
}

// -----------------------------
// 2. Void function: prints a greeting
// -----------------------------
void greet() {
    cout << "Hello! Welcome to the function toolkit.\n";
}

// -----------------------------
// 3. Important small functions
// -----------------------------

// Check if number is even
bool isEven(int x) {
    return x % 2 == 0;
}

// Return minimum of two numbers
int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// Return maximum of two numbers
int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

// -----------------------------
// 4. Area of circle
// -----------------------------
double areaOfCircle(double radius) {
    const double PI = 3.1415926535;
    return PI * radius * radius;
}

// -----------------------------
// 5. Call by value example
// -----------------------------
void callByValueExample(int x) {
    x = x + 10; // change does NOT affect original variable
    cout << "Inside callByValueExample, x = " << x << endl;
}

// -----------------------------
// 6. Call by reference example
// -----------------------------
void callByReferenceExample(int &x) {
    x = x + 10; // change affects original variable
    cout << "Inside callByReferenceExample, x = " << x << endl;
}

// -----------------------------
// 7. Power function (using loop)
// -----------------------------
int powFunc(int base, int exp) {
    int result = 1;
    for (int i = 1; i <= exp; i++)
        result *= base;
    return result;
}

// -----------------------------
// Main function: Demonstrations
// -----------------------------
int main() {
    greet();

    int a = 5, b = 7;
    cout << "Add " << a << " + " << b << " = " << add(a, b) << endl;

    int num = 8;
    cout << num << " is even? " << (isEven(num) ? "Yes" : "No") << endl;

    cout << "Min of " << a << " and " << b << " = " << minVal(a, b) << endl;
    cout << "Max of " << a << " and " << b << " = " << maxVal(a, b) << endl;

    double r = 4.5;
    cout << "Area of circle with radius " << r << " = " << areaOfCircle(r) << endl;

    int val = 20;
    cout << "\nCall by value demo:\n";
    cout << "Before callByValueExample, val = " << val << endl;
    callByValueExample(val);
    cout << "After callByValueExample, val = " << val << endl;

    cout << "\nCall by reference demo:\n";
    cout << "Before callByReferenceExample, val = " << val << endl;
    callByReferenceExample(val);
    cout << "After callByReferenceExample, val = " << val << endl;

    int base = 2, exp = 5;
    cout << base << "^" << exp << " = " << powFunc(base, exp) << endl;

    return 0;
}
