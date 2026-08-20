#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack < char > st;
    map< char, char > mp = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (st.empty() || st.top() != mp[s[i]]) {
                cout << "Invalid String\n";
                return 0;
            }
            st.pop();
        }
    }

    if (st.empty())
        cout << "Valid String\n";
    else
        cout << "Invalid String\n";
}
