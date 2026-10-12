/***********************************************************
              ARRAY TOOLKIT (std::array)
       Quick Revision Sheet for Competitive Programming
***********************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
============================================================
1. WHAT IS ARRAY?
------------------------------------------------------------
array = fixed-size container storing elements of the SAME type

Syntax:
array<data_type, size> name;

Example:
array<int, 5> a = {1, 2, 3, 4, 5};

IMPORTANT:
- Size is fixed at compile time.
- Elements have the same data type.
- Indexing starts from 0.
- Supports STL algorithms.
============================================================
*/


// ---------------------------------------------------------
// 2. CREATION
// ---------------------------------------------------------
void creation() {

    // Explicit initialization
    array<int, 5> a = {1, 2, 3, 4, 5};

    // Partial initialization (remaining elements become 0)
    array<int, 5> b = {10, 20};

    // Initialize all elements with 0
    array<int, 5> c{};

    // Initialize all elements with the same value
    array<int, 5> d;
    d.fill(7);

    // Different data types
    array<double, 3> e = {1.2, 2.3, 3.4};
    array<char, 4> f = {'A', 'B', 'C', 'D'};
}


// ---------------------------------------------------------
// 3. ACCESS ELEMENTS
// ---------------------------------------------------------
void access() {

    array<int, 4> a = {10, 20, 30, 40};

    cout << a[0] << endl;       // 10
    cout << a[2] << endl;       // 30

    cout << a.front() << endl;  // First element: 10
    cout << a.back() << endl;   // Last element: 40

    cout << a.at(1) << endl;    // 20 (bounds-checked)
}


// ---------------------------------------------------------
// 4. MODIFY ELEMENTS
// ---------------------------------------------------------
void modify() {

    array<int, 4> a = {1, 2, 3, 4};

    a[0] = 100;
    a.at(1) = 200;

    a.fill(5);  // Every element becomes 5
}


// ---------------------------------------------------------
// 5. ITERATION
// ---------------------------------------------------------
void iteration() {

    array<int, 5> a = {10, 20, 30, 40, 50};

    // Index-based loop
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Range-based loop
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;

    // Modify elements using reference
    for (auto &x : a) {
        x *= 2;
    }
}


// ---------------------------------------------------------
// 6. SIZE AND CAPACITY
// ---------------------------------------------------------
void size_example() {

    array<int, 5> a = {1, 2, 3, 4, 5};

    cout << a.size() << endl;   // 5
    cout << a.max_size() << endl; // 5

    cout << a.empty() << endl;  // 0 (false)
}


// ---------------------------------------------------------
// 7. SORTING ⭐
// ---------------------------------------------------------
void sorting() {

    array<int, 5> a = {5, 2, 4, 1, 3};

    // Ascending order
    sort(a.begin(), a.end());

    // Descending order
    sort(a.begin(), a.end(), greater<int>());

    // Reverse order
    reverse(a.begin(), a.end());
}


// ---------------------------------------------------------
// 8. MINIMUM AND MAXIMUM ⭐
// ---------------------------------------------------------
void min_max_example() {

    array<int, 5> a = {4, 1, 9, 2, 7};

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    cout << mn << endl;  // 1
    cout << mx << endl;  // 9
}


// ---------------------------------------------------------
// 9. SUM AND ACCUMULATION ⭐
// ---------------------------------------------------------
void sum_example() {

    array<int, 5> a = {1, 2, 3, 4, 5};

    int sum = accumulate(a.begin(), a.end(), 0LL);

    cout << sum << endl;  // 15
}


// ---------------------------------------------------------
// 10. SEARCHING
// ---------------------------------------------------------
void searching() {

    array<int, 5> a = {10, 20, 30, 40, 50};

    // Linear search
    auto it = find(a.begin(), a.end(), 30);

    if (it != a.end()) {
        cout << "Found at index: "
             << it - a.begin() << endl;
    }

    // Binary search: array must be sorted
    sort(a.begin(), a.end());

    cout << binary_search(a.begin(), a.end(), 40) << endl;
}


// ---------------------------------------------------------
// 11. COUNT OCCURRENCES
// ---------------------------------------------------------
void count_example() {

    array<int, 6> a = {1, 2, 2, 3, 2, 4};

    int cnt = count(a.begin(), a.end(), 2);

    cout << cnt << endl;  // 3
}


