/*
=================
RECURSION
=================

Rules to use recursion properly:

1) Define what the function means. What the function gives as output for any input.
   → Example: fact(n) returns n!

2) As a user, Trust the function.
   → During calling a function, don't bother about how it works. Just belive it works.
     (Example: Trust that, fact(n - 1) correctly returns (n - 1)!)

3) Define correct base case.
   → Base case stops infinite recursion.
   → Without base case → Stack Overflow.
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



/*
=====================================
FIBONACCI SERIES
=====================================

Series:
0 1 1 2 3 5 8 13 21 ...

Definition:
fibo(n) = fibo(n - 1) + fibo(n - 2)

Meaning:
nth Fibonacci number is sum of previous two.
*/


int fibo(int n) {

    // Base Case 1
    // We memorize fibo(0)
    if (n == 0) {
        return 0;
    }

    // Base Case 2
    // We memorize fibo(1)
    if (n == 1) {
        return 1;
    }

    // Faith:
    // fibo(n - 1) works correctly
    // fibo(n - 2) works correctly

    int result = fibo(n - 1) + fibo(n - 2);

    return result;
}

/*
As a user:
1. Input
2. Output
3. Complexity or resource usage

As an engineer:
1. Inner procceses
*/
