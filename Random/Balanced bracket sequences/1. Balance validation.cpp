#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int depth = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            depth++;
        } else {
            depth--;
        }

        if (depth < 0) {
            cout << "Invalid String" << endl;
            return 0;
        }
    }

    if (depth != 0) {
        cout << "Invalid String" << endl;
    } else {
        cout << "Valid String" << endl;
    }

    return 0;
}
