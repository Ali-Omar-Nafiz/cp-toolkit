#include <bits/stdc++.h>
using namespace std;

/*
=====================================================
        STL SET & MULTISET TOOLKIT (CPP)
=====================================================

SET:
-----
- Stores unique elements in sorted order.
- Implemented using a Red-Black Tree (balanced BST).
- Time Complexity: O(log n) for most operations.
- No duplicates allowed.
- Elements are immutable (cannot modify via iterator).

MULTISET:
---------
- Same as set but allows duplicates.
- Elements remain sorted.
- Time Complexity: O(log n) for most operations.
=====================================================
*/

int main() {
    // ----------------------Set--------------------------

    // Declaration

    set<int> st;
    /*
       Syntax: set<data_type> name;
       Stores unique, sorted elements (ascending order by default)
    */

    // Initialization

    // insert(value) → O(log n)
    st.insert(5);
    st.insert(1);
    st.insert(3);
    st.insert(5);  // duplicate ignored
    st.insert(2);

    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << " ";   // prints 1 2 3 5

    // Iteration

    // begin() → iterator to first element (O(1))
    // end()   → iterator to one past the last element (O(1))
    cout << *st.begin() << "\n";   // prints 1

    // prev(st.end()) → iterator to last element (O(1))
    cout << *prev(st.end()) << "\n";   // prints 5

    // (--st.end()) also gives last element
    cout << *(--st.end()) << "\n";    // prints 5

    // next(st.begin()) → iterator to 2nd element (O(1))
    cout << *next(st.begin()) << "\n";   // prints 1


    // Erasing

    // erase(value) → O(log n)
    // Return Type: size_t (number of elements removed)
    st.erase(3);  
    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << " ";   // prints 1 2 5

    // erase(iterator) → O(log n)
    // Return Type: void
    auto it1 = st.begin();
    st.erase(it1);
    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << " ";  // prints 2 5
    cout << "\n";

    // Find elements

    st.insert(7);
    st.insert(8);

    /*
       find(value)
       → Returns iterator to the element if found
         else returns st.end()
       Time Complexity: O(log n)
       Return Type: iterator
    */

    int val = 7;
    auto it2 = st.find(val); // returns iterator to the 7

    if (it2 != st.end()) {   // means if found
        st.erase(it2); 
    }

    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << " ";   // prints 2 5 8

    // What happens if st.find(non-existing element)?
    // → Returns st.end(), safe if checked before use
    int nonexist = 99;
    auto it3 = st.find(nonexist);
    if (it3 == st.end())  // means if not found


    /*
       count(value)
       → Returns 1 if element exists, else 0
       Time Complexity: O(log n)
       Return Type: size_t
    */
    cout << st.count(5);   // (prints 1 if 5 exists, else 0)

   // LOWER_BOUND / UPPER_BOUND

    st.insert(10);
    st.insert(12);

    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << " ";   // prints 2 5 8 10 12

    /*
       lower_bound(value)
         → iterator to first element >= value
       upper_bound(value)
         → iterator to first element > value
       Time Complexity: O(log n)
       Return Type: iterator
    */

    cout << *st.lower_bound(8) << "\n";
    cout << *st.upper_bound(8) << "\n";

    
    // Custom Comparator

    /*
       set<int, greater<int>> st;
       → Stores elements in descending order
    */

    set<int, greater<int>> gst;
    gst.insert(10);
    gst.insert(5);
    gst.insert(7);

    for (auto it = gst.begin(); it != gst.end(); ++it) // (set<int, greater<int>>::iterator it)
        cout << *it << " ";   // prints 12 10 8 7 5 2


    //--------------------Multiset---------------------------

    multiset<int> mst;
    /*
       multiset<data_type> name;
       - Allows duplicates
       - Sorted order maintained
       - Underlying structure: Red-Black Tree
    */

    // insert(value) → O(log n)
    mst.insert(5);
    mst.insert(5);
    mst.insert(3);
    mst.insert(7);

    for (auto it = mst.begin(); it != mst.end(); ++it)
        cout << *it << " ";   // prints 3 5 5 7

    /*
       erase(value)
       → Removes ALL occurrences of that value
       Time Complexity: O(log n + count(value))
       Return Type: size_t
    */
    mst.erase(5);
    for (auto it = mst.begin(); it != mst.end(); ++it)
        cout << *it << " ";   // prints 3 7

    mst.insert(5);
    mst.insert(5);
    mst.insert(6);

    /*
       erase(iterator)
       → Removes ONE occurrence only (probably the first)
       Time Complexity: O(log n)
       Return Type: void
    */
    auto it4 = mst.find(5);
    if (it4 != mst.end()) mst.erase(it4);   // erase the first 5
    for (auto it = mst.begin(); it != mst.end(); ++it)
        cout << *it << " ";    // prints 3 5 6 7

    /*
       lower_bound(value), upper_bound(value)
       → Same behavior as in set
       Time Complexity: O(log n)
       Return Type: iterator
    */
    cout << *mst.lower_bound(5) << "\n";
    cout << *mst.upper_bound(5) << "\n";

    return 0;
}

/*
=====================================================
        SUMMARY OF TIME COMPLEXITY
=====================================================

SET / MULTISET OPERATIONS:
---------------------------
insert(x)           → O(log n)
erase(x)            → O(log n)
erase(iterator)     → O(log n)
find(x)             → O(log n)
count(x)            → O(log n)
lower_bound(x)      → O(log n)
upper_bound(x)      → O(log n)
begin(), end()      → O(1)
next(), prev()      → O(1)
clear()             → O(n)

=====================================================
RETURN TYPES:
-----------------------------------------------------
insert(x)           → pair<iterator, bool>
erase(x)            → size_t
erase(iterator)     → void
find(x)             → iterator
count(x)            → size_t
lower_bound(x)      → iterator
upper_bound(x)      → iterator
begin(), end()      → iterator
next(), prev()      → iterator
=====================================================
*/
