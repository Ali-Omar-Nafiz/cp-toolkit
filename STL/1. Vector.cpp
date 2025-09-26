#include <bits/stdc++.h>
using namespace std;

int main() {
    // basic vector usage:
    vector<int> v;
    while (true) {
        int x;
        cin >> x;
        if (x == 0) break;
        v.push_back(x);        // push value x to the back of v; amortized O(1)
    }

    // reverse printing:
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
        // v.size() returns the number of elements (O(1))
    }
    cout << "\n";

    // sorting:
    sort(v.begin(), v.end());
    // v.begin()  -> iterator pointing to first element of v
    // v.end()    -> iterator pointing **one past** the last element of v

    // vector declaration with size:
    int n = 10; // assume some n
    vector<int> v1(n);          // n elements, all default-initialized to 0
    vector<int> v2(n, 10);      // n elements, all initialized to 10
    v2.push_back(11);           // add 11 to the back; size increases by 1
    int val = v2[8];            // access element at index 8 (0-based)

    // range-based for loops:
    vector<int> ara = {5, 6, 7};

    // copy version:
    for (int x : ara) {
        cout << x << "\n"; // x is a copy of each element
    }

    // reference version:
    for (int &x : ara) {
        cout << x << "\n"; // x is a reference to each element
        // if we change x here (e.g. x += 1), the original ara element changes
    }

    // multidimensional vector examples:

    int arr[4][7]; // 4 rows, 7 columns (classic array)

    vector<int> vv[5]; // array of 5 vectors<int>, each initially empty

    vector<vector<int>> big;   // a vector of vector<int> (empty initially)
    vector<int> tmp = {2, 4, 5};
    vector<int> tmp2 = {5, 9, 11};
    big.push_back(tmp);  // push tmp as first row
    big.push_back(tmp2); // push tmp2 as second row

    /*
    big now equals:
    {
       {2, 4, 5},
       {5, 9, 11}
    }
    */

    cout << big.size() << "\n";     // prints 2
    for (auto x : big) {            // x is a copy of each inner vector
        cout << x.size() << "\n";
        for (auto y : x) cout << y << " ";
        cout << "\n";
    }

    // reference version (more efficient, avoids copying):
    for (auto &x : big) {           // x is a reference to each inner vector
        cout << x.size() << "\n";
        for (auto y : x) cout << y << " ";
        cout << "\n";
    }

    // declaration with size for 2-D vector:
    // 6 rows each having 5 elements initialized to 0:
    vector<vector<int>> mat(6, vector<int>(5));

    // Some other useful member functions:
    // v.back()     -> returns reference to last element (O(1))
    // v.pop_back() -> removes last element (O(1))
    // v.erase(it)  -> erases element at iterator it (O(n) worst case, because it shifts elements)

    vector<int> v = {10, 20, 30, 40, 50};

    // v.back(): reference to last element
    cout << "Last element: " << v.back() << "\n"; // prints 50

    // you can also modify the last element:
    v.back() = 99; // changes last element to 99
    cout << "After modifying last element: ";
    for (int x : v) cout << x << " "; // 10 20 30 40 99
    cout << "\n";

    // v.pop_back(): removes last element
    v.pop_back(); // removes 99
    cout << "After pop_back(): ";
    for (int x : v) cout << x << " "; // 10 20 30 40
    cout << "\n";

    // v.erase(): remove an element at a given position
    // erase requires an iterator, like v.begin()+index
    v.erase(v.begin() + 1); // removes the element at index 1 (20)
    cout << "After erase index 1: ";
    for (int x : v) cout << x << " "; // 10 30 40
    cout << "\n";

    // erase a range:
    // e.g. erase all elements except first
    v.erase(v.begin() + 1, v.end()); // removes from index 1 to end
    cout << "After erase range: ";
    for (int x : v) cout << x << " "; // 10
    cout << "\n";

    return 0;
}

// Passing vector to a function:

// pass by value (makes a copy):
void processCopy(vector<int> v) {
    v.push_back(42); // modifies the copy only
}

// pass by reference (no copy):
void processRef(vector<int>& v) {
    v.push_back(42); // modifies the original vector
}

/*
Difference:
- pass by value copies the whole vector (O(n)), original unchanged.
- pass by reference just gives the function a reference (O(1)), original changed.
*/


