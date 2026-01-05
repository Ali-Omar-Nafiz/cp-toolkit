/*
    STRING FIND TOOLKIT (Competitive Programming)

    s.find(sub, pos)
    ----------------
    Parameters:
    s   -> main string
    sub -> substring to search
    pos -> starting index (default = 0)

    Return:
    - Index (0-based) where the first occurrence of sub starts
    - string::npos if sub is not found
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Find first occurrence of a substring
    string s = "Ali Omar Nafiz";
    string sub = "Nafiz";

    int idx = s.find(sub);
    if (idx != string::npos) {
        cout << idx << "\n";   // Output: 9
    }

    // Find all occurrences of a substring
    s = "Ali Omar Nafiz Ali";
    sub = "Ali";

    idx = s.find(sub);
    while (idx != string::npos) {
        cout << idx << " ";
        idx = s.find(sub, idx + 1);
    }

    return 0;
}
