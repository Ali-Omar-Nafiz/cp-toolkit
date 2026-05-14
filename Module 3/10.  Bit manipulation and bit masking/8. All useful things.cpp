#include <iostream>
#include <vector>

using namespace std;

// Trick 1: Check if a number is even (last bit is 0)
bool is_Even(int x) {
    return !(x & 1);
}

// Trick 2: Check if the k-th bit is set (ON/1)
bool is_Set(int x, int k) {
    return (x & (1 << k));
}

// Trick 3: Iterate through and print all 32 bits of an integer
void iterate_Bits(int x) {
    for (int k = 0; k < 32; k++) {
        cout << ((x >> k) & 1) << ' ';
    }
}

// Trick 4: Count the total number of set (ON/1) bits manually
// (Note: You can also use the built-in __builtin_popcount(x))
int count_Set_Bits(int x) {
    int cnt = 0;
    while (x) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}

// Trick 5a: Set (turn ON) the k-th bit
int set_Bit(int x, int k) {
    return (x | (1 << k));
}

// Trick 5b: Clear (turn OFF / unset) the k-th bit
int clear_Bit(int x, int k) {
    return (x & ~(1 << k));
}

// Trick 6: Toggle (flip) the k-th bit (0 becomes 1, 1 becomes 0)
int toggle_Bit(int x, int k) {
    return (x ^ (1 << k));
}

// Trick 7a: Multiply by 2^k using Left Shift
int multiply_By_2(int x, int k) {
    return (x << k);
}

// Trick 7b: Divide by 2^k using Right Shift (floor division)
int divide_By_2(int x, int k) {
    return (x >> k);
}

// Trick 8: Remove the lowest set (ON/1) bit
int remove_Lowest_Set_Bit(int x) {
    return (x & (x - 1));
}

// Trick 9: Get the value of the lowest set (ON/1) bit
int lowest_Set_Bit(int x) {
    return (x & (-x));
}

// Trick 10 Notes (Built-ins):
// Count Trailing Zeros: __builtin_ctz(x) / __builtin_ctzll(x)
// Count Leading Zeros: __builtin_clz(x) / __builtin_clzll(x)

// Trick 11: Find the position of the highest (leftmost) set bit manually
// (Note: You can also use 31 - __builtin_clz(x) / 63 - / __builtin_ctzll(x))
int highest_Set_Bit_Position(int x) {
    for (int k = 31; k >= 0; k--) {
        if ((x >> k) & 1) {
            return k;
        }
    }
    return -1;
}

// Trick 12: Check if a number is a power of 2 (has exactly one set bit)
bool is_Power_Of_2(int x) {
    return (x > 0) && !(x & (x - 1));
}

// Trick 13: Find the only unique element in an array where all others appear twice
int unique_Element(vector<int> &a) {
    int xr = 0;
    for (int x : a) {
        xr ^= x;
    }
    return xr;
}

// Trick 14: Generate and print all possible subsets of an array using bitmasking
void generate_Subsets(vector<int> &a) {
    int n = a.size();
    // (1 << n) gives 2^n, the total number of subsets
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int k = 0; k < n; k++) {
            // If the k-th bit of the current mask is ON, include a[k]
            if ((mask >> k) & 1) {
                cout << a[k] << ' ';
            }
        }
        cout << '\n';
    }
}
