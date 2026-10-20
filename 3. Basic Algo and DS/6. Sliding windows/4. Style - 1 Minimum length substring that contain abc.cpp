// Minimum length substring that contain abc
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abaabacbaaac";
    int n = s.size();
    map < char, int > mp;
    set < char > st;
    deque < char > dq;
    int r;
    for (r = 0; r < n;) {
        st.insert(str[r]);
        mp[str[r]]++;
        dq.push_back(str[r]);
        r++;
        if (st.size() == 3) {
            break;
        }
    }
    int ans = dq.size();
    for (int l = 0; l < n; l++) {
        char tmp = dq.front();
        mp[tmp]--;
        dq.pop_front();
        if (mp[tmp] == 0) {
            st.erase(tmp);
        }
        while (st.size() < 3 && r < n) {
            mp[str[r]]++;
            dq.push_back(str[r]);
            st.insert(str[r]);
            r++;
        }
        if (st.size() == 3) {
            ans = min(ans, (int)dq.size());
        }
    }
    cout << ans << endl;
}





