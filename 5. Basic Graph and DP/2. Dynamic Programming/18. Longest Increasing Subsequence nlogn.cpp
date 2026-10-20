#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define int long long

void solve() {
    int n;
    cin >> n;
    
    // 1-based indexing for the input array
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // val stores the smallest ending values of LIS for different lengths
    vector<int> val;
    // idx stores the original indices of the elements inside 'val'
    vector<int> idx;
    // prev[i] stores the index of the element that comes just before v[i] in the LIS
    vector<int> prev(n + 1, -1);

    // Initialize the base case with the first element
    val.push_back(v[1]);
    idx.push_back(1);

    // Build the LIS tracking arrays
    for (int i = 2; i <= n; i++) {
        if (v[i] > val.back()) {
            // v[i] is strictly greater, so it extends the longest sequence
            prev[i] = idx.back(); 
            val.push_back(v[i]);
            idx.push_back(i);
        } else {
            // Binary search to find the first element in 'val' that is >= v[i]
            int ind = lower_bound(val.begin(), val.end(), v[i]) - val.begin();
            
            // Overwrite to keep the ending values as small as possible
            val[ind] = v[i];
            idx[ind] = i;
            
            // If it's not the first element, link it to the element just before it
            if (ind > 0) {
                prev[i] = idx[ind - 1];
            }
        }
    }

    // Reconstruct the sequence by tracing the prev array backwards
    vector<int> lis;
    int curr = idx.back(); // Start from the index of the very last element in the LIS
    
    while (curr != -1) {
        lis.push_back(v[curr]);
        curr = prev[curr];
    }

    // Since we traced backwards, we must reverse the result
    reverse(lis.begin(), lis.end());

    // Print the final LIS
    for (int x : lis) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl;
        solve();
    }
    
    return 0;
}
