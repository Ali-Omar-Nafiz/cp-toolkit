// Minimum length substring that contain abc
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abaabacbaaac";
    int n = s.size();
    map<char,int> cnt;
    deque<char> q;
    int ans = n;
    set<char> st;
    int r = 0;
    // build initial valid window
    for (; r < n; r++) {
        st.insert(s[r]);
        cnt[s[r]]++;
        q.push_back(s[r]);
        if (st.size() == 3) break;
    }
    if (st.size() < 3) {
        cout << "No valid substring\n";
        return 0;
    }
    ans = q.size();
    // sliding window
    for (int l = 0; l < n; l++) {
        char tmp = q.front();
        q.pop_front();
        cnt[tmp]--;
        // expand until we recover missing character
        while (cnt[tmp] == 0 && r + 1 < n) {
            r++;
            q.push_back(s[r]);
            cnt[s[r]]++;
        }
        // check if still valid
        if (cnt['a'] > 0 && cnt['b'] > 0 && cnt['c'] > 0) {
            ans = min(ans, (int)q.size());
        } else break;
    }
    cout << "ans " << ans << '\n';
}