// ---------------------------------------------------------
// 12. COMPARISON
// ---------------------------------------------------------
void comparison() {

    array<int, 3> a = {1, 2, 3};
    array<int, 3> b = {1, 2, 3};
    array<int, 3> c = {1, 2, 4};

    cout << (a == b) << endl;  // 1 (true)
    cout << (a != c) << endl;  // 1 (true)

    // Lexicographical comparison
    cout << (a < c) << endl;   // 1 (true)
}


// ---------------------------------------------------------
// 13. SWAP TWO ARRAYS
// ---------------------------------------------------------
void swap_example() {

    array<int, 3> a = {1, 2, 3};
    array<int, 3> b = {4, 5, 6};

    a.swap(b);

    // a = {4, 5, 6}
    // b = {1, 2, 3}
}


// ---------------------------------------------------------
// 14. ITERATORS
// ---------------------------------------------------------
void iterator_example() {

    array<int, 4> a = {10, 20, 30, 40};

    cout << *a.begin() << endl;   // 10
    cout << *a.rbegin() << endl;  // 40

    // Forward iteration
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iteration
    for (auto it = a.rbegin(); it != a.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


// ---------------------------------------------------------
// 15. ARRAY OF ARRAYS (2D ARRAY) ⭐
// ---------------------------------------------------------
void two_d_array() {

    array<array<int, 3>, 2> a = {{
        {1, 2, 3},
        {4, 5, 6}
    }};

    cout << a[0][1] << endl;  // 2
    cout << a[1][2] << endl;  // 6

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


// ---------------------------------------------------------
// 16. ARRAY WITH PAIR ⭐
// ---------------------------------------------------------
void array_pair() {

    array<pair<int, int>, 3> a = {{
        {1, 2},
        {3, 4},
        {5, 6}
    }};

    for (auto [x, y] : a) {
        cout << x << " " << y << endl;
    }
}


// ---------------------------------------------------------
// 17. ARRAY WITH STRUCTURED BINDING
// ---------------------------------------------------------
void structured_binding() {

    array<int, 3> a = {10, 20, 30};

    auto [x, y, z] = a;

    cout << x << " " << y << " " << z << endl;

    // x, y, z are copies.
    // Use auto &[x, y, z] = a to modify the original array.
}


// ---------------------------------------------------------
// 18. INITIALIZE WITH INDEX VALUES
// ---------------------------------------------------------
void index_initialization() {

    array<int, 5> a;

    for (int i = 0; i < (int)a.size(); i++) {
        a[i] = i;
    }

    // a = {0, 1, 2, 3, 4}
}


// ---------------------------------------------------------
// 19. PASS ARRAY TO A FUNCTION
// ---------------------------------------------------------
int array_sum(array<int, 5> a) {

    int sum = 0;

    for (auto x : a) {
        sum += x;
    }

    return sum;
}

void function_example() {

    array<int, 5> a = {1, 2, 3, 4, 5};

    cout << array_sum(a) << endl;  // 15
}


// ---------------------------------------------------------
// 20. ARRAY VS VECTOR
// ---------------------------------------------------------
void array_vs_vector() {

    array<int, 3> a = {1, 2, 3};

    vector<int> v = {1, 2, 3};

    // array: fixed size
    // vector: dynamic size

    v.push_back(4);  // Allowed

    // a.push_back(4);  // ERROR: array has no push_back()
}


/*
============================================================
QUICK MEMORY CHEATSHEET
------------------------------------------------------------
Creation       -> array<int, N> a = {...}
Access         -> a[i] / a.at(i)
First / Last   -> a.front() / a.back()
Size           -> a.size()
Initialize     -> a.fill(value)
Sort           -> sort(a.begin(), a.end())
Reverse        -> reverse(a.begin(), a.end())
Min / Max      -> *min_element(...) / *max_element(...)
Sum            -> accumulate(a.begin(), a.end(), 0LL)
Search         -> find(a.begin(), a.end(), value)
Binary Search  -> binary_search(a.begin(), a.end(), value)
Count          -> count(a.begin(), a.end(), value)
Iterate        -> for (auto x : a)
Modify         -> for (auto &x : a)
Swap           -> a.swap(b)
2D Array       -> array<array<int, C>, R>
Pair Array     -> array<pair<int, int>, N>

IMPORTANT:
1. std::array has a fixed size.
2. Indexing starts from 0.
3. All elements have the same type.
4. sort() and binary_search() need iterators.
5. binary_search() requires sorted data.
6. at() checks bounds; operator[] does not.
7. Use vector when the size needs to change.
============================================================
*/


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Array Toolkit Ready\n";

    return 0;
}
