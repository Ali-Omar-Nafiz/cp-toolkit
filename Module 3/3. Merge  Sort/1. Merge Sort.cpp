#include <bits/stdc++.h>
using namespace std;

/*
Merge Sort:
-----------
Defination:
input: l, r --> range to sort, v --> vector to sort
output: nothing
processing: sort numbers form l to r in vector v.
Base Case: if the size is 1 it already sorted. So, return.
*/

void mergeSort(int l, int r, vector < int > &v) {
    if ((r - l + 1) <= 1) {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(l, mid, v);
    mergeSort(mid + 1, r, v);
    vector < int > nV(r - l + 1);
    int h1 = l, h2 = mid + 1;
    for (int i = 0; i < nV.size(); i++) {
        if (h1 > mid) {
            nV[i] = v[h2];
            h2++;
        } else if (h2 > r) {
            nV[i] = v[h1];
            h1++;
        } else {
            if (v[h1] <= v[h2]) {
                nV[i] = v[h1];
                h1++;
            } else {
                nV[i] = v[h2];
                h2++;
            }
        }
    }
    for (int i = 0; i < nV.size(); i++) {
        v[l + i] = nV[i];
    }
}

int main() {
    int n;
    cin >> n;
    vector < int > v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
    mergeSort(0, n - 1, v);
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

// Time Complexity: n * logn
