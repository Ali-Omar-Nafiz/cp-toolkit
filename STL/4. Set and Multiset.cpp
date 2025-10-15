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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ====================================================
    // 1️⃣  DECLARATION AND INSERTION
    // ====================================================

    set<int> st;
    /*
       Syntax: set<data_type> name;
       Stores unique, sorted elements (ascending order by default)
    */

    // insert(value) → O(log n)
    // Return Type: pair<iterator, bool>
    st.insert(5);
    st.insert(1);
    st.insert(3);
    st.insert(5);  // duplicate ignored
    st.insert(2);

    cout << "Set elements (sorted unique): ";
    for (auto it = st.begin(); it != st.end(); ++it) // (set<int>::iterator it)
        cout << *it << " ";
    cout << "\n";

    // ====================================================
    // 2️⃣  ERASE
    // ====================================================

    // erase(value) → O(log n)
    // Return Type: size_t (number of elements removed)
    st.erase(3);  
    cout << "After erase(3): ";
    for (auto it = st.begin(); it != st.end(); ++it) // (set<int>::iterator it)
        cout << *it << " ";
    cout << "\n";

    // ====================================================
    // 3️⃣  ITERATORS
    // ====================================================

    // begin() → iterator to first element (O(1))
    // end()   → iterator to one past the last element (O(1))
    cout << "First element: " << *st.begin() << "\n";

    // prev(st.end()) → iterator to last element (O(1))
    cout << "Last element using *prev(st.end()): " << *prev(st.end()) << "\n";

    // (--st.end()) also gives last element
    cout << "Alternative last element *(--st.end()): " << *(--st.end()) << "\n";

    // next(st.begin()) → iterator to 2nd element (O(1))
    cout << "Second element using *next(st.begin()): " << *next(st.begin()) << "\n";

    // ====================================================
    // 4️⃣  ERASE USING ITERATOR
    // ====================================================

    // erase(iterator) → O(log n)
    // Return Type: void
    auto it1 = st.begin(); // (set<int>::iterator it1)
    st.erase(it1);
    cout << "After erasing first element: ";
    for (auto it = st.begin(); it != st.end(); ++it) // (set<int>::iterator it)
        cout << *it << " ";
    cout << "\n";

    // ====================================================
    // 5️⃣  FIND & ERASE USING FIND
    // ====================================================

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
    auto it2 = st.find(val); // (set<int>::iterator it2)
    if (it2 != st.end()) {
        cout << "Found " << val << ", erasing it.\n";
        st.erase(it2); // erase(iterator) → O(log n)
    }

    cout << "After erasing using find(): ";
    for (auto it = st.begin(); it != st.end(); ++it) // (set<int>::iterator it)
        cout << *it << " ";
    cout << "\n";

    // What happens if st.find(non-existing element)?
    // → Returns st.end(), safe if checked before use
    int nonexist = 99;
    auto it3 = st.find(nonexist); // (set<int>::iterator it3)
    if (it3 == st.end()) cout << "Element " << nonexist << " not found!\n";

    // ====================================================
    // 6️⃣  COUNT
    // ====================================================

    /*
       count(value)
       → Returns 1 if element exists, else 0
       Time Complexity: O(log n)
       Return Type: size_t
    */
    cout << "st.count(5): " << st.count(5) << " (1 means exists, 0 means not)\n";

    // ====================================================
    // 7️⃣  LOWER_BOUND / UPPER_BOUND
    // ====================================================

    st.insert(10);
    st.insert(12);

    cout << "\nSet elements now: ";
    for (auto it = st.begin(); it != st.end(); ++it) // (set<int>::iterator it)
        cout << *it << " ";
    cout << "\n";

    /*
       lower_bound(value)
         → iterator to first element >= value
       upper_bound(value)
         → iterator to first element > value
       Time Complexity: O(log n)
       Return Type: iterator
    */

    cout << "Lower bound of 8: " << *st.lower_bound(8) << "\n";
    cout << "Upper bound of 8: " << *st.upper_bound(8) << "\n";

    // ====================================================
    // 8️⃣  CUSTOM COMPARATOR
    // ====================================================

    /*
       set<int, greater<int>> st;
       → Stores elements in descending order
    */

    set<int, greater<int>> gst;
    gst.insert(10);
    gst.insert(5);
    gst.insert(7);

    cout << "\nSet with greater<int> (descending order): ";
    for (auto it = gst.begin(); it != gst.end(); ++it) // (set<int, greater<int>>::iterator it)
        cout << *it << " ";
    cout << "\n";

    // ====================================================
    // 9️⃣  MULTISET
    // ====================================================

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

    cout << "\nMultiset elements (duplicates allowed): ";
    for (auto it = mst.begin(); it != mst.end(); ++it) // (multiset<int>::iterator it)
        cout << *it << " ";
    cout << "\n";

    /*
       erase(value)
       → Removes ALL occurrences of that value
       Time Complexity: O(log n + count(value))
       Return Type: size_t
    */
    mst.erase(5);
    cout << "After mst.erase(5): ";
    for (auto it = mst.begin(); it != mst.end(); ++it) // (multiset<int>::iterator it)
        cout << *it << " ";
    cout << "\n";

    mst.insert(5);
    mst.insert(5);
    mst.insert(6);

    /*
       erase(iterator)
       → Removes ONE occurrence only
       Time Complexity: O(log n)
       Return Type: void
    */
    auto it4 = mst.find(5); // (multiset<int>::iterator it4)
    if (it4 != mst.end()) mst.erase(it4);
    cout << "After mst.erase(mst.find(5)): ";
    for (auto it = mst.begin(); it != mst.end(); ++it) // (multiset<int>::iterator it)
        cout << *it << " ";
    cout << "\n";

    /*
       lower_bound(value), upper_bound(value)
       → Same behavior as in set
       Time Complexity: O(log n)
       Return Type: iterator
    */
    cout << "mst.lower_bound(5): " << *mst.lower_bound(5) << "\n";
    cout << "mst.upper_bound(5): " << *mst.upper_bound(5) << "\n";

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
