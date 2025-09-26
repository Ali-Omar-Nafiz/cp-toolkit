#include <bits/stdc++.h>
using namespace std;

int main() {
    // -------------------------------
    // 1. Basic structure of a C/C++ program
    // -------------------------------
    // Includes, main() function, return 0

    // -------------------------------
    // 2. printf / cout and comments
    // -------------------------------
    printf("Hello from printf (C style)\n");
    cout << "Hello from cout (C++ style)" << endl; // single-line comment
    /* multi-line
       comment example */

    // -------------------------------
    // 3. Variables, Data Types, Format Specifiers
    // -------------------------------
    int a = 10;
    float b = 5.25;
    char c = 'X';

    printf("int: %d, float: %.2f, char: %c\n", a, b, c);

    // -------------------------------
    // 4. How to print variables (C++ way)
    // -------------------------------
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // -------------------------------
    // 5. Taking input using scanf
    // -------------------------------
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x); // & is needed to give the ADDRESS of variable
    printf("You entered: %d\n", x);

    // -------------------------------
    // 6. Different data types & their size/range
    // -------------------------------
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of char: %zu bytes\n", sizeof(char));

    // -------------------------------
    // 7. Long long & Double
    // -------------------------------
    long long bigNum = 10000000000LL; // use long long to avoid overflow
    double pi = 3.141592653589793;
    cout << "bigNum = " << bigNum << ", pi = " << pi << endl;

    // Example: Integer overflow
    int overflowTest = 1000000 * 1000000; // may overflow
    long long safeCalc = 1000000LL * 1000000LL; // safe
    cout << "overflowTest = " << overflowTest << " (may be wrong)\n";
    cout << "safeCalc = " << safeCalc << " (correct)\n";

    // -------------------------------
    // 8. Type casting
    // -------------------------------
    int p = 5, q = 2;
    cout << "Integer division p/q = " << p / q << endl; // 2
    cout << "Typecasted division (double)p/q = " << (double)p / q << endl; // 2.5

    // -------------------------------
    // 9. Operators
    // -------------------------------
    int sum = p + q, diff = p - q, prod = p * q, divv = p / q;
    cout << "sum=" << sum << " diff=" << diff << " prod=" << prod << " div=" << divv << endl;

    // -------------------------------
    // 10. Integer Division & Last Digit Extraction (without modulo)
    // -------------------------------
    int num = 1234;
    int lastDigit = num - (num / 10) * 10; // trick without %
    cout << "Last digit of " << num << " = " << lastDigit << endl;

    // -------------------------------
    // 11. ASCII values
    // -------------------------------
    char ch = 'A';
    cout << "Character: " << ch << ", ASCII value: " << (int)ch << endl;

    // -------------------------------
    // PRACTICE PROBLEMS
    // -------------------------------
    // Problem 1: Sum of two numbers
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    cout << "Sum = " << n1 + n2 << endl;

    // Problem 2: Check even or odd
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n % 2 == 0) cout << n << " is Even\n";
    else cout << n << " is Odd\n";

    // -------------------------------
    // CUSTOM TASKS
    // -------------------------------
    // Task 1: Find ASCII of an input character
    char userChar;
    cout << "Enter a character: ";
    cin >> userChar;
    cout << "ASCII value of " << userChar << " = " << (int)userChar << endl;

    // Task 2: Extract last digit of a number without using %
    int userNum;
    cout << "Enter a number: ";
    cin >> userNum;
    cout << "Last digit = " << userNum - (userNum / 10) * 10 << endl;

    // Task 3: Demonstrate typecasting
    double d = 9.99;
    cout << "Double = " << d << ", casted to int = " << (int)d << endl;

    return 0;
}
