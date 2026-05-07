#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

/*
================================================================================
                    COMPLETE BIT MANIPULATION NOTES (C++)
================================================================================
Binary System = Base 2 number system using only digits 0 and 1.

Example:
Decimal 13 = Binary 1101

Position value:
 2^3   2^2   2^1   2^0
  1     1     0     1

================================================================================
WHY UNSIGNED INT FOR BITS?
--------------------------------------------------------------------------------
signed int:
    - MSB (Most Significant Bit) = sign bit.
    - Right shift (>>) may copy the sign bit (arithmetic shift), altering data.

unsigned int:
    - ✔ Only positive numbers.
    - ✔ Predictable shifting (logical shift fills with 0s).
    - ✔ Safer and standard for bit manipulation.
================================================================================
*/


// -----------------------------------------------------------------------------
// 1. PRINT BINARY REPRESENTATION
// -----------------------------------------------------------------------------
void print_binary(unsigned int x) {
    /*
    Example: x = 5
    Output:  00000000000000000000000000000101
    */
    cout << bitset<32>(x) << '\n';
}


// -----------------------------------------------------------------------------
// 2. EVEN / ODD USING BITS
// -----------------------------------------------------------------------------
void even_odd(int x) {
    /*
    The least significant bit (LSB) decides parity.
    EVEN → LSB = 0 (e.g., 6 = 110)
    ODD  → LSB = 1 (e.g., 7 = 111)
    */
    if (x & 1) {
        cout << x << " is Odd\n";
    } else {
        cout << x << " is Even\n";
    }
}


// -----------------------------------------------------------------------------
// 3. BASIC BIT OPERATIONS
// -----------------------------------------------------------------------------
void basic_operations() {
    unsigned int a = 5; // 0101
    unsigned int b = 3; // 0011

    cout << "a : "; print_binary(a);
    cout << "b : "; print_binary(b);

    // AND (&): 1 if both bits are 1, else 0
    cout << "\nAND (a & b)\n";
    print_binary(a & b);

    // OR (|): 1 if at least one bit is 1, else 0
    cout << "\nOR (a | b)\n";
    print_binary(a | b);

    // XOR (^): 1 if bits are different, 0 if they are the same
    cout << "\nXOR (a ^ b)\n";
    print_binary(a ^ b);

    // NOT (~): Flips all bits (0 becomes 1, 1 becomes 0)
    cout << "\nNOT (~a)\n";
    print_binary(~a);
}


// -----------------------------------------------------------------------------
// 4. SHIFT OPERATIONS
// -----------------------------------------------------------------------------
void shift_operations() {
    unsigned int a = 5; // 0000...0101

    // LEFT SHIFT (<<): Equivalent to a * (2^b)
    cout << "Left shift (5 << 1) -> 10:\n";
    print_binary(a << 1);

    // RIGHT SHIFT (>>): Equivalent to a / (2^b)
    cout << "Right shift (5 >> 1) -> 2:\n";
    print_binary(a >> 1);
}


// -----------------------------------------------------------------------------
// 5. GENERATE POWERS OF TWO
// -----------------------------------------------------------------------------
void powers_of_two() {
    /*
    1 << i shifts the bit '1' to the i-th position, generating 2^i.
    */
    for (int i = 0; i < 10; i++) {
        cout << "2^" << i << " = " << (1 << i) << '\n';
    }
}


// -----------------------------------------------------------------------------
// 6. COUNT NUMBER OF SET BITS (1s)
// -----------------------------------------------------------------------------
void count_set_bits(unsigned int x) {
    cout << "Binary : ";
    print_binary(x);

    // FAST METHOD: Compiler builtin function (GCC/Clang)
    cout << "Builtin count = " << __builtin_popcount(x) << '\n';

    // MANUAL METHOD: Brian Kernighan’s algorithm or simple bit shifting
    int cnt = 0;
    unsigned int temp = x;
    while (temp) {
        cnt += (temp & 1); // Add 1 if the LSB is set
        temp >>= 1;        // Shift right by 1
    }
    cout << "Manual count  = " << cnt << '\n';
}


