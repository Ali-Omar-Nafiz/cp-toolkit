// Binary Search in STL

#include <bits/stdc++.h>
using namespace std;

int main() {

    // Vector 
    // lower_bound()
    vector < int > v = {1, 2, 3, 4, 6, 6, 6, 8, 9, 10};
    auto it = lower_bound(v.begin(), v.end(), 6);
    int idx = it - v.begin();
    cout << idx << endl;  // Prints 4
    // returns v.end() if the element not exists

    // upper_bound()
    it = upper_bound(v.begin(), v.end(), 6);
    idx = it - v.begin();
    cout << idx << endl;  // Prints 7
    // returns v.end() if the element not exists

    // binary_search()
    bool chk = binary_search(v.begin(), v.end(), 8);  // chk if the eliment exists or not
    cout << chk << endl;   // Prints 1
    chk = binary_search(v.begin(), v.end(), 100);
    cout << chk << endl;  // Prints 0

    // Set
    set < int > s = {1, 2, 3, 4, 6, 6, 6, 8, 9, 10}; // duplicates ignored
    auto it = s.lower_bound(6);
    cout << *it << endl;   // 6

    it = s.upper_bound(6);
    cout << *it << endl;   // 8

    // binary_search equivalent
    cout << (s.find(8) != s.end()) << endl;   // 1
    cout << (s.find(100) != s.end()) << endl; // 0

    // Multiset
    multiset < int > ms = {1, 2, 3, 4, 6, 6, 6, 8, 9, 10};
    auto it = ms.lower_bound(6);
    cout << *it << endl;   // first 6

    it = ms.upper_bound(6);
    cout << *it << endl;   // 8

    cout << (ms.find(6) != ms.end()) << endl; // 1

    // Map
    map < int, string > mp = {
        {1, "A"}, {2, "B"}, {3, "C"}, {6, "X"}, {8, "Y"}
    };
    auto it = mp.lower_bound(6);
    cout << it->first << " " << it->second << endl; // 6 X

    it = mp.upper_bound(6);
    cout << it->first << " " << it->second << endl; // 8 Y

    // search
    cout << (mp.find(3) != mp.end()) << endl; // 1
    return 0;
}

