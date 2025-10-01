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
    str.push_back('!');        // hello!
    str.pop_back();            // hello
    str.erase(str.begin() + 1); // hllo (removed 'e')

    // ---------------- String concatenation ----------------
    string a = "Code", b = "Forces";
    string c = a + b;          // "CodeForces"

    // ---------------- String comparison ----------------
    string x = "abc", y = "abd";
    bool cmp1 = (x < y);   // true
    bool cmp2 = (x == y);  // false
    bool cmp3 = (x >= y);  // false

    // ---------------- to_string ----------------
    int n = 123;
    string numStr = to_string(n); // "123"

    // ---------------- atoi ----------------
    string s1 = "13";
    int x1 = 14;
    x1 += atoi(s1.c_str());  // old style
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
