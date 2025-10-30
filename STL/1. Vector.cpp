#include <bits/stdc++.h>
using namespace std;

int main() {
    // basic vector usage:
    vector<int> v;
    // initializing
    int x;
    cin >> x;
    v.push_back(x);      // push value x to the back of v; amortized O(1)

    // accessing
    cout << v[0] << "\n";  // index based access

    // size()
    cout << v.size() << "\n";   // v.size() returns the number of elements (O(1))

    // sorting:
    sort(v.begin(), v.end());
    // v.begin()  -> iterator pointing to first element of v
    // v.end()    -> iterator pointing **one past** the last element of v

    // vector declaration with size:
    int n = 10; // assume some n
    vector<int> v1(n);          // n elements, all default-initialized to 0
    // v1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    vector<int> v2(n, 10);      // n elements, all initialized to 10
    // v2 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}
    v2.push_back(11);           // add 11 to the back; size increases by 1
    // v2 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11}

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
    /*
    vv = {
          {},
          {},
          {},
          {},
          {}
         };          
    */


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

    vector<int> v3 = {10, 20, 30, 40, 50};

    // v.back(): reference to last element
    cout <<  v3.back() << "\n"; // prints 50

    // you can also modify the last element:
    v3.back() = 99; // changes last element to 99
    for (int x : v3) cout << x << " "; // 10 20 30 40 99
    cout << "\n";

    // v.pop_back(): removes last element
    v3.pop_back(); // removes 99
    for (int x : v3) cout << x << " "; // 10 20 30 40
    cout << "\n";

    // v.erase(position): remove an element at a given position
    // erase requires an iterator, like v.begin()+index
    v3.erase(v3.begin() + 1); // removes the element at index 1 (20)
    for (int x : v3) cout << x << " "; // 10 30 40
    cout << "\n";

    // erase a range:
    // e.g. erase all elements except first
    v3.erase(v3.begin() + 1, v3.end()); // removes from index 1 to end
    for (int x : v3) cout << x << " "; // 10
    cout << "\n";


    // ==========================
    // INSERT (Examples)
    // ==========================

    vector<int> myvector(3, 100); // {100,100,100}

    // Insert single element at beginning
    myvector.insert(myvector.begin(), 200); // {200,100,100,100}

    // Insert two elements of value 300 at beginning
    myvector.insert(myvector.begin(), 2, 300); // {300,300,200,100,100,100}

    // Insert elements from another vector
    vector<int> anothervector(2, 400); // {400,400}
    myvector.insert(myvector.begin() + 2, anothervector.begin(), anothervector.end());
    // {300,300,400,400,200,100,100,100}

    // Insert elements from array (using vector)
    vector<int> myarray = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray.begin(), myarray.end());
    // {501,502,503,300,300,400,400,200,100,100,100}

    for (int value : myvector) {
        cout << " " << value;
    }
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

/*
==============================================
|         STL VECTOR FUNCTION SUMMARY         |
==============================================

Basic Operations:
----------------------------------------------------
push_back(x)           → Amortized O(1)
pop_back()             → O(1)
size()                 → O(1)
empty()                → O(1)
back() / front()       → O(1)
clear()                → O(n)
resize(n)              → O(n)
assign(...)            → O(n)
operator[] / at(i)     → O(1)

Iterator Related:
----------------------------------------------------
begin(), end()         → O(1)
rbegin(), rend()       → O(1)

Insertion/Deletion:
----------------------------------------------------
insert(pos, val)       → O(n)  (may shift elements)
insert(pos, count, val)→ O(n)
insert range           → O(n)
erase(pos)             → O(n)
erase(range)           → O(n)
swap(v2)               → O(1)
emplace(pos, val)      → O(n) (similar to insert)

Memory Management:
----------------------------------------------------
capacity()             → O(1)
reserve(k)             → O(n) (if reallocation occurs)
shrink_to_fit()        → O(n)

Algorithms:
----------------------------------------------------
sort(v.begin(), v.end())      → O(n log n)
reverse(v.begin(), v.end())   → O(n)
find(v.begin(), v.end(), x)   → O(n)
count(v.begin(), v.end(), x)  → O(n)

Passing Vectors:
----------------------------------------------------
By Value (copy)        → O(n)
By Reference (&)       → O(1)

Multidimensional Vectors:
----------------------------------------------------
vector<vector<int>> v2D(r, vector<int>(c, val))  → O(r * c)

==============================================
Summary:
- Access: O(1)
- Insertion/Deletion at end: O(1) amortized
- Insertion/Deletion in middle: O(n)
- Search (linear): O(n)
- Sorting: O(n log n)
==============================================
*/
