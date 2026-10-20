#include <bits/stdc++.h>
using namespace std;

/*
=================
RECURSION
=================
Rules to use recursion properly:
1) Define the function. Get clear understanding about input and output.
2) As a user, Trust the function.
   → During calling a function, don't bother about how it works. Just belive it works.
     (Example: Trust that, fact(n - 1) correctly returns (n - 1)!)
3) Define correct base case.
   → Base case stops infinite recursion.
   → Without base case → Stack Overflow.
Restriction:
1. Directly / inderectly calling it's own function. (Calling with same input)
2. Base case have to be exists
*/

/*
=====================================
FACTORIAL (n!)
=====================================
Definition:
n! = n × (n - 1)!
0! = 1
Example:
5! = 5 × 4!
4! = 4 × 3!
3! = 3 × 2!
2! = 2 × 1!
1! = 1 × 0!
0! = 1  ← Base Case
*/

// Method 1: Standard recursive definition
int fact1(int n) {
    // Base Case
    if (n == 0) {
        return 1;
    }
    // Faith: fact1(n - 1) correctly returns (n - 1)!
    int smaller = fact1(n - 1);
    // Self work
    int result = n * smaller;
    return result;
}

/*
Alternative Thinking:
n! = (n + 1)! / (n + 1)
Example:
4! = 5! / 5
3! = 4! / 4
*/
int fact2(int n) {
    // Base Case (we must stop somewhere)
    // 9! = 362880
    if (n == 9) {
        return 362880;
    }
    // Faith: fact2(n + 1) returns (n + 1)!
    int bigger = fact2(n + 1);
    // Self work
    int result = bigger / (n + 1);
    return result;
}

int main() {
    cout << fact1(10) << endl;  // prints 3628800
    cout << fact2(5) << endl;   // prints 120
    return 0;
}
