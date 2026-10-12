// Count number of divisors of all the numbers from 1 to n
#include <bits/stdc++.h>

using namespace std;

vector < int > divCount(1e5);

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divCount[j]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (divCount[i] == 2) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
// Time Complexity - O(nln(n)) (n / 1 + n / 2 + n / 3 + ..... + n / n = ln(n) --> Harmonic Series)
// ln(n) = logen ~ log2n ~ logn
// O(nln(n)) is almost same but better than O(nlogn)
// 1e7 will pass

