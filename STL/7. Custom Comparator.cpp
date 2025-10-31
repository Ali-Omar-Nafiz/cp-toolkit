#include <bits/stdc++.h>
using namespace std;

/*-------------------- Custom Comparators --------------------*/

/* Comparator function → bool cmp(T a, T b)
   - if return true  → a comes before b
   - if return false → a comes after b
*/

// Comparator for integers (descending)   // Sort larger first
bool cmp1(int a, int b) {
    return a > b; // true → a before b (descending order)
}

// Comparator for strings (by length, then lexicographically)
bool cmp2(const string &a, const string &b) {
    if (a.size() == b.size()) {
        return a < b;
    } else {
        return a.size() < b.size();
    }
}

// Comparator for pairs (sort by first ascending, then second descending)
bool cmp3(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

/*-------------------- Main Demonstration --------------------*/

int main() {
    /*------------- VECTOR -------------*/

    vector<int> vi = {5, 1, 3, 9, 2};
    sort(vi.begin(), vi.end(), cmp1);
    for (int x : vi) cout << x << " ";   // prints 9 5 3 2 1

    vector<string> vs = {"apple", "hi", "banana", "dog"};
    sort(vs.begin(), vs.end(), cmp2);
    for (auto &s : vs) cout << s << " ";   // prints hi dog apple banana

    vector<pair<int,int>> vp = {{1,5}, {2,2}, {1,7}, {3,1}};
    sort(vp.begin(), vp.end(), cmp3);
    for (auto &p : vp) cout << "(" << p.first << "," << p.second << ") ";
    // prints (1,7) (1,5) (2,2) (3,1)


    /*------------- SET / MULTISET -------------*/

    // Set with descending int order
    set<int, greater<int>> si = {5, 1, 9, 3};
    for (int x : si) cout << x << " ";   // prints 9 5 3 1 

    // Set with custom string comparator (by length)
    struct StringCmp {
        bool operator()(const string &a, const string &b) const {
            if (a.size() == b.size()) return a < b;
            return a.size() < b.size();
        }
    };

    set<string, StringCmp> ss = {"hi", "apple", "dog", "banana"};
    for (auto &s : ss) cout << s << " ";   // prints hi dog apple banana 

    // Set with pair comparator
    struct PairCmp {
        bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    
    set<pair<int,int>, PairCmp> sp = {{1,5},{2,2},{1,7},{3,1}};
    for (auto &p : sp) cout << "(" << p.first << "," << p.second << ") ";
    // prints (1,7) (1,5) (2,2) (3,1)

    // Multiset example (descending)
    multiset<int, greater<int>> ms = {5, 3, 5, 2};
    for (int x : ms) cout << x << " ";   // prints 5 5 3 2 


    /*------------- PRIORITY QUEUE -------------*/

    // Priority Queue with custom int comparator (min-heap)
    priority_queue<int, vector<int>, greater<int>> pqInt;

    for (int x : {5, 1, 9, 3}) pqInt.push(x);
    while (!pqInt.empty()) {
        cout << pqInt.top() << " ";   // pritns 1 3 5 9 
        pqInt.pop();
    }

    // Priority Queue with custom string comparator (by length)
    struct pqCmp1 {
        bool operator()(const string &a, const string &b) const {
            if (a.size() == b.size()) return a > b; // reverse lex for equal size
            return a.size() > b.size(); // shorter string = higher priority
        }
    };

    priority_queue<string, vector<string>, pqCmp1> pqStr;
    for (auto &s : {"apple", "hi", "banana", "dog"}) pqStr.push(s);
    while (!pqStr.empty()) {
        cout << pqStr.top() << " ";   // prints hi dog apple banana 
        pqStr.pop();
    }

    // Priority Queue with pair comparator
    struct pqCmp2 {
        bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
            if (a.first == b.first) return a.second < b.second; // greater second first
            return a.first > b.first; // smaller first first
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, pqCmp2> pqPair;
    for (auto &p : vp) pqPair.push(p);
    while (!pqPair.empty()) {
        auto [f, s] = pqPair.top();
        cout << "(" << f << "," << s << ") ";   // prints (1,7) (1,5) (2,2) (3,1) 
        pqPair.pop();
    }

    return 0;
}

/*------------------------------------------------------------
🧠 QUICK REVISION SUMMARY (Custom Comparator Toolkit)

✅ VECTOR:
   sort(v.begin(), v.end(), cmp);
   - int → cmpIntDesc(a > b)
   - string → cmpString(length ↑, lex ↑)
   - pair → cmpPair(first ↑, second ↓)

✅ SET / MULTISET:
   set<T, Comp> s;
   - int → greater<int> (descending)
   - string → struct StringCmp (length ↑)
   - pair → struct PairCmp (first ↑, second ↓)
   - multiset<int, greater<int>> for duplicates

✅ PRIORITY QUEUE:
   priority_queue<T, vector<T>, Comp> pq;
   - int → greater<int> ⇒ min-heap
   - string → struct PQStringCmp (shorter first)
   - pair → struct PQPairCmp (first ↑, second ↓)

🔥 Tip:
   • Function comparator → use in sort()
   • Struct comparator → use in set/multiset/pq
   • Always define 'operator()' as const in structs
   • For quick inline: use lambda [](auto &a, auto &b){...};


✅ Comparator function → bool cmp(T a, T b)
   - return true  → a comes before b
   - return false → a comes after b

✅ Examples:
   • int ↓  → bool cmpIntDesc(int a, int b) { return a > b; }
   • string → by length ↑, then lex ↑
        bool cmpString(const string &a, const string &b) {
            return (a.size() == b.size()) ? a < b : a.size() < b.size();
        }
   • pair<int,int> → first ↑, second ↓
        bool cmpPair(const pair<int,int> &a, const pair<int,int> &b) {
            return (a.first == b.first) ? a.second > b.second : a.first < b.first;
        }

------------------------------------------------------------*/
