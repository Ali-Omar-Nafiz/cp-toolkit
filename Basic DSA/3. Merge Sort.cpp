#include <bits/stdc++.h>
using namespace std;

/*

 Merge Sort using Divide and Conquer Approach
----------------------------------------------
   Time Complexity: O(n log n)
   Space Complexity: O(n)
   Stable: Yes
*/

// Function to merge two sorted halves of the array
void merge(int l, int r, vector<int> &arr) {
    int mid = (l + r) / 2;

    // Create temporary vectors for left and right halves
    vector<int> left, right;
    for (int i = l; i <= mid; i++) left.push_back(arr[i]);
    for (int i = mid + 1; i <= r; i++) right.push_back(arr[i]);

    int currIndex = l; // index to place sorted elements back in arr
    int L = 0, R = 0;  // pointers for left and right vectors

    // Merge both halves in sorted order
    while (L < left.size() && R < right.size()) {
        if (left[L] < right[R]) {
            arr[currIndex++] = left[L++];
        } else {
            arr[currIndex++] = right[R++];
        }
    }

    // Copy any remaining elements from left half
    while (L < left.size()) {
        arr[currIndex++] = left[L++];
    }

    // Copy any remaining elements from right half
    while (R < right.size()) {
        arr[currIndex++] = right[R++];
    }
}

// Recursive function to divide the array
void divide(int l, int r, vector<int> &arr) {
    // Base case: single element is already sorted
    if (l == r) return;

    int mid = (l + r) / 2;

    // Recursively divide left and right halves
    divide(l, mid, arr);
    divide(mid + 1, r, arr);

    // Merge the sorted halves
    merge(l, r, arr);
}

// Main function (for testing)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Call divide function to sort the array
    divide(0, n - 1, arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
