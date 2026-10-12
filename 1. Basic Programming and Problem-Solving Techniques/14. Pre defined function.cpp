#include <bits/stdc++.h>

using namespace std;

/*
=============================================================
Basic Operations and Their Complexities
-------------------------------------------------------------
O(1) Operations:
- swap(a,b)
- max(a,b), min(a,b)
- ceil(x), floor(x)  (math functions)

O(n) Operations:
- reverse array
- find max_element
- find min_element

O(n log n):
- sort array
=============================================================
*/

int main() {
    // ---------------------------
    // O(1) Examples
    // ---------------------------
    int a = 5, b = 10;
    cout << "Before swap: a=" << a << " b=" << b << endl;
    swap(a, b); // O(1)
    cout << "After swap: a=" << a << " b=" << b << endl;

    cout << "Max of a and b = " << max(a, b) << endl; // O(1)
    cout << "Min of a and b = " << min(a, b) << endl; // O(1)

    double x = 4.7;
    cout << "Ceil of " << x << " = " << ceil(x) << endl; // O(1)
    cout << "Floor of " << x << " = " << floor(x) << endl; // O(1)

    // ---------------------------
    // Memory address of array
    // ---------------------------
    int arr[5] = {
        1,
        2,
        3,
        4,
        5
    };
    cout << "Memory address of array arr = " << arr << endl;
    cout << "Memory address of arr[0] = " << & arr[0] << endl;

    // ---------------------------
    // O(n) Examples
    // ---------------------------
    // Reverse array manually
    int n = 5;
    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Reverse
    for (int i = 0; i < n / 2; i++) swap(arr[i], arr[n - i - 1]); // O(n)
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    /*
    =============================================================
    Max and Min Element using Predefined Functions
    - max_element(array_start, array_end) -> returns pointer to max element
    - min_element(array_start, array_end) -> returns pointer to min element
    - Complexity: O(n)
    =============================================================
    */

    int arr[6] = {
        5,
        2,
        9,
        1,
        6,
        3
    };
    int n = 6;

    // Using predefined functions
    int maxVal = * max_element(arr, arr + n); // O(n)
    int minVal = * min_element(arr, arr + n); // O(n)

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Maximum element = " << maxVal << endl;
    cout << "Minimum element = " << minVal << endl;

    // ---------------------------
    // O(n log n) Example
    // ---------------------------
    // Simple sort (using array + loops)
    // Using built-in sort for demonstration
    sort(arr, arr + n); // O(n log n)
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}