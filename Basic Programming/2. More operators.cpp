#include bitsstdc++.h
using namespace std;

int main() {
     -------------------------------
     Assignment and compound operators
     -------------------------------
    int x = 10;
    cout  x =   x  endl;

    x += 5;  x = x + 5
    cout  After x += 5 -   x  endl;

    x -= 3;  x = x - 3
    cout  After x -= 3 -   x  endl;

    x = 2;  x = x  2
    cout  After x = 2 -   x  endl;

    x = 4;  x = x  4
    cout  After x = 4 -   x  endl;

    x %= 3;  x = x % 3
    cout  After x %= 3 -   x  endl;

     -------------------------------
     Increment  Decrement
     -------------------------------
    int a = 5;
    cout  nInitial a =   a  endl;

    a++;  post increment
    cout  After a++ (post increment) -   a  endl;

    ++a;  pre increment
    cout  After ++a (pre increment) -   a  endl;

    a--;  post decrement
    cout  After a-- (post decrement) -   a  endl;

    --a;  pre decrement
    cout  After --a (pre decrement) -   a  endl;

     Difference between pre and post
    int b = 10;
    cout  nPost increment in expression b++ -   b++   (prints old, then increases)  endl;
    cout  Now b =   b  endl;
    int c = 10;
    cout  Pre increment in expression ++c -   ++c   (increases, then prints)  endl;

     -------------------------------
     Logical operators
     -------------------------------
    bool p = true, q = false;
    cout  nLogical Operators  endl;
    cout  p  q =   (p  q)  endl;  OR
    cout  p && q =   (p && q)  endl;  AND
    cout  !p =   (!p)  endl;          NOT

     -------------------------------
     Bitwise operations
     -------------------------------
    int m = 6, n = 3;
     m = 6 - 110 in binary
     n = 3 - 011 in binary
    cout  nBitwise operations with m=6, n=3  endl;
    cout  m & n =   (m & n)   (AND)  endl;    110 & 011 = 010 (2)
    cout  m  n =   (m  n)   (OR)  endl;     110  011 = 111 (7)
    cout  m ^ n =   (m ^ n)   (XOR)  endl;    110 ^ 011 = 101 (5)
    cout  ~m =   (~m)   (NOT)  endl;          bitwise complement
    cout  m  1 =   (m  1)   (Left shift by 1)  endl;  110 - 1100 (12)
    cout  m  1 =   (m  1)   (Right shift by 1)  endl;  110 - 011 (3)

    return 0;
}
