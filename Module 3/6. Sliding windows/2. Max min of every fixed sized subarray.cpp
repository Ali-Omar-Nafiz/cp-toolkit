// min and max of every window

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 10, k = 5;
    vector < int > v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    multiset < int > st;
    // First window
    for (int i = 0; i < k; i++) {
        st.insert(v[i]);
    }
    cout << *st.begin() << " " << *prev(st.end()) << endl;
    // Sliding window
    for (int i = 0; i < n - k; i++) {
        st.erase(v[i]);
        st.insert(v[i + k]);
        cout << *st.begin() << " " << *prev(st.end()) << endl;
    }
    return 0;
}
