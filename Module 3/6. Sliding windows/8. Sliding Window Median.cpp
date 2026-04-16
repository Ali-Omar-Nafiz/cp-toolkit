// https://cses.fi/problemset/task/1076/
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long

void balance(multiset < int > &s1, multiset < int > &s2, int h) {
    // size balance
    while (s1.size() > h) {
        s2.insert(*prev(s1.end()));
        s1.erase(prev(s1.end()));
    }
    while (s1.size() < h) {
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
    }
    // order balance
    if (!s1.empty() && !s2.empty() &&
        *prev(s1.end()) > *s2.begin()) {
        int a = *prev(s1.end());
        int b = *s2.begin();
        s1.erase(prev(s1.end()));
        s2.erase(s2.begin());
        s1.insert(b);
        s2.insert(a);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector < int > v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    multiset<int> s1, s2;
    int h;
    h = (k + 1) / 2;
    // first window
    for (int i = 0; i < k; i++) {
        s1.insert(v[i]);
    }
    balance(s1, s2, h);
    vector < int > ans;
    ans.push_back(*prev(s1.end()));
    for (int i = 0; i < n - k; i++) {
        int remove = v[i];
        int add = v[i + k];
        // remove
        if (s1.find(remove) != s1.end()) {
            s1.erase(s1.find(remove));
        }
        else {
            s2.erase(s2.find(remove));
        }
        s1.insert(add);
        balance(s1, s2, h);
        ans.push_back(*prev(s1.end()));
    }
    for (auto x : ans) cout << x << " ";
}
 
signed main() {
    FAST_IO;
    solve();
}
