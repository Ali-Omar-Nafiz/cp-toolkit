#include <bits/stdc++.h>
using namespace std;

int main() {
    // ---------------------- PAIR ----------------------
    // pair: a data type that stores two elements (can be of any type)
    pair<string, int> p;

    // initializing

    // Syntax 1: using initializer list
    p = {"Nafiz", 20};

    // Syntax 2: assigning manually
    p.first = "Nafiz";
    p.second = 20;

    // Accessing

    // Old method
    cout << "Name: " << p.first << ", Age: " << p.second << "\n\n";

    // Modern method
    auto [a, b] = p;
    cout << "Name: " << a << ", Age: " << b << "\n\n";

    // Vector of pairs example
    vector<pair<string, int>> v = {
        {"Alice", 23},
        {"Bob", 19},
        {"Charlie", 25},
        {"David", 21},
        {"Alice", 18}
    };

    // Before sort
    for (auto &x : v)
        cout << x.first << " " << x.second << "\n";

    // Default sorting (non-decreasing)
    // Sorts by .first; if .first are equal, then by .second
    sort(v.begin(), v.end());

    // After sort
    for (auto [x, y] : v)
        cout << x << " " << y << "\n";

    // Default sorting (non-increasing)
    // Using reverse iterators rbegin() and rend()
    sort(v.rbegin(), v.rend());

    // After sorting
    for (auto [x, y] : v) {
        cout << x << " " << y << "\n";
    }


    // ---------------------- MAP ----------------------
    
    // map: a key-value pair container
    // Conceptually, you can think of a map as a collection (like an array) of pairs,
    // because each element is stored as a pair <key, value>. 
    // But unlike an array, map is automatically sorted by key and supports fast key-based lookup.

    map<string, string> mp;

    // Two ways to insert values
    mp["Nafiz"] = "Good";  // like arr[index] = value;  // preferred
    mp.insert({"Alice", "Excellent"});
    mp.insert({"Bob", "Average"});
    mp.insert({"Charlie", "Brilliant"});
    mp.insert({"David", "Nice"});

    // Access value using key (like accessing array index)
    cout << mp["Nafiz"] << "\n";  // prints "Good"
    cout << mp["Alice"] << "\n";  // prints "Excellent"

    // mp.count(key) -> checks if key exists (returns 1 or 0)
    cout << mp.count("Nafiz") << "\n";     // returns 1
    cout << mp.count("Unknown") << "\n";   // returns 0

    // Iterating through map (sorted by key automatically)

    // Old version
    for (auto &x : mp)
        cout << x.first << " : " << x.second << "\n";

    // Modern version
    for (auto [key, value] : mp) {
        cout << key << " : " << value << "\n";
    }

    // ---------------------- lower_bound & upper_bound ----------------------
    /*
        lower_bound(key)  -> iterator to first element >= key
        upper_bound(key)  -> iterator to first element > key
    */

    string key = "Bob";
    auto it1 = mp.lower_bound(key);   // iterator of the element that greater or equal to "Bob"
    auto it2 = mp.upper_bound(key);   // iterator of the element that greater than "Bob"

    if (it1 != mp.end()) cout << it1->first << " -> " << it1->second << "\n";  
    else if (it1 == mp.end())    // no elements found

    cout << "upper_bound(\"" << key << "\"): ";
    if (it2 != mp.end()) cout << it2->first << " -> " << it2->second << "\n";
    else if (it2 == mp.end())    // no elements found

    // Try with a non-existing key
    key = "Bunny";
    it1 = mp.lower_bound(key);
    it2 = mp.upper_bound(key);

    cout << "lower_bound(\"" << key << "\"): ";
    if (it1 != mp.end()) cout << it1->first << " -> " << it1->second << "\n";
    else if (it1 == mp.end())    // no elements found

    cout << "upper_bound(\"" << key << "\"): ";
    if (it2 != mp.end()) cout << it2->first << " -> " << it2->second << "\n";
    else if (it2 == mp.end())    // no elements found

    // mp.clear() -> removes all elements
    mp.clear();
    cout << mp.size() << "\n";  // prints 0

    // Even after clear, accessing mp["anything"] gives a default value of that data type
    // For int map, default would be 0
    map<string, int> score;
    cout << score["Rahim"] << "\n";  // prints 0

    return 0;
}

/*
=====================================================
|              STL PAIR & MAP TOOLKIT SUMMARY        |
=====================================================

-------------------------
PAIR
-------------------------
pair<T1, T2> p;                     → Declaration
p = {first, second};                → Initialization
p.first, p.second                   → Access
make_pair(a, b)                     → Create pair
tie(x, y) = p;                      → Unpack values
compare (==, <, >, etc.)            → Lexicographical
sort(vector<pair<T1, T2>>)          → Sorts by .first, then .second
swap(p1, p2)                        → O(1)

TIME COMPLEXITY:
- Access (p.first / p.second): O(1)
- Assignment / Creation: O(1)
- Comparison: O(1)
- Sorting vector<pair>: O(n log n)

-------------------------
MAP (Ordered Map)
-------------------------
map<Key, Value> mp;                 → Declaration
mp[key] = val;                      → Insert / Update (O(log n))
mp.insert({key, val});              → Insert (O(log n))
mp.erase(key);                      → Erase key (O(log n))
mp.clear();                         → Remove all (O(n))
mp.size();                          → O(1)
mp.empty();                         → O(1)
mp.count(key);                      → Check if exists (O(log n))
mp.find(key);                       → Returns iterator to key (O(log n))
mp.lower_bound(key);                → ≥ key (O(log n))
mp.upper_bound(key);                → > key (O(log n))
mp.begin(), mp.end();               → O(1)
Iterating over map                  → O(n)

KEY PROPERTIES:
- Keys are **unique**.
- Automatically **sorted by key** (ascending order).
- Implemented as a **balanced BST (red-black tree)**.
- Accessing non-existent key auto-inserts with **default value**.

DEFAULT VALUES:
- int → 0
- string → ""
- char → '\0'
- double → 0.0

EXAMPLES:
-----------------------------------------------------
map<string,int> mp;
mp["Alice"] = 10;   // insert
mp["Bob"] += 5;     // update
for (auto &x : mp) cout << x.first << " " << x.second;
-----------------------------------------------------

COMPLEXITY SUMMARY:
-----------------------------------------------------
Access (by key):              O(log n)
Insert / Erase:               O(log n)
Find / Count / Bound:         O(log n)
Iteration (entire map):       O(n)
Clear():                      O(n)
-----------------------------------------------------

-------------------------
UNORDERED_MAP (for comparison)
-------------------------
unordered_map<Key, Value> um;       → Average O(1), Worst O(n)
- Keys not sorted (uses hashing)
- Faster but no order guarantee

=====================================================
Summary:
- pair → simple container of two elements.
- map  → balanced tree key-value store (sorted, unique keys).
- unordered_map → hash-based key-value store (unsorted, faster average).
=====================================================
*/
