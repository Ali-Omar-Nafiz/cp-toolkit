#include <bits/stdc++.h>
using namespace std;

void solve() {
    // substr function in C++
    string str = "Ali Omar Nafiz";

    // substr(pos, len);
    // pos = from which index of the main string, the substring starts
    // len = length of the targeted substring

    string sub = str.substr(0, 3);
    cout << sub << endl;   // prints "Ali"

    // The index of the first character is 0 (not 1).
    // If pos is equal to the string length, the function returns an empty string.
    // If pos is greater than the string length, it throws out_of_range. In this case, the string remains unchanged.
    // If the requested substring length is greater than the remaining size of the string,
    // then the returned substring is [pos, size()).
    string sub3 = str.substr(4, 100);
    cout << sub3 << endl;   // prints "Omar Nafiz"

    // If len is not passed as a parameter, then the returned substring is [pos, size()).
    string sub4 = str.substr(4);
    cout << sub4 << endl;   // prints "Omar Nafiz"


    // getting all subarrays (substrings) of a string
    string s = "abcdef";
    int n = s.length();

    for (int len = 1; len <= n; len++) {
        for (int pos = 0; pos <= (n - len); pos++) {
            string sb = s.substr(pos, len);
            cout << sb << endl;
        }
    }
    /* Prints: 
    a
    b
    c
    d
    e
    f
    ab
    bc
    cd
    de
    ef
    abc
    bcd
    cde
    def
    abcd
    bcde
    cdef
    abcde
    bcdef
    abcdef
    */

    // Alternatively,
    for (int pos = 0; pos < n; pos++) {
        for (int len = 1; len <= (n - pos); len++) {
            string sub = s.substr(pos, len);
            cout << sub << endl;
        }
    }

    /* Prints:
    a
    ab
    abc
    abcd
    abcde
    abcdef
    b
    bc
    bcd
    bcde
    bcdef
    c
    cd
    cde
    cdef
    d
    de
    def
    e
    ef
    f
    */

}

int main() {
    solve();
    return 0;
}