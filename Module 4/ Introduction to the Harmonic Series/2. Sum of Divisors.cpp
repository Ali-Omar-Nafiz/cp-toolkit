// Sum of divisors of all the numbers from 1 to n
#include <bits/stdc++.h>

using namespace std;

vector < int > sumOfDivisors(1e5);

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            sumOfDivisors[j] += i;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << sumOfDivisors[i] << " ";
    }
    cout << endl;
    return 0;
}
// Time Complexity - O(nln(n)) (n / 1 + n / 2 + n / 3 + ..... + n / n --> Harmonic Series)
// O(nln(n)) is almost same but better than O(nlogn)
