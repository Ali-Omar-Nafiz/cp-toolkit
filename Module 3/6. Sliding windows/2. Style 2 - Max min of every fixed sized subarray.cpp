// min and max of every window

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 10, k = 5;
    vector < int > v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    multiset < int > st;
    int l = 0;
    for (int r = 0; r < n; r++) {
        st.insert(v[r]);
        if (r >= k) {
            st.erase(st.find(v[l]));
            l++;
        }
        if (r >= k - 1) {
            cout << *st.begin() << " " << *prev(st.end()) << endl;
        }
    }
    return 0;
}
