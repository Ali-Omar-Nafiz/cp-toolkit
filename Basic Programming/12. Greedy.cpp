✅ Summary:

Brute-force: Explore all possibilities (small N, correctness).

Constructive: Build answer step-by-step following constraints.

Greedy: Make locally optimal choices to reach global optimum (works if problem satisfies greedy-choice property).

#include <bits/stdc++.h>
using namespace std;

/*
Greedy Example: Minimum Coins
Use-case:
- Always pick the largest denomination coin to minimize total coins.
- Works if coin denominations are canonical (e.g., standard currency: 1,2,5,10,...).
- Complexity: O(n) where n = number of coin types
*/

int main() {
    int n;
    cout << "Enter number of coin types: ";
    cin >> n;
    int coins[20];
    cout << "Enter coin denominations in descending order:\n";
    for (int i = 0; i < n; i++) cin >> coins[i];

    int amount;
    cout << "Enter amount to change: ";
    cin >> amount;

    int totalCoins = 0;
    cout << "Coins used: ";
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            totalCoins++;
            cout << coins[i] << " ";
        }
    }

    cout << "\nTotal coins used = " << totalCoins << endl;
    if (amount > 0) cout << "Remaining amount cannot be represented with given coins\n";
    return 0;
}
