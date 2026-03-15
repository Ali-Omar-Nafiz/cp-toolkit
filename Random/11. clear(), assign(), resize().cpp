#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v;

    // -----------------------------
    // assign(n, value)
    // -----------------------------

    v.assign(5, 10);

    // vector becomes:
    // [10, 10, 10, 10, 10]
    // size = 5

    // assign() COMPLETELY replaces the vector


    // -----------------------------
    // resize(n)
    // -----------------------------

    v.resize(8);

    // before:
    // [10,10,10,10,10]

    // after:
    // [10,10,10,10,10,0,0,0]
    // new elements initialized with 0
    // size = 8


    // -----------------------------
    // resize(n, value)
    // -----------------------------

    v.resize(10, 7);

    // before:
    // [10,10,10,10,10,0,0,0]

    // after:
    // [10,10,10,10,10,0,0,0,7,7]
    // new elements initialized with 7
    // size = 10


    // -----------------------------
    // resize smaller
    // -----------------------------

    v.resize(4);

    // before:
    // [10,10,10,10,10,0,0,0,7,7]

    // after:
    // [10,10,10,10]
    // extra elements removed
    // size = 4


    // -----------------------------
    // clear()
    // -----------------------------

    v.clear();

    // before:
    // [10,10,10,10]

    // after:
    // []
    // size = 0
    // capacity may remain


    return 0;
}
