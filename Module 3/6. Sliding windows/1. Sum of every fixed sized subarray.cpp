// sum of every fixed sized window of an array
// window means subarray
// Sliding window technique works like a sliding window.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 10, k = 5;
    vector < int > v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    // First Window
    for (int i = 0; i < k; i++) {
        sum += v[i];
    }
    cout << sum << endl;
    // Sliding Window
    for (int i = 0; i < n - k; i++) {
        sum -= v[i];
        sum += v[i + k];
        cout << sum << endl;
    }
    return 0;
}
