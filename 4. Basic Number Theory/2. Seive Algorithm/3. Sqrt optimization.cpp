// Sqrt(n) optimization (Time Comlexity - O(.5 * sqrt(n) * ln(n)))
#include <bits/stdc++.h>
using namespace std;

vector < bool > is_prime(1e5, true);  // Initially for all i, is_prime[i] = true

int main() {
    int n = 100;

    is_prime[1] = false;
    for (int i = 4; i <= n; i += 2) {
        is_prime[i] = false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime[i] == true) {  // This is a real prime number
            for (int j = 3 * i; j <= n; j += (2 * i)) {  // j is a multiple, non-prime
                is_prime[j] = false; // Set j as non-prime
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (is_prime[i] == true) {
            cout << i << " ";
        }
    }
    cout << endl;
}
