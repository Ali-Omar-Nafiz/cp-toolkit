/*
Binary search:
The container must have to be Monotonic.
Means, Sorted in descending / ascending order.
Condition: F F F F T T T T / T T T T F F F F

Lower Bound: First index i where arr[i] >= target
Upper Bound: First index i where arr[i] > target
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector < int > v = {1, 2, 3, 3, 5, 7, 9, 9, 9, 10, 12};  // must be monotonic
    int low = 0, high = 11, target = 9;
    // Lower Bound implementation:
    while (low < high) {
        int mid = low + ((high - low) / 2); // Floor
        if (v[mid] >= target) {  // TRUE
            high = mid;                // F F F F F F T T T T T 
        } else {   // False
            low = mid + 1;
        }
    }
    cout << low << endl;   // First True

    low = 0, high = 11, target = 9;
    // Upper Bound implementation
    while (low < high) {
        int mid = low + ((high - low) / 2); // Floor
        if (v[mid] > target) {  // TRUE
            high = mid;                // F F F F F F F F F T T
        } else {  // FALSE
            low = mid + 1;
        }
    }
    cout << low << endl;   // First True
}

/*
Case 1: TTTTFFFF (Last True),
- mid = ceil((low + high) / 2) // Ceil
- true, low = mid
- false, high = mid - 1

Case 2: FFFFTTTT (First True),
- mid = floor((low + high) / 2) // Floor
- true, high = mid
- false, low = mid + 1

If the binary search has implemented correctly,
then, low == high at the end is guaranteed
*/

