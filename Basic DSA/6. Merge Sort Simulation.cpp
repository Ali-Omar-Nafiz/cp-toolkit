#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long

vector<int> v;
long long nodeID = 0;
long long totalCalls = 0;

string indent(int depth) {
    return string(depth * 4, ' ');
}

void printRange(string label, int l, int r, int depth) {
    cout << indent(depth) << label << " [l=" << l << ", r=" << r << "]: ";
    for (int i = l; i <= r; i++) cout << v[i] << " ";
    cout << "\n";
}

void mergeParts(int l, int r, int depth) {
    int mid = (l + r) / 2;

    cout << indent(depth) << "→ Merging l=" << l << " r=" << r << "\n";
    printRange("Left ", l, mid, depth + 1);
    printRange("Right", mid + 1, r, depth + 1);

    vector<int> L, R;
    for (int i = l; i <= mid; i++) L.push_back(v[i]);
    for (int i = mid + 1; i <= r; i++) R.push_back(v[i]);

    int i = 0, j = 0, idx = l;

    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] < R[j]) v[idx++] = L[i++];
        else v[idx++] = R[j++];
    }
    while (i < (int)L.size()) v[idx++] = L[i++];
    while (j < (int)R.size()) v[idx++] = R[j++];

    printRange("Merged", l, r, depth + 1);
}

void divide(int l, int r, int depth) {
    totalCalls++;
    long long myID = nodeID++;

    cout << indent(depth)
         << "[Node " << myID << "] divide(" << l << ", " << r << ")\n";

    if (l == r) {
        cout << indent(depth)
             << "→ Leaf node " << myID << " (single element: " << v[l] << ")\n";
        return;
    }

    int mid = (l + r) / 2;

    // LEFT BRANCH
    cout << indent(depth)
         << "→ Left child of node " << myID << "\n";
    divide(l, mid, depth + 1);

    // RIGHT BRANCH
    cout << indent(depth)
         << "→ Right child of node " << myID << "\n";
    divide(mid + 1, r, depth + 1);

    // MERGE
    cout << indent(depth)
         << "[Node " << myID << "] merging children...\n";
    mergeParts(l, r, depth);

    cout << indent(depth)
         << "[Return Node " << myID << "] range sorted (" << l << " to " << r << ")\n";
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    divide(0, n - 1, 0);

    cout << "\nFinal Sorted Array: ";
    for (auto x : v) cout << x << " ";
    cout << "\n";

    cout << "Total recursive calls = " << totalCalls << "\n";
    cout << "Total nodes created = " << nodeID << "\n";
}

signed main() {
    FAST_IO;
    solve();
    return 0;
}
