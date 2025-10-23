#include <bits/stdc++.h>
using namespace std;

int main() {
    // ---------------------- PAIR ----------------------
    cout << "===== PAIR =====\n";
    // pair: a data type that stores two elements (can be of any type)
    pair<string, int> p;

    // Syntax 1: using initializer list
    p = {"Nafiz", 20};

    // Syntax 2: assigning manually
    // p.first = "Nafiz";
    // p.second = 20;

    cout << "Name: " << p.first << ", Age: " << p.second << "\n\n";

    // Vector of pairs example
    vector<pair<string, int>> v = {
        {"Alice", 23},
        {"Bob", 19},
        {"Charlie", 25},
        {"David", 21},
        {"Alice", 18}
    };

    cout << "Before sorting:\n";
    for (auto &x : v)
        cout << x.first << " " << x.second << "\n";

    // Default sorting (non-decreasing)
    // Sorts by .first first; if .first are equal, then by .second
    sort(v.begin(), v.end());

    cout << "\nAfter sort(v.begin(), v.end()):\n";
    for (auto &x : v)
        cout << x.first << " " << x.second << "\n";

    // Default sorting (non-increasing)
    // Using reverse iterators rbegin() and rend()
    sort(v.rbegin(), v.rend());

    cout << "\nAfter sort(v.rbegin(), v.rend()):\n";
    for (auto &x : v)
        cout << x.first << " " << x.second << "\n";

    // ---------------------- MAP ----------------------
    cout << "\n===== MAP =====\n";
    // map: a key-value pair container
    // Works like an array but can use any type as key
    map<string, string> mp;

    // Two ways to insert values
    mp["Nafiz"] = "Good";  // like mp[index] = value;
    mp.insert({"Alice", "Excellent"});
    mp.insert({"Bob", "Average"});
    mp.insert({"Charlie", "Brilliant"});
    mp.insert({"David", "Nice"});

    // Access value using key (like accessing array index)
    cout << "Nafiz: " << mp["Nafiz"] << "\n";
    cout << "Alice: " << mp["Alice"] << "\n";

    // mp.count(key) -> checks if key exists (returns 1 or 0)
    cout << "\nmp.count(\"Nafiz\") = " << mp.count("Nafiz") << "\n";
    cout << "mp.count(\"Unknown\") = " << mp.count("Unknown") << "\n";

    // Iterating through map (sorted by key automatically)
    cout << "\nAll elements in map (sorted by key):\n";
    for (auto &x : mp)
        cout << x.first << " : " << x.second << "\n";

    // ---------------------- lower_bound & upper_bound ----------------------
    cout << "\n===== lower_bound() and upper_bound() =====\n";
    /*
        lower_bound(key)  -> iterator to first element >= key
        upper_bound(key)  -> iterator to first element > key
    */

    string key = "Bob";
    auto it1 = mp.lower_bound(key);
    auto it2 = mp.upper_bound(key);

    cout << "lower_bound(\"" << key << "\"): ";
    if (it1 != mp.end()) cout << it1->first << " -> " << it1->second << "\n";
    else cout << "No element found (end)\n";

    cout << "upper_bound(\"" << key << "\"): ";
    if (it2 != mp.end()) cout << it2->first << " -> " << it2->second << "\n";
    else cout << "No element found (end)\n";

    // Try with a non-existing key
    key = "Bunny";
    cout << "\nFor key \"" << key << "\":\n";
    it1 = mp.lower_bound(key);
    it2 = mp.upper_bound(key);

    cout << "lower_bound(\"" << key << "\"): ";
    if (it1 != mp.end()) cout << it1->first << " -> " << it1->second << "\n";
    else cout << "No element found (end)\n";

    cout << "upper_bound(\"" << key << "\"): ";
    if (it2 != mp.end()) cout << it2->first << " -> " << it2->second << "\n";
    else cout << "No element found (end)\n";

    // mp.clear() -> removes all elements
    mp.clear();

    cout << "\nAfter mp.clear():\n";
    cout << "mp.size() = " << mp.size() << "\n";

    // Even after clear, accessing mp["anything"] gives a default value of that data type
    cout << "mp[\"Test\"] (default after clear) = '" << mp["Test"] << "'\n";
    // For int map, default would be 0
    map<string, int> score;
    cout << "score[\"Rahim\"] (default int) = " << score["Rahim"] << "\n";

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
