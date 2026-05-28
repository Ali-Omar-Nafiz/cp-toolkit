#include <bits/stdc++.h>
using namespace std;

/*
 -------------------------------------------------------------------
   BASIC FUNCTIONS (ONLY 3 FUNCTIONS YOU REQUESTED)
 -------------------------------------------------------------------
*/

// 1. FACTORIAL FUNCTION
// --------------------------------------------------
// Purpose: Calculate n! (n factorial)
// Used in: permutation(), combination()
// Example: factorial(5) = 120
long long factorial(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

// 2. PERMUTATION FUNCTION
// --------------------------------------------------
// Purpose: Calculate P(n, r) = n! / (n-r)!
// Meaning: Select AND arrange r objects from n.
// ORDER MATTERS.
long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// 3. COMBINATION FUNCTION
// --------------------------------------------------
// Purpose: Calculate C(n, r) = n! / (r!(n-r)!)
// Meaning: Select r objects from n.
// ORDER DOES NOT MATTER.
long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}


/*
 =====================================================================
   THIS PROGRAM IS MADE FOR STUDY — YOU DON'T NEED TO RUN IT.
   JUST READ THE COMMENTS + OUTPUT STATEMENTS TO UNDERSTAND EVERYTHING.
 =====================================================================
*/

int main() {

    cout << "\n==================== PERMUTATION & COMBINATION STUDY CODE ====================\n\n";


    /*
     =================================================================
       1) BASIC PERMUTATION EXAMPLE
       ---------------------------------------------------------------
       Concept:
         - Order matters.
         - Arrangement of people, seats, letters, digits, etc.
         - Formula: P(n, r) = n! / (n-r)!
       
       Example:
         Arrange 3 people out of 5.
         P(5,3) = 5! / (5-3)! = 60
     =================================================================
    */
    cout << "1) Permutation Example (Order matters)\n";
    cout << "   Arrange 3 people out of 5 people.\n";
    cout << "   Formula: P(5,3) = 5! / (5-3)! = " << permutation(5, 3) << "\n\n";


    /*
     =================================================================
       2) BASIC COMBINATION EXAMPLE
       ---------------------------------------------------------------
       Concept:
         - Order does NOT matter.
         - Selection of students, teams, committees, etc.
         - Formula: C(n, r) = n! / (r!(n-r)!)
       
       Example:
         Choose 3 students out of 5.
         C(5,3) = 10
     =================================================================
    */
    cout << "2) Combination Example (Order does NOT matter)\n";
    cout << "   Choose 3 students out of 5.\n";
    cout << "   Formula: C(5,3) = 5! / (3! * 2!) = " << combination(5, 3) << "\n\n";


    /*
     =================================================================
       3) PERMUTATION WITH REPETITION ALLOWED
       ---------------------------------------------------------------
       Concept:
         - Repetition allowed.
         - Used in passwords, PIN codes, number locks.
         - Formula: n^r
       
       Example:
         26 letters → form 3-letter codes.
         Total = 26^3 = 17576
     =================================================================
    */
    cout << "3) Permutation With Repetition\n";
    cout << "   Number of 3-letter codes using 26 letters.\n";
    cout << "   Formula: 26^3 = 17576\n\n";


    /*
     =================================================================
       4) COMBINATION WITH REPETITION ALLOWED
       ---------------------------------------------------------------
       Concept:
         - Unlimited supply of each item.
         - Formula: C(n+r-1, r)
       
       Example:
         Choose 4 fruits from 3 types.
         Total = C(6,4) = 15
     =================================================================
    */
    cout << "4) Combination With Repetition\n";
    cout << "   Choose 4 fruits from 3 types (unlimited supply).\n";
    cout << "   Formula: C(6,4) = " << combination(6, 4) << "\n\n";


    /*
     =================================================================
       5) PERMUTATION WITH IDENTICAL ITEMS — 'BALLOON'
       ---------------------------------------------------------------
       Concept:
         - Some letters repeat.
         - Formula:
             total_letters! / (count1! * count2! * ...)
       
       Example:
         Word: BALLOON (7 letters)
         Counts:
           B = 1
           A = 1
           L = 2
           O = 2
           N = 1
         
         Formula:
           7! / (1!*1!*2!*2!*1!) = 1260
     =================================================================
    */
    cout << "5) Permutation With Identical Letters (BALLOON)\n";
    cout << "   BALLOON → B(1), A(1), L(2), O(2), N(1)\n";
    cout << "   Formula: 7! / (1!*1!*2!*2!*1!) = 1260\n\n";


    /*
     =================================================================
       6) CIRCULAR PERMUTATION
       ---------------------------------------------------------------
       Concept:
         - Circular arrangements remove rotation duplicates.
         - Formula: (n - 1)!
       
       Example:
         Arrange 5 people around a table:
           (5-1)! = 4! = 24
     =================================================================
    */
    cout << "6) Circular Permutation\n";
    cout << "   Arrange 5 people around a round table.\n";
    cout << "   Formula: (5-1)! = 4! = " << factorial(4) << "\n\n";


    /*
     =================================================================
       7) RESTRICTION EXAMPLE
       ---------------------------------------------------------------
       Concept:
         - First digit has special restriction.
         - Other digits free.
       
       Example:
         3-digit number using digits 1–9, starting with an EVEN digit.
         
         Even choices: {2, 4, 6, 8} → 4 ways
         Each remaining digit → 9 choices each
         
         Total = 4 * 9 * 9 = 324
     =================================================================
    */
    cout << "7) Restriction Example\n";
    cout << "   3-digit numbers starting with an even digit.\n";
    cout << "   Total = 4 * 9^2 = 324\n\n";


    cout << "========================= END OF STUDY CODE =========================\n";

    return 0;
}
