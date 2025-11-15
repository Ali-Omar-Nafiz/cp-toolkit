Simulation:
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long

vector<int> v;
long long totalIteration = 0;
long long nodeID = 0;

string indent(int depth) {
    return string(depth * 4, ' '); // 4 spaces per level
}

int go(int index, int left, int right, int depth) {
    totalIteration++;
    long long myID = nodeID++;  // Assign unique node number

    // Print current node state
    cout << indent(depth);
    cout << "[Node " << myID << "] index=" << index 
         << " | left=" << left 
         << " | right=" << right << "\n";

    // Base case
    if (index == v.size()) {
        cout << indent(depth);
        cout << "→ Leaf Node " << myID 
             << ": diff=" << abs(left - right) << "\n";
        return abs(left - right);
    }

    // LEFT branch
    cout << indent(depth) 
         << "→ Take LEFT (from node " << myID << ")\n";
    int leftReturn = go(index + 1, left + v[index], right, depth + 1);

    // RIGHT branch
    cout << indent(depth) 
         << "→ Take RIGHT (from node " << myID << ")\n";
    int rightReturn = go(index + 1, left, right + v[index], depth + 1);

    // Returning from this node
    cout << indent(depth);
    cout << "[Return Node " << myID 
         << "] best=" << min(leftReturn, rightReturn) << "\n";

    return min(leftReturn, rightReturn);
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = go(0, 0, 0, 0);

    cout << "\nFinal minimal difference = " << ans << "\n";
    cout << "Total recursive calls = " << totalIteration << "\n";
    cout << "Total nodes created = " << nodeID << "\n";
}

signed main() {
    FAST_IO;
    solve();
    return 0;
}

Problem link: https://cses.fi/problemset/task/1623