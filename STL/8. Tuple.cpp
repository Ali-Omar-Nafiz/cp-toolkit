```cpp
/***********************************************************
                TUPLE TOOLKIT (NO emplace_back)
        Quick Revision Sheet for Competitive Programming
***********************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
============================================================
1. WHAT IS TUPLE?
------------------------------------------------------------
tuple = container storing multiple DIFFERENT types
tuple<T1,T2,T3,...>
============================================================
*/


// ---------------------------------------------------------
// 2. CREATION
// ---------------------------------------------------------
void creation() {

    // Explicit type
    tuple<int,string,bool> t1 = {1,"Ali",true};

    // make_tuple
    auto t2 = make_tuple(10,20,'A');

    // C++17 deduction
    tuple t3{5,6.7,false};
}


// ---------------------------------------------------------
// 3. ACCESS ELEMENTS
// ---------------------------------------------------------
void access() {

    auto t = make_tuple(5,'X',3.14);

    cout << get<0>(t) << endl;
    cout << get<1>(t) << endl;
    cout << get<2>(t) << endl;
}


// ---------------------------------------------------------
// 4. MODIFY VALUES
// ---------------------------------------------------------
void modify() {

    auto t = make_tuple(1,2,3);

    get<0>(t) = 100;
}


// ---------------------------------------------------------
// 5. STRUCTURED BINDING ⭐
// ---------------------------------------------------------
void structured_binding() {

    auto t = make_tuple(10,'B',true);

    auto [x,c,flag] = t;

    cout << x << " " << c << " " << flag << endl;
}


// ---------------------------------------------------------
// 6. RETURN MULTIPLE VALUES
// ---------------------------------------------------------
tuple<int,int,int> solve() {
    return {1,2,3};
}

void return_multiple() {

    auto [a,b,c] = solve();
}


// ---------------------------------------------------------
// 7. VECTOR OF TUPLES (using push_back)
// ---------------------------------------------------------
void vector_tuple() {

    vector<tuple<int,int,int>> v;

    v.push_back({3,4,5});
    v.push_back({1,2,3});

    for (auto &[a,b,c] : v)
        cout << a << " " << b << " " << c << endl;
}


// ---------------------------------------------------------
// 8. SORTING TUPLES ⭐
// ---------------------------------------------------------
void sorting() {

    vector<tuple<int,int,int>> v;

    v.push_back({2,5,9});
    v.push_back({1,7,3});
    v.push_back({2,1,8});

    sort(v.begin(), v.end());

    // order:
    // first -> second -> third
}


// ---------------------------------------------------------
// 9. PRIORITY QUEUE WITH TUPLE ⭐⭐
// ---------------------------------------------------------
void pq_example() {

    priority_queue<tuple<int,int,int>> pq;

    pq.push({10,2,3});
    pq.push({5,7,1});
    pq.push({10,1,9});
}


// ---------------------------------------------------------
// 10. TIE (OLD UNPACK)
// ---------------------------------------------------------
void tie_example() {

    int a,b,c;

    tie(a,b,c) = make_tuple(1,2,3);
}


// ---------------------------------------------------------
// 11. IGNORE VALUES
// ---------------------------------------------------------
void ignore_value() {

    auto t = make_tuple(10,20,30);

    auto [x,ignore,z] = t;
}


// ---------------------------------------------------------
// 12. TUPLE SIZE
// ---------------------------------------------------------
void tuple_size_example() {

    auto t = make_tuple(1,2,3,4);

    cout << tuple_size<decltype(t)>::value << endl;
}


/*
============================================================
QUICK MEMORY CHEATSHEET
------------------------------------------------------------
Create        -> make_tuple(...)
Access        -> get<i>(t)
Best Access   -> auto [a,b,c]
Sort          -> automatic
PriorityQueue -> no comparator needed
Return multi  -> tuple
============================================================
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Tuple Toolkit Ready\n";
}
```

