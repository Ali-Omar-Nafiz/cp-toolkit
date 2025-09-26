#include <bits/stdc++.h>
using namespace std;

/*
=============================================================
📌 Complexity Feasibility (Contest Constraints)
-------------------------------------------------------------
Complexity      | Max N feasible (~1 sec)
-------------------------------------------------------------
O(1)            | Any N (billions)
O(logN)         | ~10^18 (binary search on 64-bit int)
O(N)            | up to ~10^7
O(N logN)       | ~10^6 (sorting, mergesort)
O(N^2)          | ~10^4
O(N^3)          | ~500
O(2^N)          | N ≤ 20
O(N!)           | N ≤ 10
=============================================================
*/

// ------------------------------
// 1. O(1) - Constant Time
// ------------------------------
int constantOperation(int a, int b) {
    return a + b; // one fixed operation
}

// ------------------------------
// 2. O(logN) - Logarithmic (Binary Search)
// ------------------------------
int binarySearch(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// ------------------------------
// 3. O(N) - Linear (Find Max)
// ------------------------------
int findMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) mx = arr[i];
    }
    return mx;
}

// ------------------------------
// 4. O(NlogN) - Sorting (Merge Sort)
// ------------------------------
void mergeArrays(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[100], R[100]; // temporary arrays (for demo)

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        mergeArrays(arr, l, mid, r);
    }
}

// ------------------------------
// 5. O(N^2) - All Pairs
// ------------------------------
void allPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
    }
    cout << endl;
}

// ------------------------------
// 6. O(N^3) - Triple Loop
// ------------------------------
void tripleLoop(int n) {
    long long cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                cnt++;
    cout << "Total operations (N^3): " << cnt << endl;
}

// ------------------------------
// 7. O(2^N) - Subsets (using bits)
// ------------------------------
void generateSubsets(int n) {
    int total = (1 << n);
    for (int mask = 0; mask < total; mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) cout << i << " ";
        }
        cout << "} ";
    }
    cout << endl;
}

// ------------------------------
// 8. O(N!) - Permutations
// ------------------------------
void generatePermutations(char str[], int l, int r) {
    if (l == r) {
        for (int i = 0; i <= r; i++) cout << str[i];
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            generatePermutations(str, l + 1, r);
            swap(str[l], str[i]); // backtrack
        }
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "O(1) Example: " << constantOperation(5, 10) << endl;

    cout << "O(logN) Example: Binary Search result = "
         << binarySearch(arr, n, 3) << endl;

    cout << "O(N) Example: Max element = " << findMax(arr, n) << endl;

    cout << "O(NlogN) Example: Merge Sort...\n";
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "O(N^2) Example: All pairs:\n";
    allPairs(arr, n);

    cout << "O(N^3) Example:\n";
    tripleLoop(4);

    cout << "O(2^N) Example: Subsets of {0,1,2}\n";
    generateSubsets(3);

    cout << "O(N!) Example: Permutations of {A,B,C}\n";
    char str[] = {'A', 'B', 'C'};
    generatePermutations(str, 0, 2);

    return 0;
}
