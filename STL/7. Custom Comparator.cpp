#include <bits/stdc++.h>
using namespace std;

/*-------------------- Custom Comparators --------------------*/

// Comparator for integers (descending)
bool cmpIntDesc(int a, int b) {
    return a > b; // Sort larger first  // if true → a before b  // if false → b before a
}

// Comparator for strings (by length, then lexicographically)
bool cmpString(const string &a, const string &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

// Comparator for pairs (sort by first ascending, then second descending)
bool cmpPair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

/*-------------------- Main Demonstration --------------------*/

int main() {
    /*------------- VECTOR -------------*/
    cout << "=== VECTOR ===\n";

    vector<int> vi = {5, 1, 3, 9, 2};
    sort(vi.begin(), vi.end(), cmpIntDesc);
    cout << "Int Desc: ";
    for (int x : vi) cout << x << " ";
    cout << "\n";

    vector<string> vs = {"apple", "hi", "banana", "dog"};
    sort(vs.begin(), vs.end(), cmpString);
    cout << "String (len+lex): ";
    for (auto &s : vs) cout << s << " ";
    cout << "\n";

    vector<pair<int,int>> vp = {{1,5}, {2,2}, {1,7}, {3,1}};
    sort(vp.begin(), vp.end(), cmpPair);
    cout << "Pair (first asc, second desc): ";
    for (auto &p : vp) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n\n";

    /*------------- SET / MULTISET -------------*/
    cout << "=== SET / MULTISET ===\n";

    // Set with descending int order
    set<int, greater<int>> si = {5, 1, 9, 3};
    cout << "Set Int Desc: ";
    for (int x : si) cout << x << " ";
    cout << "\n";

    // Set with custom string comparator (by length)
    struct StringCmp {
        bool operator()(const string &a, const string &b) const {
            if (a.size() == b.size()) return a < b;
            return a.size() < b.size();
        }
    };
    set<string, StringCmp> ss = {"hi", "apple", "dog", "banana"};
    cout << "Set String (len+lex): ";
    for (auto &s : ss) cout << s << " ";
    cout << "\n";

    // Set with pair comparator
    struct PairCmp {
        bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    set<pair<int,int>, PairCmp> sp = {{1,5},{2,2},{1,7},{3,1}};
    cout << "Set Pair (first asc, second desc): ";
    for (auto &p : sp) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n\n";

    // Multiset example (descending)
    multiset<int, greater<int>> ms = {5, 3, 5, 2};
    cout << "Multiset Int Desc: ";
    for (int x : ms) cout << x << " ";
    cout << "\n\n";

    /*------------- PRIORITY QUEUE -------------*/
    cout << "=== PRIORITY QUEUE ===\n";

    // Priority Queue with custom int comparator (min-heap)
    priority_queue<int, vector<int>, greater<int>> pqInt;
    for (int x : {5, 1, 9, 3}) pqInt.push(x);
    cout << "PQ Int (Min-heap): ";
    while (!pqInt.empty()) {
        cout << pqInt.top() << " ";
        pqInt.pop();
    }
    cout << "\n";

    // Priority Queue with custom string comparator (by length)
    struct PQStringCmp {
        bool operator()(const string &a, const string &b) const {
            if (a.size() == b.size()) return a > b; // reverse lex for equal size
            return a.size() > b.size(); // shorter string = higher priority
        }
    };
    priority_queue<string, vector<string>, PQStringCmp> pqStr;
    for (auto &s : {"apple", "hi", "banana", "dog"}) pqStr.push(s);
    cout << "PQ String (len+revlex): ";
    while (!pqStr.empty()) {
        cout << pqStr.top() << " ";
        pqStr.pop();
    }
    cout << "\n";

    // Priority Queue with pair comparator
    struct PQPairCmp {
        bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
            if (a.first == b.first) return a.second < b.second; // greater second first
            return a.first > b.first; // smaller first first
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, PQPairCmp> pqPair;
    for (auto &p : vp) pqPair.push(p);
    cout << "PQ Pair (first asc, second desc): ";
    while (!pqPair.empty()) {
        auto [f, s] = pqPair.top();
        cout << "(" << f << "," << s << ") ";
        pqPair.pop();
    }
    cout << "\n";

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
