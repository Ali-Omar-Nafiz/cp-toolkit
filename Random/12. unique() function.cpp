/* 
unique() function:
- Returns an iterator to the logical end after removing consecutive duplicate elements.
- It shifts duplicate elements to the end but does NOT actually remove them.
- Since it only removes adjacent duplicates, the container should be sorted first 
  if you want to remove all duplicates.
- To completely erase duplicates from the container, we must use erase() along with unique().
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v = {1, 1, 3, 4, 5, 5, 6, 1, 4, 5};

    // Step 1: Sort the vector so that duplicates become consecutive
    sort(v.begin(), v.end());

    // auto it = unique(v.begin(), v.end());  
    // Returns iterator to the logical end after removing consecutive duplicates

    // v.erase(it, v.end());  
    // Removes the extra elements beyond the logical end

    // Combined version of the above two lines
    v.erase(unique(v.begin(), v.end()), v.end());

    // Print the final vector (duplicates removed)
    for (auto x : v) {
        cout << x << " ";   // Output: 1 3 4 5 6
    }

    cout << endl;
    return 0;
}
