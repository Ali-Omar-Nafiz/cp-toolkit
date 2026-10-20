// Minimum length substring that contain abc
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abaabacbaaac";
    int n = s.size();
    deque < char > q;
    map < char, int > mp;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
        q.push_back(s[i]);
        while (mp[q.front()] > 1) {
            mp[q.front()]--;
            q.pop_front();
        }
        if (mp['a'] && mp['b'] && mp['c']) {
            ans = min((int)q.size(), ans);
        }
    }
    cout << ans << endl;
    return 0;
}





