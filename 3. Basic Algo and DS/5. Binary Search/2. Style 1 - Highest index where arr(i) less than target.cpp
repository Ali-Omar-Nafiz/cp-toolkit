// Highest index where arr[i] < target:

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector < int > v = {1, 2, 3, 3, 5, 7, 9, 9, 9, 10, 12};  // must be monotonic
    int low = 0, high = 11, target = 9;
    // Implementation:
    while (low < high) {
        int mid = low + ((high - low + 1) / 2); // Ceil
        if (v[mid] < target) {  // TRUE
            low = mid;               // T T T T T T F F F F F
        } else {  // FALSE
            high = mid - 1;
        }
    }
    cout << low << endl;   // Last True
    return 0;
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

