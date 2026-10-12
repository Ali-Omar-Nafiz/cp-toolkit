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

/* ===================================================================
   🔸 SUMMARY OF BITWISE OPERATORS TOOLKIT 🔸

   ✅ BASIC BITWISE OPERATORS:
      &  → AND       → 1 if both bits are 1
      |  → OR        → 1 if at least one bit is 1
      ^  → XOR       → 1 if bits are different
      ~  → NOT       → Inverts all bits (2’s complement for signed)

   ✅ SHIFT OPERATORS:
      a << k  → a * 2^k   (Left shift = multiply by 2^k)
      a >> k  → a / 2^k   (Right shift = divide by 2^k)

   ✅ COMMON USES:
      - Check even/odd:      (n & 1)
      - Get i-th bit:        (n >> i) & 1
      - Set i-th bit:        n | (1 << i)
      - Clear i-th bit:      n & ~(1 << i)
      - Flip i-th bit:       n ^ (1 << i)
      - Check bit set:       if (n & (1 << i)) …

   ✅ NOTES:
      - Bit positions are 0-indexed (LSB = bit 0)
      - Works efficiently for bitmasking, toggling flags, etc.
      - Common in low-level operations and competitive programming.

   ⚙️ COMPLEXITY:
      All bitwise operations → O(1)
=================================================================== */
