#include <bits/stdc++.h>
using namespace std;

// ====================================================================
// 🔹 CUSTOM COMPARATOR for priority_queue of pair
// Sort by first element ASCENDING,
// if first elements are equal → sort by second element DESCENDING
// ====================================================================
struct cmp1 {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first)
            return a.second < b.second;  // descending by second
        return a.first > b.first;        // ascending by first
    }
};

// ====================================================================
// 🔹 CUSTOM COMPARATOR FUNCTION for vector<pair<int,int>>
// (same logic as above but used in sort())
// ====================================================================
bool cmp2(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first)
        return a.second > b.second; // descending by second
    return a.first < b.first;       // ascending by first
}

int main() {

    // ================================================================
    // 🔹 BASIC PRIORITY QUEUE (MAX-HEAP by default)
    // ================================================================
    cout << "===== BASIC PRIORITY QUEUE =====\n";

    // Syntax
    priority_queue<int> pq;  // Max-heap by default (largest element at top)

    // Insert elements – O(log n)
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // Access top element – O(1)
    cout << "Top element: " << pq.top() << "\n";

    // Pop top element – O(log n)
    pq.pop();

    // Check if empty – O(1)
    cout << "Is empty? " << (pq.empty() ? "Yes" : "No") << "\n";

    // Accessing all elements – O(n log n)
    cout << "All elements (in descending order): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n\n";

    // ================================================================
    // 🔹 MIN HEAP using greater<int>
    // ================================================================
    cout << "===== MIN HEAP =====\n";

    // Syntax: priority_queue<Type, Container, Comparator>
    priority_queue<int, vector<int>, greater<int>> minpq;

    // Insert elements – O(log n)
    minpq.push(10);
    minpq.push(30);
    minpq.push(20);

    // Access top element (smallest now) – O(1)
    cout << "Top element: " << minpq.top() << "\n";

    // Accessing all elements – O(n log n)
    cout << "All elements (ascending order): ";
    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << "\n\n";

    // ================================================================
    // 🔹 CUSTOM COMPARATOR with PAIR in PRIORITY QUEUE
    // ================================================================
    cout << "===== CUSTOM COMPARATOR on pair (priority_queue) =====\n";

    // Syntax:
    // priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> pq2;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> pq2;

    // Push pairs – O(log n)
    pq2.push({2, 100});
    pq2.push({1, 50});
    pq2.push({2, 200});
    pq2.push({1, 10});

    // Accessing elements according to cmp1 – O(n log n)
    cout << "Pairs ordered (first ASC, if tie -> second DESC):\n";
    while (!pq2.empty()) {
        cout << pq2.top().first << " " << pq2.top().second << "\n";
        pq2.pop();
    }
    cout << "\n";

    // ================================================================
    // 🔹 CUSTOM COMPARATOR on VECTOR of PAIR (using sort)
    // ================================================================
    cout << "===== CUSTOM COMPARATOR on vector<pair<int,int>> =====\n";

    vector<pair<int,int>> vec = {{2,100}, {1,50}, {2,200}, {1,10}};

    // Sort using cmp2 – O(n log n)
    sort(vec.begin(), vec.end(), cmp2);

    cout << "Sorted vector (first ASC, if tie -> second DESC):\n";
    for (auto &p : vec)
        cout << p.first << " " << p.second << "\n";

    return 0;
}
