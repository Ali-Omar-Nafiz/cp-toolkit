/* lower_bound() & upper_bound() — Competitive Programming Toolkit
   - Container must be sorted
   - lower_bound(x): first element >= x
   - upper_bound(x): first element >  x
   - If not found, returns end()
*/

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)

int main() {
    FAST_IO;

    vector<int> v = {10, 30, 20, 50, 60, 40, 80, 70, 90};
    sort(v.begin(), v.end());

    auto lb = lower_bound(v.begin(), v.end(), 28);
    if (lb != v.end()) cout << *lb << '\n';   // 30

    auto ub = upper_bound(v.begin(), v.end(), 30);
    if (ub != v.end()) cout << *ub << '\n';   // 40

    // existence check using lower_bound
    auto it = lower_bound(v.begin(), v.end(), 20);
    cout << ((it != v.end() && *it == 20) ? "Exists...\n" : "Not exists...\n");

    it = lower_bound(v.begin(), v.end(), 33);
    cout << ((it != v.end() && *it == 33) ? "Exists...\n" : "Not exists...\n");

    it = lower_bound(v.begin(), v.end(), 100);
    cout << ((it != v.end() && *it == 100) ? "Exists...\n" : "Not exists...\n");

    return 0;
}