// -----------------------------------------------------------------------------
// 7. BIT ON / OFF / CHECK / TOGGLE
// -----------------------------------------------------------------------------
void bit_modify_demo() {
    unsigned int a = 27; // Binary: 11011
    int i = 1;           // We will target the 1st bit (0-indexed, so 2nd from right)

    cout << "Original (27):\n";
    print_binary(a);

    // TURN ON BIT: Use OR (|)
    a |= (1 << i);
    cout << "\nTurn ON bit 1:\n";
    print_binary(a);

    // TURN OFF BIT: Use AND with NOT (& ~)
    a &= ~(1 << i);
    cout << "\nTurn OFF bit 1:\n";
    print_binary(a);

    // TOGGLE BIT: Use XOR (^)
    a ^= (1 << i);
    cout << "\nToggle bit 1:\n";
    print_binary(a);

    // CHECK BIT: Use AND (&)
    if (a & (1 << i)) {
        cout << "\nCheck: Bit 1 is ON\n";
    } else {
        cout << "\nCheck: Bit 1 is OFF\n";
    }
}


// -----------------------------------------------------------------------------
// 8. BITMASKING IDEA (State Representation)
// -----------------------------------------------------------------------------
void attendance_bitmask() {
    /*
    Bitmasking = Storing MANY boolean states inside ONE number.
    Example: 10 students' attendance.
    bit i = 1 → present
    bit i = 0 → absent
    */
    int day1 = 0;
    int day2 = 0;

    // Day 1 students present: 0, 2, 4
    day1 |= (1 << 0) | (1 << 2) | (1 << 4);

    // Day 2 students present: 2, 3, 4
    day2 |= (1 << 2) | (1 << 3) | (1 << 4);

    cout << "Day1: "; print_binary(day1);
    cout << "Day2: "; print_binary(day2);

    // BOTH DAYS -> Bitwise AND
    cout << "\nPresent both days      = " << __builtin_popcount(day1 & day2);

    // ONLY ONE DAY -> Bitwise XOR
    cout << "\nPresent exactly one day = " << __builtin_popcount(day1 ^ day2);

    // AT LEAST ONCE -> Bitwise OR
    cout << "\nPresent at least once   = " << __builtin_popcount(day1 | day2) << '\n';
}


// -----------------------------------------------------------------------------
// 9. SUBSET ENUMERATION (Combinatorics)
// -----------------------------------------------------------------------------
void team_generation() {
    /*
    Players = {a, b, c, d, e, f}
    Total subsets (teams) = 2^n
    Time Complexity: $O(N \cdot 2^N)$
    */
    vector<char> players = {'a', 'b', 'c', 'd', 'e', 'f'};
    int n = players.size();
    int total_subsets = (1 << n);

    for (int mask = 0; mask < total_subsets; mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            // If the i-th bit is set in the current mask, include the i-th player
            if (mask & (1 << i)) {
                cout << players[i] << " ";
            }
        }
        cout << "}\n";
    }
}


// -----------------------------------------------------------------------------
// MAIN FUNCTION
// -----------------------------------------------------------------------------
int main() {
    cout << "==== EVEN / ODD ====\n";
    even_odd(7);

    cout << "\n==== BASIC OPERATIONS ====\n";
    basic_operations();

    cout << "\n==== SHIFT OPERATIONS ====\n";
    shift_operations();

    cout << "\n==== POWERS OF TWO ====\n";
    powers_of_two();

    cout << "\n==== COUNT SET BITS ====\n";
    count_set_bits(13);

    cout << "\n==== BIT MODIFY ====\n";
    bit_modify_demo();

    cout << "\n==== ATTENDANCE BITMASK ====\n";
    attendance_bitmask();

    cout << "\n==== TEAM GENERATION (Subsets) ====\n";
    team_generation();

    return 0;
}
