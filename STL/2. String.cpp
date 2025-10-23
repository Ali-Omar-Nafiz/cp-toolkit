#include <bits/stdc++.h>
using namespace std;

// ---------------- User-defined string → int (like atoi) ----------------
int stringToInt(string s) {
    int i = 0, ret = 0;
    bool neg = false;
    if (s[0] == '-') {
        neg = true;
        i = 1;
    }
    for (; i < (int)s.size(); i++) {
        ret = ret * 10 + (s[i] - '0');
    }
    return neg ? -ret : ret;
}

void solve() {
    // ---------------- Vector<char> and string ----------------
    vector<char> v;       // dynamic character array
    string str = "hello"; // behaves like vector<char> but with more functions

    // push_back, pop_back, erase
    str.push_back('!');         // hello!
    str.pop_back();             // hello
    str.erase(str.begin() + 1); // hllo (removed 'e')

    // ---------------- String concatenation ----------------
    string a = "Code", b = "Forces";
    string c = a + b; // "CodeForces"

    // ---------------- String comparison ----------------
    string x = "abc", y = "abd";
    bool cmp1 = (x < y);  // true
    bool cmp2 = (x == y); // false
    bool cmp3 = (x >= y); // false

    // ---------------- to_string ----------------
    int n = 123;
    string numStr = to_string(n); // "123"

    // ---------------- atoi ----------------
    string s1 = "13";
    int x1 = 14;
    x1 += atoi(s1.c_str()); // old style
    cout << "Using atoi: " << x1 << "\n"; // 27

    // ---------------- user-defined atoi (stringToInt) ----------------
    int x2 = 14;
    x2 += stringToInt(s1);
    cout << "Using stringToInt: " << x2 << "\n"; // 27

    // ---------------- Multidimensional string ----------------
    vector<string> arr1(8);                  // preferred way
    vector<vector<char>> arr2(8, vector<char>(8)); // 2D char array
    string arr3[8];                          // old-style array

    // ---------------- next_permutation ----------------
    string perm = "ABCD";
    cout << "Permutations of ABCD:\n";
    sort(perm.begin(), perm.end());
    do {
        cout << perm << "\n";
    } while (next_permutation(perm.begin(), perm.end()));
}

int main() {
    solve();
    return 0;
}

/*
====================================================
|              STL STRING TOOLKIT SUMMARY          |
====================================================

BASIC INFORMATION:
----------------------------------------------------
- string is similar to vector<char>, but provides 
  additional built-in operations for text handling.
- Supports dynamic resizing and random access.

ACCESS & CAPACITY:
----------------------------------------------------
s.size() / s.length()       → O(1)
s.empty()                   → O(1)
s[i] or s.at(i)             → O(1)
s.back(), s.front()         → O(1)
s.clear()                   → O(n)
s.resize(n)                 → O(n)
s.reserve(n)                → O(n) (if reallocation)

INSERTION / MODIFICATION:
----------------------------------------------------
s.push_back(ch)             → Amortized O(1)
s.pop_back()                → O(1)
s += "text" or s.append(t)  → O(len(t))
s.insert(pos, str)          → O(n)
s.erase(pos, len)           → O(n)
s.replace(pos, len, str)    → O(n)

COMPARISON & CONCATENATION:
----------------------------------------------------
s1 + s2                     → O(n + m)
s1 == s2, s1 < s2, etc.     → O(min(n, m))
compare(s1, s2)             → O(min(n, m))

SEARCHING:
----------------------------------------------------
s.find(sub)                 → O(n)
s.rfind(sub)                → O(n)
s.substr(pos, len)          → O(len)
s.find_first_of(chars)      → O(n)
s.find_last_of(chars)       → O(n)

CONVERSION:
----------------------------------------------------
stoi(s), stol(s)            → O(len(s))
stoll(s), stod(s)           → O(len(s))
to_string(num)              → O(log(num))
atoi(s.c_str())             → O(len(s))
custom stringToInt()        → O(len(s))

ALGORITHMIC OPERATIONS:
----------------------------------------------------
sort(s.begin(), s.end())          → O(n log n)
reverse(s.begin(), s.end())       → O(n)
next_permutation(s.begin(), s.end()) → O(n)
unique(s.begin(), s.end())        → O(n)
count(s.begin(), s.end(), ch)     → O(n)

ITERATORS:
----------------------------------------------------
s.begin(), s.end()                → O(1)
s.rbegin(), s.rend()              → O(1)

MULTIDIMENSIONAL STRING:
----------------------------------------------------
vector<string> vs(r, string(c, 'x'))  → O(r * c)
vector<vector<char>> vc(r, vector<char>(c)) → O(r * c)

STRING STREAM OPERATIONS:
----------------------------------------------------
stringstream ss; ss << s; ss >> x;  → O(n)

SUMMARY:
----------------------------------------------------
- Access: O(1)
- Add/remove at end: O(1) amortized
- Insert/erase in middle: O(n)
- Search/substr: O(n)
- Compare/concatenate: O(n)
- Sort/permutation: O(n log n)
====================================================
*/
