#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 5, b = 3; // binary: a=0101, b=0011

    // ---------------------------
    // 1. Basic Bitwise Operators
    // ---------------------------
    cout << "a = " << a << " , b = " << b << endl;
    cout << "a & b  (AND)  = " << (a & b) << endl;  // 0101 & 0011 = 0001 = 1
    cout << "a | b  (OR)   = " << (a | b) << endl;  // 0101 | 0011 = 0111 = 7
    cout << "a ^ b  (XOR)  = " << (a ^ b) << endl;  // 0101 ^ 0011 = 0110 = 6
    cout << "~a    (NOT)  = " << (~a) << endl;      // bitwise negation (2's complement)

    // ---------------------------
    // 2. Left Shift & Right Shift
    // ---------------------------
    cout << "\nLeft shift (a << 1)  = " << (a << 1) << "  (5*2=10)" << endl;
    cout << "Right shift (a >> 1) = " << (a >> 1) << "  (5/2=2)" << endl;

    // Properties:
    // a << k = a * 2^k
    // a >> k = a / 2^k (floor division)

    // ---------------------------
    // 3. Even / Odd using AND
    // ---------------------------
    int num = 13;
    if (num & 1) cout << "\n" << num << " is ODD\n";
    else cout << "\n" << num << " is EVEN\n";

    // ---------------------------
    // 4. Find i-th Bit (0-indexed from right)
    // ---------------------------
    int i = 2;
    int ithBit = (a >> i) & 1;
    cout << "\n" << i << "-th bit of a (" << a << ") = " << ithBit << endl;

    // ---------------------------
    // 5. Bit Flip (toggle all bits)
    // ---------------------------
    int x = 7; // 0111
    cout << "\nBit flip (~x) of " << x << " = " << (~x) << endl;

    // ---------------------------
    // 6. Flip n-th Bit
    // ---------------------------
    int n = 1;
    int flipped = x ^ (1 << n);  // XOR with mask
    cout << "Flipping " << n << "-th bit of " << x << " = " << flipped << endl;

    // ---------------------------
    // 7. Set n-th Bit
    // ---------------------------
    int setN = x | (1 << n);
    cout << "Set " << n << "-th bit of " << x << " = " << setN << endl;

    // ---------------------------
    // 8. Unset n-th Bit (clear bit)
    // ---------------------------
    int unsetN = x & ~(1 << n);
    cout << "Unset " << n << "-th bit of " << x << " = " << unsetN << endl;

    // ---------------------------
    // 9. Check if n-th bit is set
    // ---------------------------
    if (x & (1 << n)) cout << n << "-th bit is SET\n";
    else cout << n << "-th bit is NOT set\n";

    return 0;
}
